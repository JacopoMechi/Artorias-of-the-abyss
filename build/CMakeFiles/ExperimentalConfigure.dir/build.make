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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build"

# Utility rule file for ExperimentalConfigure.

# Include any custom commands dependencies for this target.
include CMakeFiles/ExperimentalConfigure.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ExperimentalConfigure.dir/progress.make

CMakeFiles/ExperimentalConfigure:
	/opt/homebrew/Cellar/cmake/3.22.0/bin/ctest -D ExperimentalConfigure

ExperimentalConfigure: CMakeFiles/ExperimentalConfigure
ExperimentalConfigure: CMakeFiles/ExperimentalConfigure.dir/build.make
.PHONY : ExperimentalConfigure

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalConfigure.dir/build: ExperimentalConfigure
.PHONY : CMakeFiles/ExperimentalConfigure.dir/build

CMakeFiles/ExperimentalConfigure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExperimentalConfigure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalConfigure.dir/clean

CMakeFiles/ExperimentalConfigure.dir/depend:
	cd "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build/CMakeFiles/ExperimentalConfigure.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ExperimentalConfigure.dir/depend

