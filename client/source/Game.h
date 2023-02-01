#ifndef PRIMORDIAL_GAME_H
#define PRIMORDIAL_GAME_H


#include "Window.h"
#include "utility/Settings.h"
#include "ecs/entt/entt.hpp"

class Game {
public:
    Game() = default;
    ~Game() = default;

    bool Initialize();
    void Run();
    void Shutdown();

    void ProcessInput();
    void ProcessEvents();
    void Update();
    void Render(float interpolation);

private:
    bool isRunning {};
    Window* window {};
    entt::registry registry {};
};


#endif
