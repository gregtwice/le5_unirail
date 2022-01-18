//
// Created by gregoire on 05/12/2021.
//

#ifndef UNIRAIL_CONFIG_PARSER_H
#define UNIRAIL_CONFIG_PARSER_H

#include "../../Libs_Unirail/CAN/canLinux.h"
#include "aiguillage_queue.h"
#include "canton_ressources.h"


typedef struct canton {
    int id;
    char nom[4];
    struct canton *suivant;
    int vmax;
    int distance;
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
    ressource_maquette_t ressourcesMaquette[6];
} rbc_global_info;

rbc_global_info globalInfo;


int parsetrainconfig(const char *filename, trainConfig_t *config);

void fillFilter(struct can_filter *filter, canton_t cantons[20]);

int parseCantonWatcher(const char *filename, canton_t cantons[20]);

int positionnerAiguillage(int idAiguillage, char position);

void trameToString(uCAN1_MSG msg, char *buf);

void makeTramePosition(uCAN1_MSG *msg, AIG_ACTION action, Aiguillage_Message_t message);

void init_maquette();

void print_trame(const char *buff);

int conv_ascii_hex_to_int(const char *hex);

int essai_prendre_ressource(int id_canton_du_train, int id_train);

void essai_rendre_ressources(int id_canton_du_train);

int traiterRequete(const char *buffer, int sock);

#endif //UNIRAIL_CONFIG_PARSER_H
