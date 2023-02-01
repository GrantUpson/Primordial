#ifndef PRIMORDIAL_LOBBYSTATE_H
#define PRIMORDIAL_LOBBYSTATE_H


#include "gamestate/State.h"

class LobbyState : public State {
public:
    LobbyState() = default;
    ~LobbyState() = default;

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
};


#endif
