cmake_minimum_required(VERSION 3.20)
project(PrimordialServer LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES source/Main.cpp ../shared/events/Event.h ../shared/utility/Utility.h
        ../shared/platform/PlatformDetection.h ../shared/events/EventManagementSystem.cpp
        ../shared/events/EventManagementSystem.h source/Server.cpp source/Server.h ../shared/utility/Settings.cpp ../shared/utility/Settings.h ../shared/utility/Logger.cpp ../shared/utility/Logger.h ../shared/utility/Utility.cpp ../shared/utility/Utility.h ../shared/ecs/components/TransformComponent.h)

include_directories(${CMAKE_SOURCE_DIR}/libraries/glm)
include_directories(${CMAKE_SOURCE_DIR}/shared)

if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/windows)
    include_directories(${CMAKE_SOURCE_DIR}/server/source/platform/windows)
    SET(SOURCE_FILES ${SOURCE_FILES} ../shared/platform/windows/SystemTimer.cpp ../shared/platform/windows/SystemTimer.h)

elseif(APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/macos)
    include_directories(${CMAKE_SOURCE_DIR}/server/source/platform/macos)
    SET(SOURCE_FILES ${SOURCE_FILES} ../shared/platform/macos/SystemTimer.cpp ../shared/platform/macos/SystemTimer.h)

elseif(UNIX AND NOT APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/linux)
    include_directories(${CMAKE_SOURCE_DIR}/server/source/platform/linux)
    SET(SOURCE_FILES ${SOURCE_FILES} ../shared/platform/linux/SystemTimer.cpp ../shared/platform/linux/SystemTimer.h)

endif()

add_executable(PrimordialServer ${SOURCE_FILES})
install(TARGETS PrimordialServer RUNTIME)