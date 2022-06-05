cmake_minimum_required(VERSION 2.4)

# This doenst do anything
# SET(CMAKE_C_COMPILER "/c/qp/qtools/mingw32/bin/gcc")
# SET(CMAKE_CXX_COMPILER "/c/qp/qtools/mingw32/bin/gcc")

project(MinDifficultyJobSchedule)

set(SOURCE main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})