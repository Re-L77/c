# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/re-l/Escritorio/github/c/4.0/Factorial_R-I

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/re-l/Escritorio/github/c/4.0/Factorial_R-I/build

# Include any dependencies generated for this target.
include CMakeFiles/Factorial_R-I.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Factorial_R-I.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Factorial_R-I.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Factorial_R-I.dir/flags.make

CMakeFiles/Factorial_R-I.dir/codegen:
.PHONY : CMakeFiles/Factorial_R-I.dir/codegen

CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.o: CMakeFiles/Factorial_R-I.dir/flags.make
CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.o: /home/re-l/Escritorio/github/c/4.0/Factorial_R-I/src/Factorial_R-I.c
CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.o: CMakeFiles/Factorial_R-I.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/re-l/Escritorio/github/c/4.0/Factorial_R-I/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.o -MF CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.o.d -o CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.o -c /home/re-l/Escritorio/github/c/4.0/Factorial_R-I/src/Factorial_R-I.c

CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/re-l/Escritorio/github/c/4.0/Factorial_R-I/src/Factorial_R-I.c > CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.i

CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/re-l/Escritorio/github/c/4.0/Factorial_R-I/src/Factorial_R-I.c -o CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.s

# Object files for target Factorial_R-I
Factorial_R__I_OBJECTS = \
"CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.o"

# External object files for target Factorial_R-I
Factorial_R__I_EXTERNAL_OBJECTS =

Factorial_R-I: CMakeFiles/Factorial_R-I.dir/src/Factorial_R-I.c.o
Factorial_R-I: CMakeFiles/Factorial_R-I.dir/build.make
Factorial_R-I: CMakeFiles/Factorial_R-I.dir/compiler_depend.ts
Factorial_R-I: /usr/lib/libcurses.so
Factorial_R-I: /usr/lib/libform.so
Factorial_R-I: CMakeFiles/Factorial_R-I.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/re-l/Escritorio/github/c/4.0/Factorial_R-I/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Factorial_R-I"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Factorial_R-I.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Factorial_R-I.dir/build: Factorial_R-I
.PHONY : CMakeFiles/Factorial_R-I.dir/build

CMakeFiles/Factorial_R-I.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Factorial_R-I.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Factorial_R-I.dir/clean

CMakeFiles/Factorial_R-I.dir/depend:
	cd /home/re-l/Escritorio/github/c/4.0/Factorial_R-I/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/re-l/Escritorio/github/c/4.0/Factorial_R-I /home/re-l/Escritorio/github/c/4.0/Factorial_R-I /home/re-l/Escritorio/github/c/4.0/Factorial_R-I/build /home/re-l/Escritorio/github/c/4.0/Factorial_R-I/build /home/re-l/Escritorio/github/c/4.0/Factorial_R-I/build/CMakeFiles/Factorial_R-I.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Factorial_R-I.dir/depend

