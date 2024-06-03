#ifndef PRIMORDIAL_TITLE_SCREEN_STATE_H
#define PRIMORDIAL_TITLE_SCREEN_STATE_H

#include "gamestate/state.h"


class TitleScreenState : public State {
public:
    TitleScreenState() = default;
    ~TitleScreenState() = default;

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
};


#endif
