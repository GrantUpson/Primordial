#ifndef PRIMORDIAL_SPLASH_SCREEN_STATE_H
#define PRIMORDIAL_SPLASH_SCREEN_STATE_H

#include "gamestate/state.h"
#include "types.h"


class SplashScreenState : public State {
public:
    SplashScreenState() = default;
    ~SplashScreenState() = default;

    void OnEnter() override;
    void OnExit() override;
    void Update() override;

private:
    uint32 currentDuration {};
    static constexpr uint32 DURATION_LENGTH = 150;
};


#endif
