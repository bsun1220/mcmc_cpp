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
include external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compiler_depend.make

# Include the progress variables for this target.
include external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/progress.make

# Include the compile flags for this target's objects.
include external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/flags.make

external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o: external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/flags.make
external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o: external/eigen/doc/snippets/compile_TopicAliasing_mult5.cpp
external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o: /Users/bennysun/mcmc_cpp/external/eigen/doc/snippets/TopicAliasing_mult5.cpp
external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o: external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o -MF CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o.d -o CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o -c /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets/compile_TopicAliasing_mult5.cpp

external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.i"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets/compile_TopicAliasing_mult5.cpp > CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.i

external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.s"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets/compile_TopicAliasing_mult5.cpp -o CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.s

# Object files for target compile_TopicAliasing_mult5
compile_TopicAliasing_mult5_OBJECTS = \
"CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o"

# External object files for target compile_TopicAliasing_mult5
compile_TopicAliasing_mult5_EXTERNAL_OBJECTS =

external/eigen/doc/snippets/compile_TopicAliasing_mult5: external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/compile_TopicAliasing_mult5.cpp.o
external/eigen/doc/snippets/compile_TopicAliasing_mult5: external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/build.make
external/eigen/doc/snippets/compile_TopicAliasing_mult5: external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bennysun/mcmc_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable compile_TopicAliasing_mult5"
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile_TopicAliasing_mult5.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets && ./compile_TopicAliasing_mult5 >/Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets/TopicAliasing_mult5.out

# Rule to build all files generated by this target.
external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/build: external/eigen/doc/snippets/compile_TopicAliasing_mult5
.PHONY : external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/build

external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/clean:
	cd /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets && $(CMAKE_COMMAND) -P CMakeFiles/compile_TopicAliasing_mult5.dir/cmake_clean.cmake
.PHONY : external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/clean

external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/depend:
	cd /Users/bennysun/mcmc_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bennysun/mcmc_cpp /Users/bennysun/mcmc_cpp/external/eigen/doc/snippets /Users/bennysun/mcmc_cpp/build /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets /Users/bennysun/mcmc_cpp/build/external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/eigen/doc/snippets/CMakeFiles/compile_TopicAliasing_mult5.dir/depend

