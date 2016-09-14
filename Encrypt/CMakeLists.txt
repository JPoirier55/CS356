cmake_minimum_required(VERSION 3.6)
project(Project1_356)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp FileManager.cpp FileManager.h Message.cpp Message.h Encryptor.cpp Encryptor.h)
add_executable(Project1_356 ${SOURCE_FILES})