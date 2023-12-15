cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_ST&&ARD 14)

include_directories(include)

add_executable(MyProject src/main.cpp "include/" "presentation/source.cpp")