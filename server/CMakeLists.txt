cmake_minimum_required(VERSION 3.20)
project(PrimordialServer LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES source/Main.cpp ../shared/events/Event.h ../shared/utility/Utility.h
        ../shared/platform/PlatformDetection.h ../shared/events/EventManagementSystem.cpp
        ../shared/events/EventManagementSystem.h source/Server.cpp source/Server.h ../shared/utility/Settings.cpp ../shared/utility/Settings.h)

include_directories(${CMAKE_SOURCE_DIR}/libraries/glm)
include_directories(${CMAKE_SOURCE_DIR}/shared)

if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/windows)
    SET(SOURCE_FILES ${SOURCE_FILES})
            #../shared/platform/windows/Window.h)
elseif(APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/macos)
    SET(SOURCE_FILES ${SOURCE_FILES})
            #../shared/platform/macos/Window.h)
elseif(UNIX AND NOT APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/linux)
    SET(SOURCE_FILES ${SOURCE_FILES})
            #../shared/platform/linux/Window.h)
endif()

add_executable(PrimordialServer ${SOURCE_FILES})
install(TARGETS PrimordialServer RUNTIME)