cmake_minimum_required(VERSION 3.20)
project(Primordial LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES source/Main.cpp ../shared/events/Event.h ../shared/utility/Utility.h
        source/Game.cpp source/Game.h ../shared/platform/PlatformDetection.h ../shared/events/EventManagementSystem.cpp
        ../shared/events/EventManagementSystem.h ../shared/utility/Settings.cpp ../shared/utility/Settings.h ../shared/utility/Logger.cpp ../shared/utility/Logger.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(libraries/glm)
include_directories(libraries/glfw-3.3.7/include/GLFW)
include_directories(${CMAKE_SOURCE_DIR}/shared)
add_subdirectory(libraries/glfw-3.3.7)

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

add_executable(Primordial ${SOURCE_FILES})

#Stops the command prompt from appearing in windows
if(WIN32)
    set_target_properties(Primordial PROPERTIES
            LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")
endif()

target_link_libraries(Primordial LINK_PUBLIC glfw)
install(TARGETS Primordial RUNTIME)