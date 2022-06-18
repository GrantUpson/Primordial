cmake_minimum_required(VERSION 3.20)
project(InDarkestNight LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES source/Main.cpp)

add_executable(InDarkestNight MACOSX_BUNDLE ${SOURCE_FILES})
