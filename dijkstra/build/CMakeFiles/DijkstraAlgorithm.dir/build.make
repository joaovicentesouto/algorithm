# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joaovicente/code/algorithm/dijkstra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joaovicente/code/algorithm/dijkstra/build

# Include any dependencies generated for this target.
include CMakeFiles/DijkstraAlgorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DijkstraAlgorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DijkstraAlgorithm.dir/flags.make

CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o: CMakeFiles/DijkstraAlgorithm.dir/flags.make
CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o: ../dijkstra_algorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joaovicente/code/algorithm/dijkstra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o -c /home/joaovicente/code/algorithm/dijkstra/dijkstra_algorithm.cpp

CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joaovicente/code/algorithm/dijkstra/dijkstra_algorithm.cpp > CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.i

CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joaovicente/code/algorithm/dijkstra/dijkstra_algorithm.cpp -o CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.s

CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o.requires:

.PHONY : CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o.requires

CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o.provides: CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o.requires
	$(MAKE) -f CMakeFiles/DijkstraAlgorithm.dir/build.make CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o.provides.build
.PHONY : CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o.provides

CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o.provides.build: CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o


# Object files for target DijkstraAlgorithm
DijkstraAlgorithm_OBJECTS = \
"CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o"

# External object files for target DijkstraAlgorithm
DijkstraAlgorithm_EXTERNAL_OBJECTS =

libDijkstraAlgorithm.a: CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o
libDijkstraAlgorithm.a: CMakeFiles/DijkstraAlgorithm.dir/build.make
libDijkstraAlgorithm.a: CMakeFiles/DijkstraAlgorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joaovicente/code/algorithm/dijkstra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDijkstraAlgorithm.a"
	$(CMAKE_COMMAND) -P CMakeFiles/DijkstraAlgorithm.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DijkstraAlgorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DijkstraAlgorithm.dir/build: libDijkstraAlgorithm.a

.PHONY : CMakeFiles/DijkstraAlgorithm.dir/build

CMakeFiles/DijkstraAlgorithm.dir/requires: CMakeFiles/DijkstraAlgorithm.dir/dijkstra_algorithm.cpp.o.requires

.PHONY : CMakeFiles/DijkstraAlgorithm.dir/requires

CMakeFiles/DijkstraAlgorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DijkstraAlgorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DijkstraAlgorithm.dir/clean

CMakeFiles/DijkstraAlgorithm.dir/depend:
	cd /home/joaovicente/code/algorithm/dijkstra/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joaovicente/code/algorithm/dijkstra /home/joaovicente/code/algorithm/dijkstra /home/joaovicente/code/algorithm/dijkstra/build /home/joaovicente/code/algorithm/dijkstra/build /home/joaovicente/code/algorithm/dijkstra/build/CMakeFiles/DijkstraAlgorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DijkstraAlgorithm.dir/depend

