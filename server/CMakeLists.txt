cmake_minimum_required(VERSION 3.20)
project(PrimordialServer LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES source/Main.cpp ../shared/events/Event.h ../shared/utility/Utility.h
        ../shared/events/EventSystem.cpp
        ../shared/events/EventSystem.h source/Server.cpp source/Server.h ../shared/utility/Settings.cpp ../shared/utility/Settings.h ../shared/utility/Logger.cpp ../shared/utility/Logger.h ../shared/utility/Utility.cpp ../shared/utility/SystemTimer.h ../shared/ecs/components/TransformComponent.h ../shared/gamestate/State.h ../shared/ecs/components/SpriteComponent.h ../shared/ecs/systems/System.h)

include_directories(${CMAKE_SOURCE_DIR}/libraries/glm)
include_directories(${CMAKE_SOURCE_DIR}/shared)
include_directories(${CMAKE_SOURCE_DIR}/server/source/)

#Specific platform only includes and files
if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/windows)
    include_directories(${CMAKE_SOURCE_DIR}/server/source/platform/windows)
    SET(SOURCE_FILES ${SOURCE_FILES} ../shared/platform/windows/SystemTimer.cpp)

elseif(APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/macos)
    include_directories(${CMAKE_SOURCE_DIR}/server/source/platform/macos)
    SET(SOURCE_FILES ${SOURCE_FILES} ../shared/platform/macos/SystemTimer.cpp)

elseif(UNIX AND NOT APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/linux)
    include_directories(${CMAKE_SOURCE_DIR}/server/source/platform/linux)
    SET(SOURCE_FILES ${SOURCE_FILES} ../shared/platform/linux/SystemTimer.cpp)

endif()

add_executable(PrimordialServer ${SOURCE_FILES})
install(TARGETS PrimordialServer RUNTIME)