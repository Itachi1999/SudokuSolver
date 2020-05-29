cmake_minimum_required(VERSION 3.5)


project(SudokuSolver)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include_directories(include)
file(GLOB SOURCES "src/*.c")

add_executable(sudoku ${SOURCES})