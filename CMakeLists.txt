cmake_minimum_required(VERSION 3.7)
project(primes)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

add_definitions("-std=c++1y -Wall -Wextra -pedantic")
add_definitions("-Weffc++ -Wnon-virtual-dtor -Wshadow")

file(DOWNLOAD "https://github.com/catchorg/Catch2/releases/download/v2.0.1/catch.hpp"
              ${CMAKE_BINARY_DIR}/includes/catch/catch.hpp)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/includes)
include_directories(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/includes/catch)

configure_file("src/primes.txt" ${CMAKE_BINARY_DIR} COPYONLY)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx)
add_executable(${PROJECT_NAME} ${SOURCES})
