//
// Created by gregoire on 05/12/2021.
//

#include "../libs/rbc_utils.h"
#include "../libs/log.h"
int main() {
    trainConfig_t config;
    log_set_level(LOG_DEBUG);
    parsetrainconfig("./train1.conf", &config);
}