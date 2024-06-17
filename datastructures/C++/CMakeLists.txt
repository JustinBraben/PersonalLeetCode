cmake_minimum_required(VERSION 3.21)
project(PersonalLeetCode)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

# Add third-party libraries
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

set(BENCHMARK_ENABLE_TESTING NO)
FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.4
)
FetchContent_MakeAvailable(googlebenchmark)

# Helper function to add problem directories
function(add_problem problem_name)    
    # Ensure the problem name starts with three numbers
    if (problem_name MATCHES "^[0-9][0-9][0-9]-.*$")
        # Locate the source files
        file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${problem_name}/*.cpp)
        set(SOLUTION_SOURCES ${PROJECT_SOURCE_DIR}/${problem_name}/${problem_name}.cpp)
        add_library(${problem_name} STATIC ${SOLUTION_SOURCES})
        foreach(source IN LISTS SOURCES)
            get_filename_component(source_name ${source} NAME_WE)
            if (source_name MATCHES ".*-test$")
                message(STATUS "Adding test for ${problem_name}")
                set(TEST_NAME "${problem_name}_test")
                add_executable(${TEST_NAME} ${source})
                target_compile_features(${TEST_NAME} PUBLIC cxx_std_20)
                target_link_libraries(${TEST_NAME} PRIVATE ${problem_name} GTest::gtest_main)
                gtest_discover_tests(${TEST_NAME})
            # else()
            #     message(STATUS "Adding executable for ${source_name}")
            #     add_executable(${problem_name} ${source})
            endif()
        endforeach()
    else()
        message(WARNING "Skipping ${problem_name}: problem name must start with three numbers.")
    endif()
endfunction()

file(GLOB problem_dirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(problem_dir IN LISTS problem_dirs)
    add_problem(${problem_dir})
endforeach()