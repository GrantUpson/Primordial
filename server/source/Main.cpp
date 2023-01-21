#include <cstdlib>
#include "Server.h"
#include "utility/Logger.h"


int main(int argc, char *argv[]) {
    Server* server = new Server();

    if(server->Initialize()) {
        server->Run();
        server->Shutdown();
    } else {
        Logger::Log("Server - Failed to initialize the server.");
    }

    delete server;
    return EXIT_SUCCESS;
}