cmake_minimum_required(VERSION 3.20)
project(InDarkestNight LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES source/client/Main.cpp source/events/Event.h source/Utility.h
        source/client/Game.cpp source/client/Game.h source/PlatformDetection.h source/events/EventManagementSystem.cpp
        source/events/EventManagementSystem.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(${PROJECT_SOURCE_DIR}/libraries/glm)
include_directories(${PROJECT_SOURCE_DIR}/libraries/glfw-3.3.7/include/GLFW)
include_directories(${PROJECT_SOURCE_DIR}/source/client)
add_subdirectory(${PROJECT_SOURCE_DIR}/libraries/glfw-3.3.7)

if(WIN32)
    include_directories(${PROJECT_SOURCE_DIR}/source/platform/windows)
    SET(SOURCE_FILES ${SOURCE_FILES}
            source/platform/windows/WindowsWindow.cpp
            source/platform/windows/Window.h)
elseif(APPLE)
    include_directories(${PROJECT_SOURCE_DIR}/source/platform/macos)
    SET(SOURCE_FILES ${SOURCE_FILES}
            source/platform/macos/MacOSWindow.cpp
            source/platform/macos/Window.h)
elseif(UNIX AND NOT APPLE)
    include_directories(${PROJECT_SOURCE_DIR}/source/platform/linux)
    SET(SOURCE_FILES ${SOURCE_FILES}
            source/platform/linux/LinuxWindow.cpp
            source/platform/linux/Window.h)
endif()

add_executable(InDarkestNight MACOSX_BUNDLE ${SOURCE_FILES})

target_link_libraries(InDarkestNight glfw)
