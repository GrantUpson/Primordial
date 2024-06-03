#include "client.h"
#include "utility/logger.h"


int main(int argc, char *argv[]) {
    Client client;
    ClientStatus result = client.Initialize();

    if(result != ClientStatus::Initialized) {
        Logger::Log("Client failed to initialize with error code: " + std::to_string(result));
        return result;
    } else {
        client.Run();
        client.Shutdown();
    }

    return EXIT_SUCCESS;
}
