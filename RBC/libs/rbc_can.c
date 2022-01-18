//
// Created by gregoire on 05/12/2021.
//

#include "rbc_utils.h"
#include "aiguillage_queue.h"
#include "../../Libs_Unirail/CAN/Identificateur.h"
#include "log.h"

void fillFilter(struct can_filter *filter, canton_t cantons[20]) {
    for (int i = 0; i < 20; ++i) {
        filter[i].can_id = cantons[i].id;
        filter[i].can_mask = 0xFFC0;
    }
}

int positionnerAiguillage(int idAiguillage, char position) {
    Aiguillage_Message_t *message = malloc(sizeof(Aiguillage_Message_t));
    message->id = idAiguillage;
    message->position = position;
//    message->sent = 0;
    enfiler_message(message);
    return 0;
}

void makeTramePosition(uCAN1_MSG *msg, AIG_ACTION action, Aiguillage_Message_t message) {
    msg->frame.id = message.id;
    msg->frame.dlc = 3;
    msg->frame.data0 = action;
    switch (action) {
        case MVT:
            msg->frame.data1 = message.position;
            msg->frame.data2 = 'A';
            break;
        case UNLOCK:
            msg->frame.data1 = 0;
            msg->frame.data2 = 0;
            break;
        case LOCK:
        case INIT:
            // not implemented
            break;
        default:
            break;
    }

}

void trameToString(uCAN1_MSG msg, char *buf) {
    sprintf(buf, "Trame : \nID : %#3X\ndlc : %d\n", msg.frame.id, msg.frame.dlc);
    for (int i = 0; i < msg.frame.dlc; ++i) {
        char tempBuf[20];
        sprintf(tempBuf, "data[%d]=%d\n", i, msg.array[7 + i]);
        strncat(buf, tempBuf, 20);
    }
}

void init_maquette() {
    positionnerAiguillage(ID_AIG_1, DROIT);
    usleep(100 * 1000);
    positionnerAiguillage(ID_AIG_3, BIAIS);
    usleep(100 * 1000);
    positionnerAiguillage(ID_AIG_7, DROIT);
    usleep(100 * 1000);
    positionnerAiguillage(ID_AIG_9, DROIT);
    usleep(100 * 1000);
    positionnerAiguillage(ID_AIG_11, BIAIS);
    usleep(100 * 1000);
    positionnerAiguillage(ID_AIG_13, BIAIS);
    usleep(100 * 1000);
    positionnerAiguillage(ID_AIG_14, BIAIS);
    usleep(100 * 1000);
    positionnerAiguillage(ID_AIG_15, BIAIS);
    usleep(100 * 1000);
    positionnerAiguillage(ID_AIG_17, DROIT);

}

void print_trame(const char *buff) {
    char printTrame[100];
    strncpy(printTrame, buff, 13);
    printTrame[0] += '0';
    log_debug("%s", printTrame);
}
