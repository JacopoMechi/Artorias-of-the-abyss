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

# Include any dependencies generated for this target.
include CMakeFiles/Artorias-Of-The_Abyss.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Artorias-Of-The_Abyss.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Artorias-Of-The_Abyss.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Artorias-Of-The_Abyss.dir/flags.make

CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.o: CMakeFiles/Artorias-Of-The_Abyss.dir/flags.make
CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.o: ../main.cpp
CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.o: CMakeFiles/Artorias-Of-The_Abyss.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.o -MF CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.o.d -o CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.o -c "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/main.cpp"

CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/main.cpp" > CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.i

CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/main.cpp" -o CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.s

# Object files for target Artorias-Of-The_Abyss
Artorias__Of__The_Abyss_OBJECTS = \
"CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.o"

# External object files for target Artorias-Of-The_Abyss
Artorias__Of__The_Abyss_EXTERNAL_OBJECTS =

Artorias-Of-The_Abyss: CMakeFiles/Artorias-Of-The_Abyss.dir/main.cpp.o
Artorias-Of-The_Abyss: CMakeFiles/Artorias-Of-The_Abyss.dir/build.make
Artorias-Of-The_Abyss: CMakeFiles/Artorias-Of-The_Abyss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Artorias-Of-The_Abyss"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Artorias-Of-The_Abyss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Artorias-Of-The_Abyss.dir/build: Artorias-Of-The_Abyss
.PHONY : CMakeFiles/Artorias-Of-The_Abyss.dir/build

CMakeFiles/Artorias-Of-The_Abyss.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Artorias-Of-The_Abyss.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Artorias-Of-The_Abyss.dir/clean

CMakeFiles/Artorias-Of-The_Abyss.dir/depend:
	cd "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build/CMakeFiles/Artorias-Of-The_Abyss.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Artorias-Of-The_Abyss.dir/depend
