#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>

#include "../Libs_Unirail/CAN/Identificateur.h"
#include "libs/aiguillage_queue.h"
#include "../Libs_Unirail/CAN/canLinux.h"
#include "libs/rbc_utils.h"
#include "libs/log.h"

#define US 1
#define MS 1000
#define S  1000000

_Noreturn void *aiguillageHandler() {
    struct can_filter aig_filter[18];
    for (int i = 0; i < 18; i++) {
        aig_filter[i].can_id = 16 + i;
        aig_filter[i].can_mask = 0xF000;
    }
    int portCan = canLinux_Init("can0");
//    canLinux_InitFilter(portCan, aig_filter, 18);
    for (;;) {
        Aiguillage_Message_t *message_to_send = defiler_message();
        if (message_to_send == NULL) {
            usleep(10 * MS);
            continue;
        }
        log_trace("Trouvé un message à envoyer");
        //TODO : filtrer les trames avec l'id de l'aiguillage.

        afficher_message(*message_to_send);
        uCAN1_MSG consigneAiguillage;
        makeTramePosition(&consigneAiguillage, UNLOCK, *message_to_send);
        bool res = ECAN1_transmit(portCan, CANLINUX_PRIORITY_HIGH, &consigneAiguillage);
        if (res == true) {
            printf("Trame Transmise !!\n");
        } else {
            printf("Erreur de transmission de la trame !! \n");
        }
        usleep(10 * MS);
        uCAN1_MSG cro;
        ECAN1_receive(portCan, &cro);
        makeTramePosition(&consigneAiguillage, MVT, *message_to_send);
        res = ECAN1_transmit(portCan, CANLINUX_PRIORITY_HIGH, &consigneAiguillage);
        if (res == true) {
            printf("Trame Transmise !!\n");
        } else {
            printf("Erreur de transmission de la trame !! \n");
        }
        ECAN1_receive(portCan, &cro);
        usleep(10 * MS);
    }
}

_Noreturn void *connexionHandler(void *sock_param) {
    log_debug("Nouveau train connecté");
    int sock = *(int *) sock_param;
    char buffer[100];
    size_t nread;
    char id_train;
    for (;;) {
        // Lire le début de trame
        nread = read(sock, buffer, 100);
        if (nread == 0) {
            log_fatal("Connexion perdue avec le client");
            pthread_exit(0);
        }
        id_train = buffer[0];
        log_debug("id du train : %d", id_train);
        log_debug("Trame recue :%s", buffer);
        int nbC = traiterRequete(buffer, sock);
        log_debug("nbC = %d",nbC);
    }
}


int main() {
    pthread_mutex_init(&globalInfo.Lock, NULL);
    initMessageQueue();
    init_ressources(1);
    init_ressources(2);
    init_ressources(3);
    init_ressources(4);
    init_ressources(5);
//    pthread_mutex_lock(&cantons[1].res);
//    pthread_mutex_lock(&cantons[2].res);
//    pthread_mutex_lock(&cantons[3].res);
//    pthread_mutex_lock(&cantons[4].res);
//    pthread_mutex_lock(&cantons[5].res);
    log_debug("File des aiguillages initialisée");
    parsetrainconfig("./config/train1.conf", &globalInfo.config.config_trains[0]);
    parsetrainconfig("./config/train2.conf", &globalInfo.config.config_trains[1]);
    parsetrainconfig("./config/train3.conf", &globalInfo.config.config_trains[2]);

    // création de la socket
    log_debug("Lancement du serveur");
    int sd, se;
    struct sockaddr_in svc, clt;
    socklen_t cltLen;
    // Création de la socket de réception d’écoute des appels
    se = socket(PF_INET, SOCK_STREAM, 0);
    int reuse = 1;
    if (setsockopt(se, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");

    if (se == -1) {
        printf("Error creating socket");
        return 0;
    }
    svc.sin_family = PF_INET;
    svc.sin_port = htons(8080);
    svc.sin_addr.s_addr = INADDR_ANY;
    memset(&svc.sin_zero, 0, 8);
    if (bind(se, (struct sockaddr *) &svc, sizeof(svc)) != 0) {
        printf("Can't bind\n");
        exit(0);
    }
    printf("valeur de la socket : %d\n", se);

    pthread_t threadAPI, threadAiguillage, threadOccupation;
    printf("Création du thread de gestion de l'aiguillage\n");
    pthread_create(&threadAiguillage, NULL, aiguillageHandler, NULL);
    pthread_detach(threadAiguillage);
//    pthread_create(&threadOccupation, NULL, occupationHandler, NULL);
//    pthread_detach(threadOccupation);
    printf("Ajout des messages dans la file !!\n");
    init_maquette();
    listen(se, 4);
    printf("Lancement de la boucle de service\n");
    while (1) {
        cltLen = sizeof(clt);
        sd = accept(se, (struct sockaddr *) &clt, &cltLen);
        if (sd == -1) {
            printf("Can't accept!\n");
            break;
        }
        int err = pthread_create(&threadAPI, NULL, connexionHandler, (void *) &sd);
        pthread_detach(threadAPI);
        if (err != 0) {
            perror("could not create thread");
            return 1;
        }
        puts("Nouveau Train Connecté !!!\n");
        sleep(1);
    }
    close(se);
}