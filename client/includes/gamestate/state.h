#ifndef PRIMORDIAL_STATE_H
#define PRIMORDIAL_STATE_H


class State {
public:
    State() = default;
    ~State() = default;

    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void Update() = 0;
};

#endif
