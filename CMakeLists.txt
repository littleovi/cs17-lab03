cmake_minimum_required(VERSION 3.0)
project(lab01)
set(CMAKE_EXE_LINKER_FLAGS -static)
set(SOURCE_FILES main.cpp tempreture.cpp)
add_executable(lab01 ${SOURCE_FILES})
add_executable(test_input test.cpp tempreture.cpp)

enable_testing()
add_test(NAME test_input COMMAND test_input)
