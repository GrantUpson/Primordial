cmake_minimum_required(VERSION 3.20)
project(Primordial LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES source/Main.cpp ../shared/events/Event.h ../shared/utility/Utility.h
        source/Game.cpp source/Game.h ../shared/events/EventSystem.cpp
        ../shared/events/EventSystem.h ../shared/utility/Settings.cpp ../shared/utility/Settings.h ../shared/utility/Logger.cpp ../shared/utility/Logger.h source/utility/Localization.cpp source/utility/Localization.h ../shared/utility/Utility.cpp ../shared/utility/SystemTimer.h source/utility/ServerLauncher.h ../shared/ecs/components/TransformComponent.h ../shared/gamestate/GameState.cpp ../shared/gamestate/GameState.h ../shared/gamestate/State.h source/gamestate/SplashScreenState.cpp source/gamestate/SplashScreenState.h source/gamestate/TitleScreenState.cpp source/gamestate/TitleScreenState.h source/gamestate/PlayingState.cpp source/gamestate/PlayingState.h source/gamestate/LobbyState.cpp source/gamestate/LobbyState.h ../shared/ecs/components/SpriteComponent.h libraries/glad/src/glad.c ../shared/ecs/systems/SpriteRenderingSystem.cpp ../shared/ecs/systems/SpriteRenderingSystem.h source/rendering/Renderer2D.cpp source/rendering/Renderer2D.h ../shared/ecs/components/CameraFocusComponent.h source/rendering/OrthographicCamera.cpp source/rendering/OrthographicCamera.h source/input/Input.h source/input/InputCodes.h ../shared/ecs/systems/TestSystem.cpp ../shared/ecs/systems/TestSystem.h ../shared/events/InputEvent.h ../shared/events/ApplicationEvent.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(libraries/glm)
include_directories(libraries/glad/include/)
include_directories(libraries/glfw-3.3.7/include/GLFW)
include_directories(${CMAKE_SOURCE_DIR}/client/source/)
include_directories(${CMAKE_SOURCE_DIR}/shared)
add_subdirectory(libraries/glfw-3.3.7)


#Specific platform only includes and files
if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/windows)
    include_directories(${CMAKE_SOURCE_DIR}/client/source/platform/windows)
    include_directories(${CMAKE_SOURCE_DIR}/client/source/rendering/opengl)
    SET(SOURCE_FILES ${SOURCE_FILES}
            source/platform/windows/WindowsWindow.cpp source/platform/windows/Window.h source/platform/windows/WindowsServerLauncher.cpp ../shared/platform/windows/SystemTimer.cpp source/rendering/opengl/Shader.cpp source/rendering/opengl/Shader.h source/rendering/opengl/VertexArray.cpp source/rendering/opengl/VertexArray.h source/rendering/opengl/Texture.cpp source/rendering/opengl/Texture.h ../shared/ecs/systems/System.h source/rendering/opengl/Buffer.cpp source/rendering/opengl/Buffer.h source/rendering/opengl/RenderCommand.cpp source/rendering/opengl/RenderCommand.h)

elseif(APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/macos)
    include_directories(${CMAKE_SOURCE_DIR}/client/source/platform/macos)
    #include_directories(${CMAKE_SOURCE_DIR}/client/source/rendering/metal) ONCE DONE UNCOMMENT THIS
    include_directories(${CMAKE_SOURCE_DIR}/client/source/rendering/opengl)
    SET(SOURCE_FILES ${SOURCE_FILES}
            source/platform/macos/MacOSWindow.cpp source/platform/macos/Window.h source/platform/macos/MacosServerLauncher.cpp ../shared/platform/macos/SystemTimer.cpp source/rendering/opengl/RenderCommand.cpp source/rendering/opengl/RenderCommand.h)

elseif(UNIX AND NOT APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/shared/platform/linux)
    include_directories(${CMAKE_SOURCE_DIR}/client/source/platform/linux)
    include_directories(${CMAKE_SOURCE_DIR}/client/source/rendering/opengl)
    SET(SOURCE_FILES ${SOURCE_FILES} source/platform/linux/LinuxWindow.cpp source/platform/linux/Window.h ../shared/platform/linux/SystemTimer.cpp source/platform/linux/LinuxServerLauncher.cpp source/rendering/opengl/RenderCommand.cpp source/rendering/opengl/RenderCommand.h)

endif()

add_executable(Primordial ${SOURCE_FILES})

#Stops the command prompt from appearing in windows
if(WIN32)
    #set_target_properties(Primordial PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")
endif()

target_link_libraries(Primordial LINK_PUBLIC glfw)
install(TARGETS Primordial RUNTIME)