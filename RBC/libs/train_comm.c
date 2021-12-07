//
// Created by gregoire on 07/12/2021.
//
#include "rbc_utils.h"

void updateOccupation(char id_train, int id_canton);

int traiterRequete(char id_train, const char *buffer, char taille) {
    char type[3] = {buffer[0], buffer[1], buffer[2]};

    if (strcmp(type, "BAL") == 0) {
        int id_canton;
        sscanf(buffer, "BAL:%d", &id_canton);
        updateOccupation(id_train, id_canton);
    } else if (strcmp(type, "MVT") == 0) {

    }
}

void updateOccupation(char id_train, int id_canton) {
    pthread_mutex_lock(&globalInfo.Lock);
    for (int i = 0; i < 20; ++i) {
        if (globalInfo.occupationCanton[i].id_train == id_train) {
            globalInfo.occupationCanton[i].occupe = 0;
            globalInfo.occupationCanton[i].id_train = 0;
        }
    }
    for (int i = 0; i < 20; ++i) {
        if (globalInfo.occupationCanton[i].id == id_canton) {
            globalInfo.occupationCanton[i].occupe = 1;
            globalInfo.occupationCanton[i].id_train = id_train;
        }
    }
    pthread_mutex_unlock(&globalInfo.Lock);
}
