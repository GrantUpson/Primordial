#ifndef INDARKESTNIGHT_GAME_H
#define INDARKESTNIGHT_GAME_H


#include "Window.h"

class Game {
public:
    Game() = default;
    ~Game() = default;
    bool Initialize();
    void Start();

private:
    Window* window;
};


#endif
