#ifndef PRIMORDIAL_PLAYINGSTATE_H
#define PRIMORDIAL_PLAYINGSTATE_H


#include "gamestate/State.h"

class PlayingState : public State {
public:
    PlayingState() = default;
    ~PlayingState() = default;

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
};


#endif
