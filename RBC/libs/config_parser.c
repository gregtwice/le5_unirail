//
// Created by gregoire on 05/12/2021.
//
#include <stdlib.h>

#include "rbc_utils.h"
#include "log.h"

static const int MAX_CAR = 1024;

int parsetrainconfig(const char *filename, trainConfig_t *config) {
    log_info("Lecture du fichier de config");
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        log_fatal("Lecture du fichier de configuration impossible !");
        exit(0);
    }
    log_info("Fichier ouvert !");


    char buffer[MAX_CAR];
    int nb_cantons = 0;
    while (!feof(fp)) {
        fgets(buffer, MAX_CAR, fp);
        if (sscanf(buffer, "Id:\t%d", &config->id)) {
            log_debug("Dans le fichier : %s id du train trouvé : %d", filename, config->id);
            continue;
        } else if (buffer[0] == '\t') {
            if (sscanf(buffer, "\t%s :\t%d\t:\t%d\t:\t%d", config->cantons[nb_cantons].nom, &config->cantons[nb_cantons].id,&config->cantons[nb_cantons].distance,&config->cantons[nb_cantons].vmax)) {
                log_debug("Canton %s : Adresse : %d", config->cantons[nb_cantons].nom, config->cantons[nb_cantons].id);
                nb_cantons++;
            }
        } else if (sscanf(buffer, "Distance: %d", &config->distance_totale)) {
            log_debug("Distance : %d", config->distance_totale);
        } else if (sscanf(buffer, "Ip: %s", config->ip_addr)) {
            log_debug("%s", config->ip_addr);
        }
    }
    for (int i = 0; i < nb_cantons; ++i) {
        if (i + 1 < nb_cantons)
            config->cantons[i].suivant = &config->cantons[i + 1];
    }
    config->cantons[nb_cantons - 1].suivant = &config->cantons[0];
    config->nb_cantons = nb_cantons;
    return 0;
}

int parseCantonWatcher(const char *filename, canton_t cantons[20]) {
    log_info("Ouverture du fichier de surveillance des cantons : %s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        log_fatal("Impossible d'ouvrir le fichier %s", filename);
        exit(0);
    }

    char buffer[MAX_CAR];
    int nb_cantons = 0;
    while (!feof(fp)) {
        fgets(buffer, MAX_CAR, fp);
        if (strlen(buffer) == 0 || buffer[0] != 'C') {
            continue;
        }
        sscanf(buffer, "%s\t:\t%d\t:\t%d", cantons[nb_cantons].nom, &cantons[nb_cantons].id, &cantons[nb_cantons].vmax);
        globalInfo.occupationCanton[nb_cantons].id = cantons[nb_cantons].id;
        nb_cantons++;
    }

    return 0;
}