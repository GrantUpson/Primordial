#include "Game.h"
#include "utility/Logger.h"
#include "ServerLauncher.h"
#include "utility/Localization.h"
#include <filesystem>
#include <iostream>
#include "SystemTimer.h"
#include "ecs/components/TransformComponent.h"


bool Game::Initialize() {
    isRunning = true;

    if(!Settings::Load(std::filesystem::current_path().string() + "/Data/Settings.configuration")) { //TODO get path string elsewhere?
        Logger::Log("Client - Could not load settings file.");
        return false;
    }

    if(!Localization::LoadLanguage(static_cast<Languages>(std::stoi(Settings::GetSetting("Language"))))) {
        Logger::Log("Client - Could not load language file.");
        return false;
    }

    window = new Window(new WindowData(
            Localization::GetString("Title"),
            static_cast<bool>(std::stoi(Settings::GetSetting("WindowedModeEnabled"))),
            static_cast<uint32>(std::stoul(Settings::GetSetting("ResolutionWidth"))),
            static_cast<uint32>(std::stoul(Settings::GetSetting("ResolutionHeight"))),
            static_cast<bool>(std::stoi(Settings::GetSetting("VSyncEnabled")))));

    //temp
    for(auto i = 0u; i < 10u; ++i) {
        const auto entity = registry.create();
        registry.emplace<TransformComponent>(entity, Vector2(1.0, 1.0), Vector2(1.0, 1.0), 1.0f);
    }

    return true;
}

void Game::Run() {
    if(!ServerLauncher::StartServer()) {
        Logger::Log("Client - Server launch failed");
    }

    const uint32 UPDATES_PER_SECOND = 25;
    const uint32 SKIP_TICKS = 1000 / UPDATES_PER_SECOND;
    const uint32 MAX_FRAME_SKIP = 5;

    uint64 nextGameUpdate = SystemTimer::GetTickCountSinceInitialization();
    uint32 loops;
    float interpolation;

    while(isRunning) {
        loops = 0;

        while(SystemTimer::GetTickCountSinceInitialization() > nextGameUpdate && loops < MAX_FRAME_SKIP) {
            ProcessEvents();
            ProcessInput();
            Update();

            nextGameUpdate += SKIP_TICKS;
            loops++;
        }

        interpolation = float(SystemTimer::GetTickCountSinceInitialization() +  - nextGameUpdate) / float();
        // view_position = position + (speed * interpolation) for updating rendered things between frames
        Render(interpolation);
    }
}


void Game::Shutdown() {
    window->Close();
    Settings::SaveToFile(std::filesystem::current_path().string() + "/Data/Settings.configuration"); //TODO get path string elsewhere?
}


void Game::ProcessInput() {
    glfwPollEvents();

    if(glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE ) == GLFW_PRESS) {
        isRunning = false;
    }
}


void Game::ProcessEvents() {

}


void Game::Update() {
    //How some systems could be implemented?
    auto view = registry.view<TransformComponent>();

    for(auto [entity, transform]: view.each()) {
        transform.position.x += 0.1;
        transform.position.y += 0.1;
    }
}


void Game::Render(float interpolation) {
    glfwSwapBuffers(window->GetWindow());
}

