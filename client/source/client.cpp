#include <print>
#include "client.h"
#include "utility/localization.h"
#include "utility/system_timer.h"
#include "gamestate/game_state.h"
#include "gamestate/splash_screen_state.h"
#include "utility/settings.h"


ClientStatus Client::Initialize() {
    isRunning = true;

    ClientStatus result = Settings::LoadSettings();
    if(result != Initialized) {
        return result;
    }

    result = Localization::LoadLanguage(Settings::gameplay.language);
    if(result != Initialized) {
        return result;
    }

    window = new Window(new WindowData(
            Localization::GetString("Title"),
            Settings::graphics.windowedMode,
            Settings::graphics.resolutionWidth,
            Settings::graphics.resolutionHeight,
            Settings::graphics.vSync));

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
    Settings::SaveSettings();
    window->Close();
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