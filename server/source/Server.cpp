#include <string>
#include <iostream>
#include "Server.h"

bool Server::Initialize() {
    return true;
    //TODO Setup initial server variables from config file
}


void Server::Run() {
    //For testing it runs.
    std::string temp;
    std::cin >> temp;
    std::cout << temp;
}


void Server::Shutdown() {

}
