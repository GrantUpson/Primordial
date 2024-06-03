cmake_minimum_required(VERSION 3.28)
project(PrimordialServer LANGUAGES CXX VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 23)

include_directories(${PROJECT_SOURCE_DIR}/includes)
include_directories(${CMAKE_SOURCE_DIR}/shared/includes)
include_directories(SYSTEM ${CMAKE_SOURCE_DIR}/shared/libraries)

set(SOURCE_FILES
        source/main.cpp
        source/server.cpp
        source/server_status.cpp
        ../shared/source/utility/logger.cpp
)

set(HEADER_FILES
        includes/server.h
        includes/server_status.h
        ../shared/includes/types.h
        ../shared/includes/utility/logger.h
)


#Specific platform only includes and files
if(WIN32)
    include_directories(${PROJECT_SOURCE_DIR}/includes/platform/windows)
    include_directories(${CMAKE_SOURCE_DIR}/shared/includes/platform/windows)

    SET(SOURCE_FILES ${SOURCE_FILES}

    )

    SET(HEADER_FILES ${HEADER_FILES}

    )


elseif(APPLE)
    include_directories(${PROJECT_SOURCE_DIR}/includes/platform/macos)
    include_directories(${CMAKE_SOURCE_DIR}/shared/includes/platform/macos)

    SET(SOURCE_FILES ${SOURCE_FILES}

    )

    SET(HEADER_FILES ${HEADER_FILES}

    )


elseif(UNIX AND NOT APPLE)
    include_directories(${PROJECT_SOURCE_DIR}/includes/platform/linux)
    include_directories(${CMAKE_SOURCE_DIR}/shared/includes/platform/linux)

    SET(SOURCE_FILES ${SOURCE_FILES}

    )

    SET(HEADER_FILES ${HEADER_FILES}

    )


endif()

add_executable(PrimordialServer ${SOURCE_FILES} ${HEADER_FILES})
install(TARGETS PrimordialServer RUNTIME)