#include "Game.h"
#include "utility/Logger.h"
#include <windows.h>
#include <iostream>
#include <filesystem>


bool Game::Initialize() {
    isRunning = true;
    configuration = new Settings();

    if(!configuration->Load(std::filesystem::current_path().string() + "\\Data\\Settings.configuration")) {
        Logger::Log("Could not load settings file.");
        return false;
    }

    auto settings = configuration->GetSettings();

    window = new Window(new WindowData(
            "Primordial",
            static_cast<bool>(std::stoi(settings.at("WindowedModeEnabled"))),
            static_cast<uint32>(std::stoul(settings.at("ResolutionWidth"))),
            static_cast<uint32>(std::stoul(settings.at("ResolutionHeight"))),
            static_cast<bool>(std::stoi(settings.at("VSyncEnabled")))));

    return true;
}

void Game::Run() {
    std::string temp;

    StartServer();

    while(isRunning) {
        //glClear( GL_COLOR_BUFFER_BIT );

        glfwSwapBuffers(window->GetWindow());
        glfwPollEvents();

        if(glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE ) == GLFW_PRESS) {
            isRunning = false;
        }
    }
}


void Game::Shutdown() {
    window->Close();
}


bool Game::StartServer() {
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
    return true;
}
