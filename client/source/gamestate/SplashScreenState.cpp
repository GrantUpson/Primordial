#include <iostream>
#include "SplashScreenState.h"
#include "gamestate/GameState.h"
#include "TitleScreenState.h"

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
