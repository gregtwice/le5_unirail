//
// Created by gregoire on 10/01/2022.
//

#include "canton_ressources.h"
#include "cores_bal_can.h"
#include "../../Libs_Unirail/CAN/Identificateur.h"
#include "rbc_utils.h"
#include "log.h"

void init_ressources(int ressource_id) {
    ressource_maquette_t *ressourceMaquette = &globalInfo.ressourcesMaquette[ressource_id];
    pthread_mutex_init(&ressourceMaquette->mutex_ressource, NULL);
    ressourceMaquette->ressource_id = ressource_id;

// C'est ignoble
    switch (ressource_id) {
        case 1: {
            ressourceMaquette->cantons_prise[0] = GLOBAL_BAL[12];
            ressourceMaquette->cantons_prise[1] = GLOBAL_BAL[26];
            ressourceMaquette->cantons_prise[2] = GLOBAL_BAL[0];
            ressourceMaquette->cantons_cession[0] = GLOBAL_BAL[26];
            ressourceMaquette->cantons_cession[1] = GLOBAL_BAL[12];
            ressourceMaquette->cantons_cession[2] = GLOBAL_BAL[0];
            break;
        }
        case 2: {
            ressourceMaquette->cantons_prise[0] = GLOBAL_BAL[26];
            ressourceMaquette->cantons_prise[1] = GLOBAL_BAL[25];
            ressourceMaquette->cantons_prise[2] = GLOBAL_BAL[0];
            ressourceMaquette->cantons_cession[0] = GLOBAL_BAL[27];
            ressourceMaquette->cantons_cession[1] = GLOBAL_BAL[20];
            ressourceMaquette->cantons_cession[2] = GLOBAL_BAL[0];
            break;
        }
        case 3: {
            ressourceMaquette->cantons_prise[0] = GLOBAL_BAL[11];
            ressourceMaquette->cantons_prise[1] = GLOBAL_BAL[0];
            ressourceMaquette->cantons_cession[0] = GLOBAL_BAL[26];
            ressourceMaquette->cantons_cession[1] = GLOBAL_BAL[12];
            ressourceMaquette->cantons_cession[2] = GLOBAL_BAL[0];
            break;
        }
        case 4: {
            ressourceMaquette->cantons_prise[0] = GLOBAL_BAL[17];
            ressourceMaquette->cantons_prise[1] = GLOBAL_BAL[22];
            ressourceMaquette->cantons_prise[2] = GLOBAL_BAL[0];
            ressourceMaquette->cantons_cession[0] = GLOBAL_BAL[17];
            ressourceMaquette->cantons_cession[1] = GLOBAL_BAL[22];
            ressourceMaquette->cantons_cession[2] = GLOBAL_BAL[0];
            break;
        }
        case 5: {
            ressourceMaquette->cantons_prise[0] = GLOBAL_BAL[1];
            ressourceMaquette->cantons_prise[1] = GLOBAL_BAL[22];
            ressourceMaquette->cantons_prise[2] = GLOBAL_BAL[0];
            ressourceMaquette->cantons_cession[0] = GLOBAL_BAL[1];
            ressourceMaquette->cantons_cession[1] = GLOBAL_BAL[22];
            ressourceMaquette->cantons_cession[2] = GLOBAL_BAL[0];
            break;
        }
    }

}

void setUpAiguillages(int ressource_id, int id_train) {
    switch (ressource_id) {
        case 1: {
            switch (id_train) {
                case 0:
                    positionnerAiguillage(ID_AIG_10, BIAIS);
                    positionnerAiguillage(ID_AIG_18, DROIT);
                    break;
                case 1:
                    positionnerAiguillage(ID_AIG_10, BIAIS);
                    positionnerAiguillage(ID_AIG_18, BIAIS);
                    break;
                case 2:
                    positionnerAiguillage(ID_AIG_10, DROIT);
                    positionnerAiguillage(ID_AIG_18, DROIT);
                    break;
            }
            break;
        }
        case 2: {
            if (id_train == 1) {
                positionnerAiguillage(ID_AIG_12, BIAIS);
                positionnerAiguillage(ID_AIG_16, DROIT);
            }
            if (id_train == 2) {
                positionnerAiguillage(ID_AIG_12, DROIT);
                positionnerAiguillage(ID_AIG_16, BIAIS);
            }
            break;
        }
        case 3: {
            if (id_train == 1) {
                positionnerAiguillage(ID_AIG_6, DROIT);
            } else if (id_train == 2) {
                positionnerAiguillage(ID_AIG_6, BIAIS);
            }
            break;
        }
        case 4: {
            if (id_train == 1) {
                positionnerAiguillage(ID_AIG_5, DROIT);
                positionnerAiguillage(ID_AIG_6, DROIT);
            } else if (id_train == 2) {
                positionnerAiguillage(ID_AIG_5, BIAIS);
                positionnerAiguillage(ID_AIG_6, BIAIS);
            }
            break;
        }
        case 5: {
            if (id_train == 0) {
                positionnerAiguillage(ID_AIG_2, BIAIS);
            }
            if (id_train == 1) {
                positionnerAiguillage(ID_AIG_2, DROIT);
            }
            break;
        }
        default:
            return;
    }
}

