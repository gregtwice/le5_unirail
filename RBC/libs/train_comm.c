//
// Created by gregoire on 07/12/2021.
//
#include "rbc_utils.h"
#include "log.h"
#include "../../Libs_Unirail/CAN/Identificateur.h"


void updateOccupation(char id_train, int id_canton);

int retrouverCanton(int id_train) {
    for (int i = 0; i < 20; ++i) {
        if (globalInfo.occupationCanton[i].id_train == id_train && globalInfo.occupationCanton[i].occupe) {
            return globalInfo.occupationCanton[i].id;
        }
    }
    return -1;
}

int conv_ascii_hex_to_int(const char *hex) {
    int res = 0;
    res += (hex[0] - 48) * 16 * 16;
    if (hex[1] >= 65) {
        res += (hex[1] - 55) * 16;
    } else {
        res += (hex[1] - 48) * 16;
    }
    if (hex[2] >= 65) {
        res += hex[2] - 55;
    } else {
        res += hex[2] - 48;
    }
    return res;
}

int traiterRequete(const char *buffer, int sock) {
    // [id_train][|][canton présence]{3}[|][canton suivant]{3}[|][canton n+2]{3}
    int id_train = buffer[0];
    char arr_canton_sortie[] = {buffer[2], buffer[3], buffer[4]};
    char arr_canton_courant[] = {buffer[6], buffer[7], buffer[8]};
    char arr_canton_suivant[] = {buffer[10], buffer[11], buffer[12]};
    log_debug("init cantons");
    int canton_sortie_train = conv_ascii_hex_to_int(arr_canton_sortie);
    int canton_courant_train = conv_ascii_hex_to_int(arr_canton_courant);
    int canton_suivant_train = conv_ascii_hex_to_int(arr_canton_suivant);

    int nbr1 = essai_prendre_ressource(canton_courant_train, id_train);
    int nbr2 = essai_prendre_ressource(canton_suivant_train, id_train);
    log_debug("Prise des ressources ok");
    essai_rendre_ressources(canton_sortie_train);
    log_debug("Remise des ressources ok");
    canton_t canton1;
    canton_t canton2;
    id_train = id_train - 49;
    log_debug("Id du train : %d", id_train);
    log_debug("IL EST DANS CE CANTON !! : %d", canton_sortie_train);
    for (int i = 0; i < globalInfo.config.config_trains[id_train].nb_cantons; ++i) {
        if (globalInfo.config.config_trains[id_train].cantons[i].id == canton_courant_train) {
            canton1 = globalInfo.config.config_trains[id_train].cantons[i];
            switch (id_train) {
                case 0:
                    switch (canton_sortie_train) {
                        case ID_BALI_3:
                            positionnerAiguillage(ID_AIG_10, BIAIS);
                            usleep(1000);
                            positionnerAiguillage(ID_AIG_18, DROIT);
                            break;
                        case ID_BALI_9:
                            positionnerAiguillage(ID_AIG_2, BIAIS);
                            break;
                    }
                    break;
                case 1:
                    switch (canton_sortie_train) {
                        case ID_BALI_21:
                            positionnerAiguillage(ID_AIG_4, DROIT);
                            usleep(1000);
                            positionnerAiguillage(ID_AIG_5, DROIT);
                            break;
                        case ID_BALI_17:
                            positionnerAiguillage(ID_AIG_6, DROIT);
                            break;
                        case ID_BALI_11:
                            positionnerAiguillage(ID_AIG_10, DROIT);
                            usleep(1000);
                            positionnerAiguillage(ID_AIG_18, BIAIS);
                            usleep(1000);
                            positionnerAiguillage(ID_AIG_16, DROIT);
                            break;
                        case ID_BALI_25:
                            positionnerAiguillage(ID_AIG_12, BIAIS);
                            break;
                    }
                    break;
            }
        }
        if (globalInfo.config.config_trains[id_train].cantons[i].id == canton_suivant_train) {
            canton2 = globalInfo.config.config_trains[id_train].cantons[i];
        }
    }
    log_debug("cantons trouvés");

    char sendBuffer[100];
    int wrote;
    if (nbr1 && nbr2) {
        wrote = sprintf(sendBuffer, "%d:%d|%d:%d", canton1.distance, canton1.vmax, canton2.distance, canton2.vmax);
    } else if (nbr1) {
        wrote = sprintf(sendBuffer, "%d:%d", canton1.distance, canton1.vmax);
    } else {
        wrote = sprintf(sendBuffer, "0:0");
    }
    log_debug("Je vais écrire ça : %s", sendBuffer);
    write(sock, sendBuffer, wrote);
    log_debug("J'ai écrit");
    usleep(500*1000);
    return 0;//(incorrect type)
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
