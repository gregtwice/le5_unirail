//
// Created by gregoire on 10/01/2022.
//

#ifndef UNIRAIL_CANTON_RESSOURCES_H
#define UNIRAIL_CANTON_RESSOURCES_H

#include <pthread.h>

typedef struct {
    int ressource_id;
    pthread_mutex_t mutex_ressource;
    int current_train;
    int cantons_prise[10];
    int cantons_cession[10];
} ressource_maquette_t;

void init_ressources(int);


#endif //UNIRAIL_CANTON_RESSOURCES_H
