#ifndef PRIMORDIAL_GAMESTATE_H
#define PRIMORDIAL_GAMESTATE_H


#include <stack>
#include "State.h"

class GameState {
public:
    ~GameState();
    GameState() = default;

    static void Initialize(State* state);
    static State* GetCurrentGameState();
    static void SetCurrentGameState(State* newState);
    static void ReplaceCurrentGameState(State* newState);
    static void RemoveCurrentGameState();

private:
    inline static std::stack<State*> currentGameState {};
};


#endif
