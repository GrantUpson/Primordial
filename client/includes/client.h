#ifndef PRIMORDIAL_CLIENT_H
#define PRIMORDIAL_CLIENT_H


#include "window.h"

enum ClientStatus : uint8 {
    Initialized = 0
};


class Client {
public:
    Client() = default;
    ~Client() = default;

    ClientStatus Initialize();
    void Run();
    void Shutdown();

    void ProcessInput();
    void ProcessEvents();
    void Update();
    void Render(float interpolation);

private:
    bool isRunning {};
    Window* window {};
};


#endif
