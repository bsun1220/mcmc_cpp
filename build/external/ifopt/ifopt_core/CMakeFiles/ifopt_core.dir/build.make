# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bennysun/mcmc_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bennysun/mcmc_cpp/build

# Include any dependencies generated for this target.
include external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/compiler_depend.make

# Include the progress variables for this target.
include external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/progress.make

# Include the compile flags for this target's objects.
include external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/flags.make

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/problem.cc.o: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/flags.make
external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/problem.cc.o: /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/problem.cc
external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/problem.cc.o: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/problem.cc.o"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/problem.cc.o -MF CMakeFiles/ifopt_core.dir/src/problem.cc.o.d -o CMakeFiles/ifopt_core.dir/src/problem.cc.o -c /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/problem.cc

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/problem.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ifopt_core.dir/src/problem.cc.i"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/problem.cc > CMakeFiles/ifopt_core.dir/src/problem.cc.i

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/problem.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ifopt_core.dir/src/problem.cc.s"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/problem.cc -o CMakeFiles/ifopt_core.dir/src/problem.cc.s

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/composite.cc.o: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/flags.make
external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/composite.cc.o: /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/composite.cc
external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/composite.cc.o: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/composite.cc.o"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/composite.cc.o -MF CMakeFiles/ifopt_core.dir/src/composite.cc.o.d -o CMakeFiles/ifopt_core.dir/src/composite.cc.o -c /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/composite.cc

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/composite.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ifopt_core.dir/src/composite.cc.i"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/composite.cc > CMakeFiles/ifopt_core.dir/src/composite.cc.i

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/composite.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ifopt_core.dir/src/composite.cc.s"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/composite.cc -o CMakeFiles/ifopt_core.dir/src/composite.cc.s

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/leaves.cc.o: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/flags.make
external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/leaves.cc.o: /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/leaves.cc
external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/leaves.cc.o: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/leaves.cc.o"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/leaves.cc.o -MF CMakeFiles/ifopt_core.dir/src/leaves.cc.o.d -o CMakeFiles/ifopt_core.dir/src/leaves.cc.o -c /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/leaves.cc

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/leaves.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ifopt_core.dir/src/leaves.cc.i"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/leaves.cc > CMakeFiles/ifopt_core.dir/src/leaves.cc.i

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/leaves.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ifopt_core.dir/src/leaves.cc.s"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core/src/leaves.cc -o CMakeFiles/ifopt_core.dir/src/leaves.cc.s

# Object files for target ifopt_core
ifopt_core_OBJECTS = \
"CMakeFiles/ifopt_core.dir/src/problem.cc.o" \
"CMakeFiles/ifopt_core.dir/src/composite.cc.o" \
"CMakeFiles/ifopt_core.dir/src/leaves.cc.o"

# External object files for target ifopt_core
ifopt_core_EXTERNAL_OBJECTS =

external/ifopt/ifopt_core/libifopt_core.dylib: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/problem.cc.o
external/ifopt/ifopt_core/libifopt_core.dylib: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/composite.cc.o
external/ifopt/ifopt_core/libifopt_core.dylib: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/src/leaves.cc.o
external/ifopt/ifopt_core/libifopt_core.dylib: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/build.make
external/ifopt/ifopt_core/libifopt_core.dylib: external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libifopt_core.dylib"
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ifopt_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/build: external/ifopt/ifopt_core/libifopt_core.dylib
.PHONY : external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/build

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/clean:
	cd /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core && $(CMAKE_COMMAND) -P CMakeFiles/ifopt_core.dir/cmake_clean.cmake
.PHONY : external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/clean

external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/depend:
	cd /Users/bennysun/mcmc_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bennysun/mcmc_cpp /Users/bennysun/mcmc_cpp/external/ifopt/ifopt_core /Users/bennysun/mcmc_cpp/build /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core /Users/bennysun/mcmc_cpp/build/external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/ifopt/ifopt_core/CMakeFiles/ifopt_core.dir/depend

