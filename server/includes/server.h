#ifndef PRIMORDIAL_SERVER_H
#define PRIMORDIAL_SERVER_H

#include "types.h"
#include "server_status.h"


class Server {
public:
    Server() = default;
    ~Server() = default;

    ServerStatus Initialize();
    void Run();
    void Shutdown();

private:

};




#endif
