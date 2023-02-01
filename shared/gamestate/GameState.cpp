#include "GameState.h"


GameState::~GameState() {
    while(!currentGameState.empty()) {
        currentGameState.pop();
    }
}


void GameState::Initialize(State* newState) {
    currentGameState.push(newState);
}


State* GameState::GetCurrentGameState() {
    return currentGameState.top();
}


void GameState::SetCurrentGameState(State* newState) {
    currentGameState.top()->OnExit();
    currentGameState.push(newState);
    currentGameState.top()->OnEnter();
}


void GameState::ReplaceCurrentGameState(State* newState) {
    RemoveCurrentGameState();
    currentGameState.push(newState);
}


void GameState::RemoveCurrentGameState() {
    currentGameState.top()->OnExit();
    currentGameState.pop();
}





