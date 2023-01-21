#include "Client.h"
#include <windows.h>
#include <iostream>
#include <filesystem>


bool Client::Initialize() {
    window = new Window(new WindowData());
    isRunning = true;
    return true;
}

void Client::Run() {
    std::string temp;

    while(isRunning) {
        //glClear( GL_COLOR_BUFFER_BIT );

        // Draw nothing, see you in tutorial 2 !

        // Swap buffers
        glfwSwapBuffers(window->GetWindow());
        glfwPollEvents();

        if(glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE ) == GLFW_PRESS) {
            isRunning = false;
        }
    }
}


void Client::Shutdown() {
    window->Close();
}


bool Client::StartServer() {
    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInfo;
    SECURITY_ATTRIBUTES securityAttributes;

    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    ZeroMemory(&processInfo, sizeof(processInfo));
    ZeroMemory(&securityAttributes, sizeof(securityAttributes));

    std::filesystem::path cwd = std::filesystem::current_path();
    cwd.append("PrimordialServer.exe");
    std::string serverName = cwd.string();

    //debugging
    std::cout << serverName;

    if(CreateProcess(serverName.c_str(), nullptr, nullptr,
                     nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr, nullptr,
                     &startupInfo, &processInfo)) {

    } else {
        std::cout << "Failed Launch";
    }


    std::string temp;
    std::cin >> temp;
    std::cout << temp;

    TerminateProcess(processInfo.hProcess, 0);
    return true;
}
