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
include CMakeFiles/ArtoriasOfTheAbyss.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ArtoriasOfTheAbyss.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ArtoriasOfTheAbyss.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ArtoriasOfTheAbyss.dir/flags.make

CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.o: CMakeFiles/ArtoriasOfTheAbyss.dir/flags.make
CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.o: ../main.cpp
CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.o: CMakeFiles/ArtoriasOfTheAbyss.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.o -MF CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.o.d -o CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.o -c "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/main.cpp"

CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/main.cpp" > CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.i

CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/main.cpp" -o CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.s

# Object files for target ArtoriasOfTheAbyss
ArtoriasOfTheAbyss_OBJECTS = \
"CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.o"

# External object files for target ArtoriasOfTheAbyss
ArtoriasOfTheAbyss_EXTERNAL_OBJECTS =

ArtoriasOfTheAbyss: CMakeFiles/ArtoriasOfTheAbyss.dir/main.cpp.o
ArtoriasOfTheAbyss: CMakeFiles/ArtoriasOfTheAbyss.dir/build.make
ArtoriasOfTheAbyss: /opt/homebrew/lib/libsfml-graphics.2.5.1.dylib
ArtoriasOfTheAbyss: /opt/homebrew/lib/libsfml-window.2.5.1.dylib
ArtoriasOfTheAbyss: /opt/homebrew/lib/libsfml-system.2.5.1.dylib
ArtoriasOfTheAbyss: CMakeFiles/ArtoriasOfTheAbyss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ArtoriasOfTheAbyss"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ArtoriasOfTheAbyss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ArtoriasOfTheAbyss.dir/build: ArtoriasOfTheAbyss
.PHONY : CMakeFiles/ArtoriasOfTheAbyss.dir/build

CMakeFiles/ArtoriasOfTheAbyss.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ArtoriasOfTheAbyss.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ArtoriasOfTheAbyss.dir/clean

CMakeFiles/ArtoriasOfTheAbyss.dir/depend:
	cd "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build" "/Users/jacopown/Documents/Universita'/Artorias-of-the-abyss/build/CMakeFiles/ArtoriasOfTheAbyss.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ArtoriasOfTheAbyss.dir/depend

