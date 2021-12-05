//
// Created by gregoire on 05/12/2021.
//

#include "rbc_utils.h"

void fillFilter(struct can_filter *filter, canton_t cantons[20]) {
    for (int i = 0; i < 20; ++i) {
        filter[i].can_id = globalInfo.config.cantons_to_watch[i].id;
        filter[i].can_mask = CAN_SFF_MASK;
    }
}