#ifndef UNIRAIL_AIGUILLAGE_QUEUE_H
#define UNIRAIL_AIGUILLAGE_QUEUE_H

#include <pthread.h>


#define MAX_ORDER_AIGUILLAGE 10

typedef enum {
    MVT = 0x57, // W
    LOCK = 0x4C, // L
    UNLOCK = 0x55, // U
    INIT = 0x49, // I
} AIG_ACTION;

typedef enum {
    DROIT,
    BIAIS
} AIG_POSTION;

typedef struct {
    AIG_ACTION aigAction;
    int id;
    char position;
    char sent;
} Aiguillage_Message_t;

typedef struct mq {
    Aiguillage_Message_t *messages[MAX_ORDER_AIGUILLAGE];
    int nb_elems, fo, li; // fo = first_out | li = last in
    pthread_mutex_t Lock;
} Aiguillage_Queue_t;

Aiguillage_Queue_t file_Messages;

void initMessageQueue();

int enfiler_message(Aiguillage_Message_t *message);

Aiguillage_Message_t *defiler_message();

void afficher_message(Aiguillage_Message_t message);


#endif //UNIRAIL_AIGUILLAGE_QUEUE_H
