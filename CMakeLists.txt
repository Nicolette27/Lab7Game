cmake_minimum_required(VERSION 3.26)
project(Lab7Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab7Game main.cpp
        Game.cpp
        Ghost.cpp
        Player.cpp
        Room.cpp
)