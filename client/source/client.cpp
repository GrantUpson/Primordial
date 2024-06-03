#include "client.h"
#include "utility/localization.h"
#include "utility/system_timer.h"
#include "gamestate/game_state.h"
#include "gamestate/splash_screen_state.h"



ClientStatus Client::Initialize() {
    isRunning = true;

    /*
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
    */

    window = new Window(new WindowData(
            Localization::GetString("Title"),
            true,
            1920,
            1080,
            true));


    GameState::Initialize(new SplashScreenState);

    return Initialized;
}


void Client::Run() {
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

            nextGameUpdate += SKIP_TICKS;
            loops++;
            temp++;
        }

        interpolation = float(SystemTimer::GetTickCountSinceInitialization() +  - nextGameUpdate) / float();
        Render(interpolation);
    }
}


void Client::Shutdown() {
    window->Close();
    //TODO Save game settings
}


void Client::ProcessInput() {
    glfwPollEvents();

    if(glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE ) == GLFW_PRESS) {
        isRunning = false;
    }
}


void Client::ProcessEvents() {

}


void Client::Update() {

}


void Client::Render(float interpolation) {

}