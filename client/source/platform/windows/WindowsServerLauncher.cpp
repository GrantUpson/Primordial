#include <windows.h>

bool StartServer() {
    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInfo;
    SECURITY_ATTRIBUTES securityAttributes;

    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    ZeroMemory(&processInfo, sizeof(processInfo));
    ZeroMemory(&securityAttributes, sizeof(securityAttributes));

    std::string serverName = std::filesystem::current_path().string() + "\\Server\\PrimordialServer.exe";


    if(CreateProcess(serverName.c_str(), nullptr, nullptr,
                     nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr, nullptr,
                     &startupInfo, &processInfo)) {

    } else {
        Logger::Log("Client - Failed to create server process.");
    }


    //TerminateProcess(processInfo.hProcess, 0);
}