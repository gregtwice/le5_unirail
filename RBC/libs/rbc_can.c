//
// Created by gregoire on 05/12/2021.
//

#include "rbc_utils.h"
#include "aiguillage_queue.h"
#include "../../Libs_Unirail/CAN/Identificateur.h"

void fillFilter(struct can_filter *filter, canton_t cantons[20]) {
    for (int i = 0; i < 20; ++i) {
        filter[i].can_id = cantons[i].id;
        filter[i].can_mask = 0xFFC0;
    }
}

int positionnerAiguillage(int idAiguillage, char position){
    Aiguillage_Message_t messageUnlock = {
            .aigAction = UNLOCK,
            .id = idAiguillage,
            .position = position,
            .sent = 0
    };
    enfiler_message(&messageUnlock);
    Aiguillage_Message_t messagePosition = {
            .aigAction = MVT,
            .id = idAiguillage,
            .position = position,
            .sent = 0
    };
    enfiler_message(&messagePosition);
    return 0;
}