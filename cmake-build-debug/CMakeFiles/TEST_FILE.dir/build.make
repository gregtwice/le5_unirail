# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2020.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.3.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gregoire/Documents/IG2I/LE5/UNIRAIL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TEST_FILE.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TEST_FILE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TEST_FILE.dir/flags.make

CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.o: CMakeFiles/TEST_FILE.dir/flags.make
CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.o: ../RBC/main_rbc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.o   -c /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/main_rbc.c

CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/main_rbc.c > CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.i

CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/main_rbc.c -o CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.s

CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.o: CMakeFiles/TEST_FILE.dir/flags.make
CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.o: ../RBC/libs/aiguillage_queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.o   -c /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/aiguillage_queue.c

CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/aiguillage_queue.c > CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.i

CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/aiguillage_queue.c -o CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.s

CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.o: CMakeFiles/TEST_FILE.dir/flags.make
CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.o: ../RBC/libs/config_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.o   -c /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/config_parser.c

CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/config_parser.c > CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.i

CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/config_parser.c -o CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.s

CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.o: CMakeFiles/TEST_FILE.dir/flags.make
CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.o: ../RBC/libs/log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.o   -c /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/log.c

CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/log.c > CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.i

CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/log.c -o CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.s

CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.o: CMakeFiles/TEST_FILE.dir/flags.make
CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.o: ../RBC/libs/rbc_can.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.o   -c /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/rbc_can.c

CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/rbc_can.c > CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.i

CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/rbc_can.c -o CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.s

CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.o: CMakeFiles/TEST_FILE.dir/flags.make
CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.o: ../RBC/libs/train_comm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.o   -c /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/train_comm.c

CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/train_comm.c > CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.i

CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gregoire/Documents/IG2I/LE5/UNIRAIL/RBC/libs/train_comm.c -o CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.s

# Object files for target TEST_FILE
TEST_FILE_OBJECTS = \
"CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.o" \
"CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.o" \
"CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.o" \
"CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.o" \
"CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.o" \
"CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.o"

# External object files for target TEST_FILE
TEST_FILE_EXTERNAL_OBJECTS =

TEST_FILE: CMakeFiles/TEST_FILE.dir/RBC/main_rbc.c.o
TEST_FILE: CMakeFiles/TEST_FILE.dir/RBC/libs/aiguillage_queue.c.o
TEST_FILE: CMakeFiles/TEST_FILE.dir/RBC/libs/config_parser.c.o
TEST_FILE: CMakeFiles/TEST_FILE.dir/RBC/libs/log.c.o
TEST_FILE: CMakeFiles/TEST_FILE.dir/RBC/libs/rbc_can.c.o
TEST_FILE: CMakeFiles/TEST_FILE.dir/RBC/libs/train_comm.c.o
TEST_FILE: CMakeFiles/TEST_FILE.dir/build.make
TEST_FILE: CMakeFiles/TEST_FILE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable TEST_FILE"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TEST_FILE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TEST_FILE.dir/build: TEST_FILE

.PHONY : CMakeFiles/TEST_FILE.dir/build

CMakeFiles/TEST_FILE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TEST_FILE.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TEST_FILE.dir/clean

CMakeFiles/TEST_FILE.dir/depend:
	cd /home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gregoire/Documents/IG2I/LE5/UNIRAIL /home/gregoire/Documents/IG2I/LE5/UNIRAIL /home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug /home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug /home/gregoire/Documents/IG2I/LE5/UNIRAIL/cmake-build-debug/CMakeFiles/TEST_FILE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TEST_FILE.dir/depend

