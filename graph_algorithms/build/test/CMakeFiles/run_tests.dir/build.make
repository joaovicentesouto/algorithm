# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /opt/cmake-3.4.3-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.4.3-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/denis/Documents/algorithm/graph_algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denis/Documents/algorithm/graph_algorithms/build

# Include any dependencies generated for this target.
include test/CMakeFiles/run_tests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/run_tests.dir/flags.make

test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o: ../test/dijkstra_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/Documents/algorithm/graph_algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o"
	cd /home/denis/Documents/algorithm/graph_algorithms/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/dijkstra_test.cpp.o -c /home/denis/Documents/algorithm/graph_algorithms/test/dijkstra_test.cpp

test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/dijkstra_test.cpp.i"
	cd /home/denis/Documents/algorithm/graph_algorithms/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/Documents/algorithm/graph_algorithms/test/dijkstra_test.cpp > CMakeFiles/run_tests.dir/dijkstra_test.cpp.i

test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/dijkstra_test.cpp.s"
	cd /home/denis/Documents/algorithm/graph_algorithms/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/Documents/algorithm/graph_algorithms/test/dijkstra_test.cpp -o CMakeFiles/run_tests.dir/dijkstra_test.cpp.s

test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o.requires:

.PHONY : test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o.requires

test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o.provides: test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/run_tests.dir/build.make test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o.provides.build
.PHONY : test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o.provides

test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o.provides.build: test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o


test/CMakeFiles/run_tests.dir/main.cpp.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/main.cpp.o: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/Documents/algorithm/graph_algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/run_tests.dir/main.cpp.o"
	cd /home/denis/Documents/algorithm/graph_algorithms/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_tests.dir/main.cpp.o -c /home/denis/Documents/algorithm/graph_algorithms/test/main.cpp

test/CMakeFiles/run_tests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/main.cpp.i"
	cd /home/denis/Documents/algorithm/graph_algorithms/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/Documents/algorithm/graph_algorithms/test/main.cpp > CMakeFiles/run_tests.dir/main.cpp.i

test/CMakeFiles/run_tests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/main.cpp.s"
	cd /home/denis/Documents/algorithm/graph_algorithms/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/Documents/algorithm/graph_algorithms/test/main.cpp -o CMakeFiles/run_tests.dir/main.cpp.s

test/CMakeFiles/run_tests.dir/main.cpp.o.requires:

.PHONY : test/CMakeFiles/run_tests.dir/main.cpp.o.requires

test/CMakeFiles/run_tests.dir/main.cpp.o.provides: test/CMakeFiles/run_tests.dir/main.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/run_tests.dir/build.make test/CMakeFiles/run_tests.dir/main.cpp.o.provides.build
.PHONY : test/CMakeFiles/run_tests.dir/main.cpp.o.provides

test/CMakeFiles/run_tests.dir/main.cpp.o.provides.build: test/CMakeFiles/run_tests.dir/main.cpp.o


# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/dijkstra_test.cpp.o" \
"CMakeFiles/run_tests.dir/main.cpp.o"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

test/run_tests: test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o
test/run_tests: test/CMakeFiles/run_tests.dir/main.cpp.o
test/run_tests: test/CMakeFiles/run_tests.dir/build.make
test/run_tests: test/CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/denis/Documents/algorithm/graph_algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable run_tests"
	cd /home/denis/Documents/algorithm/graph_algorithms/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/run_tests.dir/build: test/run_tests

.PHONY : test/CMakeFiles/run_tests.dir/build

test/CMakeFiles/run_tests.dir/requires: test/CMakeFiles/run_tests.dir/dijkstra_test.cpp.o.requires
test/CMakeFiles/run_tests.dir/requires: test/CMakeFiles/run_tests.dir/main.cpp.o.requires

.PHONY : test/CMakeFiles/run_tests.dir/requires

test/CMakeFiles/run_tests.dir/clean:
	cd /home/denis/Documents/algorithm/graph_algorithms/build/test && $(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/run_tests.dir/clean

test/CMakeFiles/run_tests.dir/depend:
	cd /home/denis/Documents/algorithm/graph_algorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denis/Documents/algorithm/graph_algorithms /home/denis/Documents/algorithm/graph_algorithms/test /home/denis/Documents/algorithm/graph_algorithms/build /home/denis/Documents/algorithm/graph_algorithms/build/test /home/denis/Documents/algorithm/graph_algorithms/build/test/CMakeFiles/run_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/run_tests.dir/depend

