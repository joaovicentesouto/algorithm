cmake_minimum_required (VERSION 2.6)
project (graph_algorithms)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.59 REQUIRED)
find_package(OpenMP)

if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lemon")
endif()

add_library(GraphAlgorithms graph_algorithms.cpp)
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

enable_testing()
 
# add the executable
add_executable(main main.cpp)
target_link_libraries (main GraphAlgorithms)