#ifndef PRIMORDIAL_GAME_STATE_H
#define PRIMORDIAL_GAME_STATE_H

#include <stack>
#include "state.h"


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
