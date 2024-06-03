#include <iostream>
#include "gamestate/splash_screen_state.h"
#include "gamestate/game_state.h"
#include "gamestate/title_screen_state.h"

void SplashScreenState::OnEnter() {
    std::cout << "Enter Splash Screen\n";
}


void SplashScreenState::OnExit() {
    std::cout << "Exit Splash Screen\n";
}


void SplashScreenState::Update() {
    currentDuration++;

    if(currentDuration >= DURATION_LENGTH) {
        GameState::SetCurrentGameState(new TitleScreenState);
    }
}
