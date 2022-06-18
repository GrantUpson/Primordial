cmake_minimum_required(VERSION 3.20)
project(InDarkestNight LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES source/client/Main.cpp source/client/Window.cpp source/client/Window.h source/events/Event.h source/utility.h source/platform/windows/WindowsWindow.cpp source/platform/windows/WindowsWindow.h source/platform/osx/OSXWindow.cpp source/platform/osx/OSXWindow.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(${PROJECT_SOURCE_DIR}/libraries/glm)
add_subdirectory(${PROJECT_SOURCE_DIR}/libraries/glfw-3.3.7)

add_executable(InDarkestNight MACOSX_BUNDLE ${SOURCE_FILES})
target_link_libraries(InDarkestNight glfw)
