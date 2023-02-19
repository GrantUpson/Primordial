#include "Game.h"
#include "utility/Logger.h"
#include "utility/Localization.h"
#include <filesystem>
#include <iostream>
#include "utility/SystemTimer.h"
#include "gamestate/GameState.h"
#include "gamestate/SplashScreenState.h"
#include "rendering/Renderer2D.h"
#include "RenderCommand.h"
#include "ecs/systems/TestSystem.h"


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

    Renderer2D::Initialize();
    GameState::Initialize(new SplashScreenState);

    //TEMP
    eventBus = new EventBus();
    test = new TestSystem();
    test->SubscribeToEvents(*eventBus);


    //->SubscribeToEvent<CollisionEvent>(this, &DamageSystem::OnCollision);

    return true;
}


void Game::Run() {
    const uint32 UPDATES_PER_SECOND = 30;
    const uint32 SKIP_TICKS = 1000 / UPDATES_PER_SECOND;
    const uint32 MAX_FRAME_SKIP = 5;
    uint32 temp = 0;

    uint64 nextGameUpdate = SystemTimer::GetTickCountSinceInitialization();
    uint32 loops;
    float interpolation;

    while(isRunning) {
        loops = 0;

        while(SystemTimer::GetTickCountSinceInitialization() > nextGameUpdate && loops < MAX_FRAME_SKIP) {
            ProcessEvents();
            ProcessInput();
            GameState::GetCurrentGameState()->Update();
            eventBus->DispatchEvent<ResolutionChangedEvent>(1920, 1080);
            nextGameUpdate += SKIP_TICKS;
            loops++;
            temp++;

            if(temp >= 400) {
                std::cout << "Unsubscribe";
                //ResolutionChangedEvent event(0, 0);
                //Logger::Log("Change it");
            }
        }

        interpolation = float(SystemTimer::GetTickCountSinceInitialization() +  - nextGameUpdate) / float();
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

}


void Game::Render(float interpolation) {
    //TODO different rendering systems or one big rendering system called in here that uses the Renderer2D
    Renderer2D::BeginScene();
    RenderCommand::SwapBuffers(window->GetWindow());
}


/*
    CREATING ENTITIES WITH SPECIFIC COMPONENTS
    for(auto i = 0u; i < 10u; ++i) {
        const auto entity = registry.create();
        registry.emplace<TransformComponent>(entity, Vector2(1.0, 1.0), Vector2(1.0, 1.0), 1.0f);
    }

 */