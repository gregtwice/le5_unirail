cmake_minimum_required(VERSION 3.0)
project(RBC_LE5)
find_package (Threads)
#find_library(wiringPi_LIB wiringPi)
add_definitions(-DMC802=0)
set (PATH_LIB_UNIRAIL ../Libs_Unirail/)
include_directories(${PATH_LIB_UNIRAIL})


# Cree des variables avec les fichiers a compiler
set(SRCS
        ${PATH_LIB_UNIRAIL}CAN/canLinux.c
        ${PATH_LIB_UNIRAIL}CAN/MESCAN1_Utilitaire.c
        ${PATH_LIB_UNIRAIL}CAN/MESCAN1_VarStatusTrain.c
        ${PATH_LIB_UNIRAIL}CAN/MESCAN1_VarTrain.c
        libs/aiguillage_queue.c
        libs/log.c
        libs/config_parser.c
        libs/rbc_can.c
        main_rbc.c
        libs/train_comm.c
        libs/canton_ressources.c
        )

set(HEADERS
        ${PATH_LIB_UNIRAIL}CAN/canLinux.h
        ${PATH_LIB_UNIRAIL}CAN/MESCAN1_Utilitaire.h
        ${PATH_LIB_UNIRAIL}CAN/loco_MAIN_PARAMS.h
        ${PATH_LIB_UNIRAIL}CAN/MESCAN1_DefinitionVariable.h
        libs/aiguillage_queue.h
        libs/log.h
        libs/rbc_utils.h
        libs/cores_bal_can.h
        libs/canton_ressources.h
        #        ${PATH_LIB_UNIRAIL}CAN/MESCAN1_ID&DLC_LOCO.h
        ${PATH_LIB_UNIRAIL}CAN/Identificateur.h
        ${PATH_LIB_UNIRAIL}CAN/MESCAN1_VarStatusTrain.h
        ${PATH_LIB_UNIRAIL}CAN/MESCAN1_VarTrain.h
        )
set (EXECSRC main_rbc.c)
set (EXECUTABLE main_rbc.exe)

set(SRCS ${SRCS} ${EXECSRC} )
add_executable(${EXECUTABLE} ${SRCS} ${HEADERS})
target_compile_options(${EXECUTABLE} PRIVATE -Wall -DVERBOSE -DLOG_USE_COLOR)

#inclusion des libs (equivalent a -lwiringPi -lpthread -lm)
target_link_libraries( ${EXECUTABLE} pthread )
#target_link_libraries( ${EXECUTABLE} wiringPi )
target_link_libraries( ${EXECUTABLE} m )
target_link_libraries( ${EXECUTABLE} rt )