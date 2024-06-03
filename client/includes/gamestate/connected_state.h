#ifndef PRIMORDIAL_CONNECTED_STATE_H
#define PRIMORDIAL_CONNECTED_STATE_H

#include "gamestate/state.h"


class ConnectedState : public State {
public:
    ConnectedState() = default;
    ~ConnectedState() = default;

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
};


#endif
