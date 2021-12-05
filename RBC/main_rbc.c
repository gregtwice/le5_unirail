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
#include "aiguillage_queue.h"
#include "../Libs_Unirail/CAN/canLinux.h"

#define US 1
#define MS 1000
#define S  1000000


typedef struct RBC_Info_s {
    int canPort;
} RBC_Info;
RBC_Info Rbc_Global_Info;

_Noreturn void *aiguillageHandler() {
    for (;;) {

        printf("\tNouveau message a défiler\n");
        printf("Nb Elems dans la file : %d\n",file_Messages.nb_elems);
        Aiguillage_Message_t *message_to_send = defiler_message();
        if (message_to_send == NULL) {
            printf("C'est vide !!!\n");
            usleep(150 * MS);
            continue;
        }
        printf("\tMessage défilé avec succès\n");
        int portCan = canLinux_Init("can0");
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
        usleep(150 * MS);
        uCAN1_MSG cro;
        ECAN1_receive(portCan, &cro);
        printf("Message recu !!\n");
        printf("ID de la trame : %d\n", cro.frame.id);
        printf("DATA[0] = %#02x\n", cro.frame.data0);
        printf("DATA[1] = %#02x\n", cro.frame.data1);
        printf("DATA[2] = %#02x\n", cro.frame.data2);
        printf("\n");

        usleep(150 * MS);
    }

}


void *connexionHandler(void *sock_param) {
    puts("Nouveau train connecté");

    return NULL;
}


int main() {
    printf("Programme de gestion du RBC\n");
    initMessageQueue();
    // création de la socket
    puts("Lancement de la socket");
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

    printf("Lancement du bus CAN\n");
    char *NomPort = "can0";
    // Definition d'une variable pour memoriser le descripteur de port CAN ouvert
    int canPort;
    //Definition d'un filtre CAN pour preciser les identifiant a lire
    struct can_filter rfilter[1]; //Le filtre sera limite ici a une variable
    uCAN1_MSG msg;
    canPort = canLinux_Init(NomPort);

    // Mise en place d'un filtre
    canLinux_InitFilter(canPort, rfilter, sizeof(rfilter));
    printf("Bus can Lancé !! \n");

    pthread_t threadAPI, treadAiguillage;
    printf("Création du thread de gestion de l'aiguillage\n");
    pthread_create(&treadAiguillage, NULL, aiguillageHandler, NULL);
    pthread_detach(treadAiguillage);
    printf("Ajout des messages dans la file !!\n");
    Aiguillage_Message_t message1 = {
            .aigAction = UNLOCK,
            .id = ID_AIG_1,
            .position = 0,
            .sent = 0
    };
    enfiler_message(&message1);
    Aiguillage_Message_t message2 = {
            .aigAction = MVT,
            .id = ID_AIG_1,
            .position = 0x01,
            .sent = 0
    };
    enfiler_message(&message2);
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