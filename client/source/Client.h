#ifndef PRIMORDIAL_CLIENT_H
#define PRIMORDIAL_CLIENT_H


#include "Window.h"

class Client {
public:
    Client() = default;
    ~Client() = default;
    bool Initialize();
    void Start();

private:
    Window* window;
};


#endif
