#include "Client.h"

int main(int argc, char *argv[]) {
    Client* game = new Client();

    if(game->Initialize()) {
        game->Start();
    }

    delete game;
    return 0;
}
