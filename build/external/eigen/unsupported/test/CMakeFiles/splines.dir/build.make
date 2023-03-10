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
include external/eigen/unsupported/test/CMakeFiles/splines.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/eigen/unsupported/test/CMakeFiles/splines.dir/compiler_depend.make

# Include the progress variables for this target.
include external/eigen/unsupported/test/CMakeFiles/splines.dir/progress.make

# Include the compile flags for this target's objects.
include external/eigen/unsupported/test/CMakeFiles/splines.dir/flags.make

external/eigen/unsupported/test/CMakeFiles/splines.dir/splines.cpp.o: external/eigen/unsupported/test/CMakeFiles/splines.dir/flags.make
external/eigen/unsupported/test/CMakeFiles/splines.dir/splines.cpp.o: /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test/splines.cpp
external/eigen/unsupported/test/CMakeFiles/splines.dir/splines.cpp.o: external/eigen/unsupported/test/CMakeFiles/splines.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/eigen/unsupported/test/CMakeFiles/splines.dir/splines.cpp.o"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/eigen/unsupported/test/CMakeFiles/splines.dir/splines.cpp.o -MF CMakeFiles/splines.dir/splines.cpp.o.d -o CMakeFiles/splines.dir/splines.cpp.o -c /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test/splines.cpp

external/eigen/unsupported/test/CMakeFiles/splines.dir/splines.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/splines.dir/splines.cpp.i"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test/splines.cpp > CMakeFiles/splines.dir/splines.cpp.i

external/eigen/unsupported/test/CMakeFiles/splines.dir/splines.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/splines.dir/splines.cpp.s"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test/splines.cpp -o CMakeFiles/splines.dir/splines.cpp.s

# Object files for target splines
splines_OBJECTS = \
"CMakeFiles/splines.dir/splines.cpp.o"

# External object files for target splines
splines_EXTERNAL_OBJECTS =

external/eigen/unsupported/test/splines: external/eigen/unsupported/test/CMakeFiles/splines.dir/splines.cpp.o
external/eigen/unsupported/test/splines: external/eigen/unsupported/test/CMakeFiles/splines.dir/build.make
external/eigen/unsupported/test/splines: external/eigen/unsupported/test/CMakeFiles/splines.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable splines"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splines.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/eigen/unsupported/test/CMakeFiles/splines.dir/build: external/eigen/unsupported/test/splines
.PHONY : external/eigen/unsupported/test/CMakeFiles/splines.dir/build

external/eigen/unsupported/test/CMakeFiles/splines.dir/clean:
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test && $(CMAKE_COMMAND) -P CMakeFiles/splines.dir/cmake_clean.cmake
.PHONY : external/eigen/unsupported/test/CMakeFiles/splines.dir/clean

external/eigen/unsupported/test/CMakeFiles/splines.dir/depend:
	cd /Users/bennysun/mcmc_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bennysun/mcmc_cpp /Users/bennysun/mcmc_cpp/external/eigen/unsupported/test /Users/bennysun/mcmc_cpp/build /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test /Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/test/CMakeFiles/splines.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/eigen/unsupported/test/CMakeFiles/splines.dir/depend

