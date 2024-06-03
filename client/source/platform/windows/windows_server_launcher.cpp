#include <windows.h>
#include <string>
#include <filesystem>
#include "utility/logger.h"
#include "utility/server_launcher.h"


bool StartServer() {
    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInfo;
    SECURITY_ATTRIBUTES securityAttributes;

    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    ZeroMemory(&processInfo, sizeof(processInfo));
    ZeroMemory(&securityAttributes, sizeof(securityAttributes));

    std::string serverName = std::filesystem::current_path().string() + "\\PrimordialServer.exe";
    Logger::Log(serverName);


    if(CreateProcess(serverName.c_str(), nullptr, nullptr,
                     nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr, nullptr,
                     &startupInfo, &processInfo)) {

    } else {
        Logger::Log("Client - Failed to create server process.");
        return false;
    }

    return true;
    //TerminateProcess(processInfo.hProcess, 0);
    //TODO terminating must be sent as a message to server from client
}