#include <cstdlib>
#include "Server.h"

int main(int argc, char *argv[]) {
    Server* server = new Server();

    if(server->Initialize()) {
        server->Run();
        server->Shutdown();
    } else {
        //TODO Error to server console
    }

    delete server;
    return EXIT_SUCCESS;
}