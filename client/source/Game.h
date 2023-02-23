#ifndef PRIMORDIAL_GAME_H
#define PRIMORDIAL_GAME_H


#include "Window.h"
#include "utility/Settings.h"
#include "ecs/entt/entt.hpp"
#include "events/EventSystem.h"
#include "ecs/systems/TestSystem.h"
#include "ecs/systems/SpriteRenderingSystem.h"

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
    EventSystem* eventBus {};
    TestSystem* test {};
    SpriteRenderingSystem* test2 {};
};


#endif
