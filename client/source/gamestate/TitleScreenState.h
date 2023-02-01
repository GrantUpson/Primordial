#ifndef PRIMORDIAL_TITLESCREENSTATE_H
#define PRIMORDIAL_TITLESCREENSTATE_H


#include "gamestate/State.h"

class TitleScreenState : public State {
public:
    TitleScreenState() = default;
    ~TitleScreenState() = default;

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
};


#endif
