#ifndef PRIMORDIAL_EVENTSYSTEM_H
#define PRIMORDIAL_EVENTSYSTEM_H


#include <map>
#include <typeindex>
#include <memory>
#include <list>
#include <queue>
#include <iostream>
#include "Event.h"
#include "utility/Utility.h"


typedef fastdelegate::FastDelegate1<Reference<Event>> EventCallback;
const uint32 NUM_QUEUES {2};


class EventSystem {
public:
    EventSystem(const EventSystem&) = delete;
    EventSystem& operator=(const EventSystem&) = delete;

    static EventSystem& GetInstance() {
        static EventSystem instance;
        return instance;
    }

    void SubscribeToEvent(EventID id, EventCallback& callback);
    void UnsubscribeToEvent(EventID id, const EventCallback& callback);

    void QueueEvent(const Reference<Event>& event);
    void DispatchEvent(Reference<Event>& event);
    void CancelEvent(EventID eventID, bool allOfType = false);

    void ProcessEvents();
    void ClearEvents();

private:
    uint32 activeQueue {0};

    std::list<Reference<Event>> eventQueue[NUM_QUEUES];
    std::map<EventID, std::list<EventCallback>> subscribers;

private:
    EventSystem() = default;
    ~EventSystem() = default;
};


#endif
