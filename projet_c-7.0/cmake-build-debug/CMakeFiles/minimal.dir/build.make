# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
<<<<<<< HEAD
CMAKE_COMMAND = /snap/clion/190/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/190/bin/cmake/linux/bin/cmake -E rm -f
=======
CMAKE_COMMAND = /snap/clion-2022.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion-2022.1/bin/cmake/linux/bin/cmake -E rm -f
>>>>>>> refs/remotes/origin/master

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
<<<<<<< HEAD
CMAKE_SOURCE_DIR = /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/cmake-build-debug
=======
CMAKE_SOURCE_DIR = /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/cmake-build-debug
>>>>>>> refs/remotes/origin/master

# Include any dependencies generated for this target.
include CMakeFiles/minimal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/minimal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/minimal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minimal.dir/flags.make

CMakeFiles/minimal.dir/tests/minimal.c.o: CMakeFiles/minimal.dir/flags.make
CMakeFiles/minimal.dir/tests/minimal.c.o: ../tests/minimal.c
CMakeFiles/minimal.dir/tests/minimal.c.o: CMakeFiles/minimal.dir/compiler_depend.ts
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minimal.dir/tests/minimal.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/minimal.dir/tests/minimal.c.o -MF CMakeFiles/minimal.dir/tests/minimal.c.o.d -o CMakeFiles/minimal.dir/tests/minimal.c.o -c /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/tests/minimal.c

CMakeFiles/minimal.dir/tests/minimal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minimal.dir/tests/minimal.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/tests/minimal.c > CMakeFiles/minimal.dir/tests/minimal.c.i

CMakeFiles/minimal.dir/tests/minimal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minimal.dir/tests/minimal.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/tests/minimal.c -o CMakeFiles/minimal.dir/tests/minimal.c.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minimal.dir/tests/minimal.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/minimal.dir/tests/minimal.c.o -MF CMakeFiles/minimal.dir/tests/minimal.c.o.d -o CMakeFiles/minimal.dir/tests/minimal.c.o -c /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/tests/minimal.c

CMakeFiles/minimal.dir/tests/minimal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minimal.dir/tests/minimal.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/tests/minimal.c > CMakeFiles/minimal.dir/tests/minimal.c.i

CMakeFiles/minimal.dir/tests/minimal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minimal.dir/tests/minimal.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/tests/minimal.c -o CMakeFiles/minimal.dir/tests/minimal.c.s
>>>>>>> refs/remotes/origin/master

# Object files for target minimal
minimal_OBJECTS = \
"CMakeFiles/minimal.dir/tests/minimal.c.o"

# External object files for target minimal
minimal_EXTERNAL_OBJECTS =

minimal: CMakeFiles/minimal.dir/tests/minimal.c.o
minimal: CMakeFiles/minimal.dir/build.make
minimal: ../_x11/libeibase64.a
minimal: CMakeFiles/minimal.dir/link.txt
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable minimal"
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable minimal"
>>>>>>> refs/remotes/origin/master
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minimal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minimal.dir/build: minimal
.PHONY : CMakeFiles/minimal.dir/build

CMakeFiles/minimal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minimal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minimal.dir/clean

CMakeFiles/minimal.dir/depend:
<<<<<<< HEAD
	cd /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0 /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0 /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/cmake-build-debug /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/cmake-build-debug /home/hb/Ensimag/C/Projet-C/projet-c/projet_c-7.0/cmake-build-debug/CMakeFiles/minimal.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0 /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0 /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/cmake-build-debug /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/cmake-build-debug /home/axel/Devoirs/PROJETTTT/projet-c/projet_c-7.0/cmake-build-debug/CMakeFiles/minimal.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> refs/remotes/origin/master
.PHONY : CMakeFiles/minimal.dir/depend

