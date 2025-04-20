cmake_minimum_required( VERSION 3.15 )

project(test_sorting_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

find_package(GTest REQUIRED)

add_subdirectory(lib)

add_executable(test_sorting_algorithms test_sorting_algorithms.cpp)
target_include_directories(test_sorting_algorithms PRIVATE lib)
target_link_libraries(test_sorting_algorithms sort_helper GTest::gtest_main)
