cmake_minimum_required(VERSION 3.10)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Project Name and Version
project(Matrix LANGUAGES CXX VERSION 1.0)

# Enable Testing and Add Testing Module
enable_testing()
add_subdirectory(test)

# Configure Includes
include_directories(./include)