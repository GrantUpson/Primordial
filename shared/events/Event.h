#ifndef PRIMORDIAL_EVENT_H
#define PRIMORDIAL_EVENT_H


#include "utility/Utility.h"
#include "ecs/entt/entt.hpp"


enum class EventID {
    None = 0, ResolutionChanged, Collision,

    PlayerDied
};


class Event {
public:
    [[nodiscard]] virtual const EventID GetEventID() const = 0;
};



#endif
