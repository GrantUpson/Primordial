#include "../PlatformDetection.h"
#include "Game.h"

int main(int argc, char *argv[]) {
    Game* game = new Game();

    if(game->Initialize()) {
        game->Start();
    }

    delete game;

    return 0;
}
