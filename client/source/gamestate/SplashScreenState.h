#ifndef PRIMORDIAL_SPLASHSCREENSTATE_H
#define PRIMORDIAL_SPLASHSCREENSTATE_H


#include "gamestate/State.h"
#include "utility/Utility.h"

class SplashScreenState : public State {
public:
    SplashScreenState() = default;
    ~SplashScreenState() = default;

    void OnEnter() override;
    void OnExit() override;
    void Update() override;

private:
    uint32 currentDuration {};
    const uint32 DURATION_LENGTH = 150;
};


#endif
