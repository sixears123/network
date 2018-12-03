cmake_minimum_required(VERSION 3.12)
project(net)

set(CMAKE_CXX_STANDARD 14)

add_executable(net main.cpp Route.cpp Route.h Floyd.cpp Floyd.h File.cpp File.h Edge.cpp Edge.h outputm.cpp outputm.h)