#include "server.h"
#include "utility/logger.h"

int main(int argc, char *argv[]) {
    Server server;
    ServerStatus result = server.Initialize();

    if(result != ServerStatus::Initialized) {
        Logger::Log(ServerStatusToString(result));
    } else {
        server.Run();
        server.Shutdown();
    }

    return 0;
}