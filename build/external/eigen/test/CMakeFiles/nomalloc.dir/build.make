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

# Utility rule file for nomalloc.

# Include any custom commands dependencies for this target.
include external/eigen/test/CMakeFiles/nomalloc.dir/compiler_depend.make

# Include the progress variables for this target.
include external/eigen/test/CMakeFiles/nomalloc.dir/progress.make

nomalloc: external/eigen/test/CMakeFiles/nomalloc.dir/build.make
.PHONY : nomalloc

# Rule to build all files generated by this target.
external/eigen/test/CMakeFiles/nomalloc.dir/build: nomalloc
.PHONY : external/eigen/test/CMakeFiles/nomalloc.dir/build

external/eigen/test/CMakeFiles/nomalloc.dir/clean:
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/test && $(CMAKE_COMMAND) -P CMakeFiles/nomalloc.dir/cmake_clean.cmake
.PHONY : external/eigen/test/CMakeFiles/nomalloc.dir/clean

external/eigen/test/CMakeFiles/nomalloc.dir/depend:
	cd /Users/bennysun/mcmc_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bennysun/mcmc_cpp /Users/bennysun/mcmc_cpp/external/eigen/test /Users/bennysun/mcmc_cpp/build /Users/bennysun/mcmc_cpp/build/external/eigen/test /Users/bennysun/mcmc_cpp/build/external/eigen/test/CMakeFiles/nomalloc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/eigen/test/CMakeFiles/nomalloc.dir/depend

