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

_Noreturn void *occupationHandler() {
    struct can_filter filter[20];
//    filter[0].can_id = 0x37B;
//    filter[0].can_mask = CAN_SFF_MASK;

    // il y a 20 cantons a surveiller;
    canton_t canton[20];
    parseCantonWatcher("./config/cantons_watcher.conf", canton);
    fillFilter(filter, canton);


    log_debug("sizeof = %d", sizeof(filter));
    int port = canLinux_Init("can0");
    canLinux_InitFilter(port, filter, sizeof(filter));
    for (;;) {
        //TODO filtrer les trames avec l'id du canton

        uCAN1_MSG trame_rcv;
        if (ECAN1_receive(port, &trame_rcv)) {
//            for (int i = 0; i < 20; ++i) {
//                if (trame_rcv.frame.id == (0x39A)) {
            log_debug("trame id : %#X dlc : %d", trame_rcv.frame.id, trame_rcv.frame.dlc);
            log_debug("\tdata[0] = %d\n\tdata[1] = %d\n\tdata[2] = %d", trame_rcv.frame.data0, trame_rcv.frame.data1, trame_rcv.frame.data2);
//                }
//            }

        }
        usleep(20 * MS);
    }
}

_Noreturn void *aiguillageHandler() {
    int portCan = canLinux_Init("can0");

    for (;;) {
        Aiguillage_Message_t *message_to_send = defiler_message();
        if (message_to_send == NULL) {
            usleep(150 * MS);
            continue;
        }
        log_trace("Trouvé un message à envoyer");
        //TODO : filtrer les trames avec l'id de l'aiguillage.

        afficher_message(*message_to_send);
        uCAN1_MSG consigneAiguillage;
        consigneAiguillage.frame.id = message_to_send->id;
        consigneAiguillage.frame.dlc = 3;
        consigneAiguillage.frame.data0 = message_to_send->aigAction;
        consigneAiguillage.frame.data1 = message_to_send->position;
        consigneAiguillage.frame.data2 = 'A';
        bool res = ECAN1_transmit(portCan, CANLINUX_PRIORITY_HIGH, &consigneAiguillage);
        if (res == true) {
            printf("Trame Transmise !!\n");
            message_to_send->sent = 1;
        } else {
            printf("Erreur de transmission de la trame !! \n");
        }
        usleep(10 * MS);
        uCAN1_MSG cro;
        ECAN1_receive(portCan, &cro);
        printf("Message recu !!\n");
        printf("ID de la trame : %d\n", cro.frame.id);
        printf("DATA[0] = %#02x\n", cro.frame.data0);
        printf("DATA[1] = %#02x\n", cro.frame.data1);
        printf("DATA[2] = %#02x\n", cro.frame.data2);
        printf("\n");

        usleep(10 * MS);
    }

}

_Noreturn void *connexionHandler(void *sock_param) {
    log_debug("Nouveau train connecté");
    int sock = *(int *) sock_param;
    char header[2];
    int nread;
    char id_train;
    char size;
    for (;;) {
        // Lire le début de trame
        nread = read(sock, header, 2);
        if (nread <= 0) {
            pthread_exit(0);
        }
        id_train = header[0];
        size = header[1];
        log_debug("Taille de la trame : %d", size);
        char buffer[size];
        read(sock, buffer, size);
        log_debug("Trame recue :%s", buffer);
    }
}


int main() {
    pthread_mutex_init(&globalInfo.Lock, NULL);
    initMessageQueue();
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
    pthread_create(&threadOccupation, NULL, occupationHandler, NULL);
    pthread_detach(threadOccupation);

    printf("Ajout des messages dans la file !!\n");

    for (int i = 16; i < 32; ++i) {
        positionnerAiguillage((i << 4) + 2, DROIT);
        usleep(300*MS);
    }

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