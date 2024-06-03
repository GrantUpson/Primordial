#include <string>
#include <iostream>
#include <print>
#include "server.h"


ServerStatus Server::Initialize() {
    return ServerStatus::Initialized;
}


void Server::Run() {
    //Testing it runs.
    std::string temp;
    std::cin >> temp;
    std::print("Output {}", temp);
}


void Server::Shutdown() {
    //TODO shut down server in reverse order
}
