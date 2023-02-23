#ifndef PRIMORDIAL_INPUTEVENT_H
#define PRIMORDIAL_INPUTEVENT_H


#include "Event.h"


struct CollisionEvent : public Event {
    Entity a;
    Entity b;

    CollisionEvent(Entity a, Entity b) : a(a), b(b) {}
};


#endif
