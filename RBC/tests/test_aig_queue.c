//
// Created by gregoire on 30/11/2021.
//

#include <stdio.h>
#include "../libs/aiguillage_queue.h"

int main() {
    initMessageQueue();
    defiler_message();
    defiler_message();
    Aiguillage_Message_t message1;
    Aiguillage_Message_t message2;
    Aiguillage_Message_t message3;
    Aiguillage_Message_t message4;
    Aiguillage_Message_t message5;
    Aiguillage_Message_t message6;
    Aiguillage_Message_t message7;
    Aiguillage_Message_t message8;
    Aiguillage_Message_t message9;
    Aiguillage_Message_t message10;
    Aiguillage_Message_t message11;
//    message1.sent = 0;
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message1);
    defiler_message();
    defiler_message();
    defiler_message();
    defiler_message();
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message2);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message3);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message4);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message5);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message6);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message7);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message8);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message9);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message10);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message11);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    defiler_message();
    defiler_message();
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message1);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
    enfiler_message(&message2);
    printf("FO = %d | LI = %d | N = %d\n", file_Messages.fo, file_Messages.li, file_Messages.nb_elems);
}