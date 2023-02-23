#ifndef PRIMORDIAL_APPLICATIONEVENT_H
#define PRIMORDIAL_APPLICATIONEVENT_H


#include "Event.h"

struct ResolutionChangedEvent : public Event {
    uint32 width;
    uint32 height;

    ResolutionChangedEvent(uint32 width, uint32 height) : width(width), height(height) {}

    static EventID GetStaticID() { return EventID::ResolutionChanged; }
    [[nodiscard]] EventID const GetEventID() const override { return GetStaticID(); }
};


struct PlayerDeathEvent : public Event {
    uint32 id;

    PlayerDeathEvent(uint32 id) : id(id) {}

    static EventID GetStaticID() { return EventID::PlayerDied; }
    [[nodiscard]] EventID const GetEventID() const override { return GetStaticID(); }
};


#endif
