#ifndef PRIMORDIAL_EVENT_H
#define PRIMORDIAL_EVENT_H


#include "utility/Utility.h"
#include "ecs/entt/entt.hpp"


class Event {
public:
    Event() = default;
};


/* All Game Events */


struct ResolutionChangedEvent : public Event {
    uint32 width;
    uint32 height;

    ResolutionChangedEvent(uint32 width, uint32 height) : width(width), height(height) {}
};


struct CollisionEvent : public Event {
    Entity a;
    Entity b;

    CollisionEvent(Entity a, Entity b) : a(a), b(b) {}
};


#endif
