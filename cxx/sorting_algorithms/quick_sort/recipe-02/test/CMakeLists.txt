cmake_minimum_required( VERSION 3.15 )

project(test_median3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

find_package(GTest REQUIRED)

add_executable(test_median3 test_median3.cpp)
target_link_libraries(test_median3 GTest::gtest_main)
