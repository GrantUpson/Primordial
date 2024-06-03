cmake_minimum_required(VERSION 3.28)
project(Primordial LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/libraries/glfw-3.3.7)

include_directories(${PROJECT_SOURCE_DIR}/includes)
include_directories(${CMAKE_SOURCE_DIR}/shared/includes)
include_directories(SYSTEM ${CMAKE_SOURCE_DIR}/shared/libraries)
include_directories(${PROJECT_SOURCE_DIR}/libraries/glad/include/)
include_directories(${PROJECT_SOURCE_DIR}/libraries/glfw-3.3.7/include/GLFW)

set(SOURCE_FILES
        source/main.cpp
        source/client.cpp
        source/gamestate/game_state.cpp
        source/gamestate/splash_screen_state.cpp
        source/gamestate/title_screen_state.cpp
        source/gamestate/connected_state.cpp
        source/utility/localization.cpp
        ../shared/source/utility/logger.cpp
        libraries/glad/src/glad.c
        ../shared/libraries/simple_ini/convert_utf.c
        source/utility/settings.cpp
        source/client_status.cpp
)

set(HEADER_FILES
        includes/client.h
        includes/gamestate/state.h
        includes/gamestate/splash_screen_state.h
        includes/gamestate/connected_state.h
        includes/gamestate/title_screen_state.h
        includes/gamestate/game_state.h
        includes/input/input.h
        includes/input/input_codes.h
        includes/utility/localization.h
        includes/utility/server_launcher.h
        ../shared/includes/types.h
        ../shared/includes/utility/logger.h
        ../shared/includes/utility/system_timer.h
        ../shared/libraries/simple_ini/simple_ini.h
        ../shared/libraries/simple_ini/convert_utf.h
        includes/client_status.h
)

#Specific platform only includes and files
if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/windows)
    include_directories(${PROJECT_SOURCE_DIR}/includes/platform/windows)
    include_directories(${PROJECT_SOURCE_DIR}/includes/rendering/opengl)

    SET(SOURCE_FILES ${SOURCE_FILES}
            ../shared/source/platform/windows/system_timer.cpp
            source/platform/windows/windows_server_launcher.cpp
            source/platform/windows/windows_window.cpp
            source/rendering/opengl/index_buffer.cpp
            source/rendering/opengl/shader.cpp
            source/rendering/opengl/vertex_array.cpp
            source/rendering/opengl/vertex_buffer.cpp
    )

    SET(HEADER_FILES ${HEADER_FILES}
            includes/platform/windows/window.h
            includes/rendering/opengl/vertex_array.h
            includes/rendering/opengl/shader.h
            includes/rendering/opengl/index_buffer.h
            includes/rendering/opengl/vertex_buffer.h
    )

    #Stops the command prompt from appearing in Windows OS
    set_target_properties(Primordial PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")


elseif(APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/macos)
    include_directories(${PROJECT_SOURCE_DIR}/includes/platform/macos)
    include_directories(${PROJECT_SOURCE_DIR}/includes/rendering/opengl)

    SET(SOURCE_FILES ${SOURCE_FILES}
            ../shared/source/platform/macos/system_timer.cpp
            source/platform/macos/macos_server_launcher.cpp
            source/platform/macos/macos_window.cpp
            source/rendering/opengl/index_buffer.cpp
            source/rendering/opengl/shader.cpp
            source/rendering/opengl/vertex_array.cpp
            source/rendering/opengl/vertex_buffer.cpp
    )

    SET(HEADER_FILES ${HEADER_FILES}
            includes/platform/macos/window.h
            includes/rendering/opengl/vertex_array.h
            includes/rendering/opengl/shader.h
            includes/rendering/opengl/index_buffer.h
            includes/rendering/opengl/vertex_buffer.h
    )


elseif(UNIX AND NOT APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/linux)
    include_directories(${PROJECT_SOURCE_DIR}/includes/platform/linux)
    include_directories(${PROJECT_SOURCE_DIR}/includes/rendering/opengl)

    SET(SOURCE_FILES ${SOURCE_FILES}
            ../shared/source/platform/linux/system_timer.cpp
            source/platform/linux/linux_server_launcher.cpp
            source/platform/linux/linux_window.cpp
            source/rendering/opengl/index_buffer.cpp
            source/rendering/opengl/shader.cpp
            source/rendering/opengl/vertex_array.cpp
            source/rendering/opengl/vertex_buffer.cpp
    )

    SET(HEADER_FILES ${HEADER_FILES}
            includes/platform/linux/window.h
            includes/rendering/opengl/vertex_array.h
            includes/rendering/opengl/shader.h
            includes/rendering/opengl/index_buffer.h
            includes/rendering/opengl/vertex_buffer.h
            includes/utility/settings.h
    )


endif()

add_executable(Primordial ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(Primordial LINK_PUBLIC glfw)
install(TARGETS Primordial RUNTIME)