int essai_prendre_ressource(int id_canton_du_train, int id_train) {
    log_debug("id_canton : %d", id_canton_du_train);
    int ressources_a_prendre[2] = {0, 0};
    int nb_ressources_prises = 0;
    // parcourir toutes les ressources pour vérifier que l'on a une ressource à prendre
    for (int index_ressource = 1; index_ressource < 6; ++index_ressource) {
        ressource_maquette_t ressource_en_cours = globalInfo.ressourcesMaquette[index_ressource];
        int index_cantons_prise_maquette = -1;
        do {
            index_cantons_prise_maquette++;
        } while (ressource_en_cours.cantons_prise[index_cantons_prise_maquette] != id_canton_du_train &&
                 ressource_en_cours.cantons_prise[index_cantons_prise_maquette] != 0);

        if (ressource_en_cours.cantons_prise[index_cantons_prise_maquette] == 0) {
            continue;
        }

        ressources_a_prendre[nb_ressources_prises] = ressource_en_cours.ressource_id;
        nb_ressources_prises++;
    }
    log_debug("ressources à prendre %d", nb_ressources_prises);
    log_debug("%d %d", ressources_a_prendre[0], ressources_a_prendre[1]);
    // prendre les ressources
    int flags_reussite_prise_ressource[2] = {1, 1};
    // pour chaque ressource à prendre
    for (int index_ressource_a_prendre = 0; index_ressource_a_prendre < nb_ressources_prises; ++index_ressource_a_prendre) {
        // si la ressource est déja prise par le train, alors ce n'est pas grave, on continue
        if (globalInfo.ressourcesMaquette[ressources_a_prendre[index_ressource_a_prendre]].current_train == id_train)continue;

        log_debug("Tentative reservation ressource : %d", ressources_a_prendre[index_ressource_a_prendre]);
        if (pthread_mutex_trylock(&globalInfo.ressourcesMaquette[ressources_a_prendre[index_ressource_a_prendre]].mutex_ressource)) {
            flags_reussite_prise_ressource[index_ressource_a_prendre] = 0;
            log_debug("Echec Prise de la ressource %d", ressources_a_prendre[index_ressource_a_prendre]);
        } else {
            globalInfo.ressourcesMaquette[ressources_a_prendre[index_ressource_a_prendre]].current_train = id_train;
        }
    }

    for (int index_ressource = 0; index_ressource < nb_ressources_prises; ++index_ressource) {
        if (flags_reussite_prise_ressource[index_ressource])
            setUpAiguillages(ressources_a_prendre[index_ressource], id_train);
    }
    return 1; // les ressources sont prises
}

void essai_rendre_ressources(int id_canton_du_train) {
    int ressources_a_rendre[2] = {0, 0};
    int ressources_rendues = 0;
    for (int index_ressource = 0; index_ressource < 5; ++index_ressource) {
        ressource_maquette_t ressource_en_cours = globalInfo.ressourcesMaquette[index_ressource];
        int index_cantons_cession = 0;

        while (ressource_en_cours.cantons_cession[index_cantons_cession] != id_canton_du_train &&
               ressource_en_cours.cantons_cession[index_cantons_cession] != 0) {
            index_cantons_cession++;
        }
        ressources_a_rendre[ressources_rendues] = ressource_en_cours.ressource_id;
        ressources_rendues++;
    }
    for (int i = 0; i < ressources_rendues; ++i) {
        log_debug("Remise ressource : %d", ressources_a_rendre[i]);
        pthread_mutex_unlock(&globalInfo.ressourcesMaquette[ressources_a_rendre[i]].mutex_ressource);
        globalInfo.ressourcesMaquette[ressources_a_rendre[ressources_rendues]].current_train = -1;
    }
}