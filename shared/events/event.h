#ifndef PRIMORDIAL_EVENT_H
#define PRIMORDIAL_EVENT_H


#include "types.h"


enum class EventID {
    None = 0, ResolutionChanged, Collision,

    PlayerDied
};


class Event {
public:
    [[nodiscard]] virtual const EventID GetEventID() const = 0;
};


#endif
