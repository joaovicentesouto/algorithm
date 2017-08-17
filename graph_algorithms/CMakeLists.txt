cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME "graph_algorithms")
project (PROJECT_NAME)

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

#add_library(GraphAlgorithms ./src/graph_algorithms.cpp ./src/graph_algorithms.h)

set(GRAPH_ALGORITHMS_INCLUDE_DIR
	${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/src/
	${PROJECT_SOURCE_DIR}/test/
)

include_directories(GRAPH_ALGORITHMS_INCLUDE_DIR)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()

add_test (NAME MyTest COMMAND Test)