#ifndef PRIMORDIAL_GAME_H
#define PRIMORDIAL_GAME_H


#include "Window.h"
#include "utility/Settings.h"

class Game {
public:
    Game() = default;
    ~Game() = default;

    bool Initialize();
    void Run();
    void Shutdown();

    bool StartServer();

private:
    bool isRunning;
    Settings* configuration;
    Window* window;
};


#endif
