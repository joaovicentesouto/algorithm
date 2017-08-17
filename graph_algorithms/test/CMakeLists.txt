file(GLOB_RECURSE all_tests_CPP 
    "*.cpp"
)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE .)

add_executable(run_tests ${all_tests_CPP})
target_link_libraries(run_tests PUBLIC 
    Catch
)

#add_test(unit_tests UnitTests)
