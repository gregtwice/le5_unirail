cmake_minimum_required(VERSION 3.17)
project(UNIRAIL C)
find_package(Threads)
find_library(wiringPi_LIB wiringPi)

set(CMAKE_C_STANDARD 99)

add_executable(RPI_Train RPI_Train/main_train.c)
FILE(GLOB RBC_FILES RBC/*.c )
FILE(GLOB UNIRAIL Libs_Unirail/*)
add_executable(RBC ${RBC_FILES} ${UNIRAIL} RBC/aiguillage_queue.c RBC/aiguillage_queue.h RBC/tests/test_aig_queue.c)
add_executable(TEST_FILE RBC RBC/aiguillage_queue.c RBC/aiguillage_queue.h RBC/tests/test_aig_queue.c)