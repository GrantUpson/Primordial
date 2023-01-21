#ifndef PRIMORDIAL_SERVER_H
#define PRIMORDIAL_SERVER_H


class Server {
public:
    Server() = default;
    ~Server() = default;

    bool Initialize();
    void Run();
    void Shutdown();
};


#endif
