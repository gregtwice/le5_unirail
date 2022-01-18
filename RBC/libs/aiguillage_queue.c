//
// Created by gregoire on 30/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "aiguillage_queue.h"

Aiguillage_Message_t *defiler_message() {

    if (file_Messages.nb_elems == 0) {
        return NULL; // On défile du vide
    }
    Aiguillage_Message_t *toReturn = file_Messages.messages[file_Messages.fo];
    file_Messages.messages[file_Messages.fo] = NULL;
    file_Messages.fo = (file_Messages.fo + 1) % MAX_ORDER_AIGUILLAGE;
    file_Messages.nb_elems--;

    return toReturn;
}

int enfiler_message(Aiguillage_Message_t *message) {

    if (file_Messages.nb_elems > MAX_ORDER_AIGUILLAGE - 1) {
        return 1; // LA FILE EST PLEINE;
    }
    file_Messages.li = (file_Messages.li + 1) % MAX_ORDER_AIGUILLAGE;
    file_Messages.messages[file_Messages.li] = message;
    file_Messages.nb_elems++;

    return 0;
}

void initMessageQueue() {
    pthread_mutex_init(&file_Messages.Lock, NULL);
    file_Messages.fo = 0;
    file_Messages.li = -1;
    file_Messages.nb_elems = 0;
}


void afficher_message(Aiguillage_Message_t message) {
    printf("Message.id : %#02x\nMessage.Action : %#02x\nMessage.position : %#02x", message.id, message.position, message.position);
}



