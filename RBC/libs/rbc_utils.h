//
// Created by gregoire on 05/12/2021.
//

#ifndef UNIRAIL_CONFIG_PARSER_H
#define UNIRAIL_CONFIG_PARSER_H

#include "../../Libs_Unirail/CAN/canLinux.h"

typedef struct canton {
    int id;
    char nom[4];
    struct canton *suivant;
    int vmax;
} canton_t;

typedef struct {
    int id;
    int nb_cantons;
    canton_t cantons[14];
    int distance_totale;
    char ip_addr[16];
} trainConfig_t;

typedef struct {
    trainConfig_t config_trains[3];
    canton_t cantons_to_watch[20];
} rbc_config_t;

typedef struct {
    int id;
    char occupe;
    char id_train;
} occupation_canton_t;

typedef struct {
    rbc_config_t config;
    occupation_canton_t occupationCanton[20];
    pthread_mutex_t Lock;
} rbc_global_info;

rbc_global_info globalInfo;

int parsetrainconfig(const char *filename, trainConfig_t *config);

void fillFilter(struct can_filter *filter, canton_t cantons[20]);

int parseCantonWatcher(const char *filename, canton_t cantons[20]);

int traiterRequete(char train_id, const char *buffer, char taille);

int positionnerAiguillage(int idAiguillage, char position);
#endif //UNIRAIL_CONFIG_PARSER_H
