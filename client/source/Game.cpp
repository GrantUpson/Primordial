#include "Game.h"
#include "utility/Logger.h"
#include "ServerLauncher.h"
#include <iostream>
#include <filesystem>


bool Game::Initialize() {
    isRunning = true;
    gameSettings = new Settings();

    if(!gameSettings->Load(std::filesystem::current_path().string() + "/Data/Settings.configuration")) {
        Logger::Log("Client - Could not load settings file.");
        return false;
    }

    auto settings = gameSettings->GetSettings();

    window = new Window(new WindowData(
            "Primordial",
            static_cast<bool>(std::stoi(settings.at("WindowedModeEnabled"))),
            static_cast<uint32>(std::stoul(settings.at("ResolutionWidth"))),
            static_cast<uint32>(std::stoul(settings.at("ResolutionHeight"))),
            static_cast<bool>(std::stoi(settings.at("VSyncEnabled")))));

    return true;
}

void Game::Run() {

    Logger::Log("Client - Before Server Launch");
    ServerLauncher::StartServer();
    Logger::Log("Client - After Server Launch");

    while(isRunning) {
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

