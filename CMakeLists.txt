cmake_minimum_required(VERSION 3.17)
project(CS170_Project_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(Part2, Part2/header)

add_executable(CS170_Project_2
        Part2/mainCode.cpp )
       
