#ifndef PRIMORDIAL_EVENT_H
#define PRIMORDIAL_EVENT_H


#include "utility/Utility.h"
#include "ecs/entt/entt.hpp"


enum class EventID {
    None = 0, ResolutionChanged, Collision,

    PlayerDied
};


/*class IEvent {
public:
    [[nodiscard]] virtual const EventID GetEventID() const = 0;
};*/


class Event {
public:
    [[nodiscard]] virtual EventID GetEventID() const = 0;
};



#endif
