cmake_minimum_required(VERSION 3.20)
project(Launcher LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES source/Main.cpp ../shared/events/Event.h ../shared/Utility.h
        source/Client.cpp source/Client.h ../shared/PlatformDetection.h ../shared/events/EventManagementSystem.cpp
        ../shared/events/EventManagementSystem.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(${CMAKE_SOURCE_DIR}/libraries/glm)
include_directories(${CMAKE_SOURCE_DIR}/libraries/glfw-3.3.7/include/GLFW)
include_directories(${CMAKE_SOURCE_DIR}/shared)

if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/windows)
    SET(SOURCE_FILES ${SOURCE_FILES}
            ../shared/platform/windows/WindowsWindow.cpp
            ../shared/platform/windows/Window.h)
elseif(APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/macos)
    SET(SOURCE_FILES ${SOURCE_FILES}
            ../shared/platform/macos/MacOSWindow.cpp
            ../shared/platform/macos/Window.h)
elseif(UNIX AND NOT APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/linux)
    SET(SOURCE_FILES ${SOURCE_FILES}
            ../shared/platform/linux/LinuxWindow.cpp
            ../shared/platform/linux/Window.h)
endif()

add_executable(Launcher ${SOURCE_FILES})
target_link_libraries(Launcher LINK_PUBLIC glfw)
install(TARGETS Launcher RUNTIME)