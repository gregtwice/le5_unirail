all : testaig

testaig:
	gcc ../aiguillage_queue.h ../aiguillage_queue.c test_aig_queue.c -lpthread -o test_aig_queue.exe

test_parsing_train: ../libs/log.h ../libs/log.c ../libs/rbc_utils.h ../libs/config_parser.c
	gcc ../libs/log.h ../libs/log.c ../libs/rbc_utils.h ../libs/config_parser.c test_parsing_train.c -o test_parsing_train -DLOG_USE_COLOR

test_hex: ./test_hex_train.c
	gcc $^ -o test_hex_train