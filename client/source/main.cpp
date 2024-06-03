#include "client.h"
#include "utility/logger.h"


int main(int argc, char *argv[]) {
    Client client;
    ClientStatus result = client.Initialize();

    if(result != ClientStatus::Initialized) {
        Logger::Log(ClientStatusToString(result));
        return result;
    } else {
        client.Run();
        client.Shutdown();
    }

    return EXIT_SUCCESS;
}
