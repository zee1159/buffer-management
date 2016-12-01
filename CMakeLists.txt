cmake_minimum_required(VERSION 3.6)
project(buffer_management)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    caching_strategies.cpp
    prefetcher.cpp
    prefetcher.h)

add_executable(buffer_management ${SOURCE_FILES})