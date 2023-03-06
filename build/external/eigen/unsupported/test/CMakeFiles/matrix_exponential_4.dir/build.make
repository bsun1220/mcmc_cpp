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
include external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/compiler_depend.make

# Include the progress variables for this target.
include external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/progress.make

# Include the compile flags for this target's objects.
include external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/flags.make

external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.o: external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/flags.make
external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.o: /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test/matrix_exponential.cpp
external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.o: external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.o"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.o -MF CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.o.d -o CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.o -c /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test/matrix_exponential.cpp

external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.i"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test/matrix_exponential.cpp > CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.i

external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.s"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test/matrix_exponential.cpp -o CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.s

# Object files for target matrix_exponential_4
matrix_exponential_4_OBJECTS = \
"CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.o"

# External object files for target matrix_exponential_4
matrix_exponential_4_EXTERNAL_OBJECTS =

external/eigen/unsupported/test/matrix_exponential_4: external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/matrix_exponential.cpp.o
external/eigen/unsupported/test/matrix_exponential_4: external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/build.make
external/eigen/unsupported/test/matrix_exponential_4: external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable matrix_exponential_4"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrix_exponential_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/build: external/eigen/unsupported/test/matrix_exponential_4
.PHONY : external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/build

external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/clean:
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && $(CMAKE_COMMAND) -P CMakeFiles/matrix_exponential_4.dir/cmake_clean.cmake
.PHONY : external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/clean

external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/depend:
	cd /Users/bennysun/mcmc_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bennysun/mcmc_cpp /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test /Users/bennysun/mcmc_cpp/build /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/eigen/unsupported/test/CMakeFiles/matrix_exponential_4.dir/depend

