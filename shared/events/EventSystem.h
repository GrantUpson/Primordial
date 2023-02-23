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


typedef fastdelegate::FastDelegate1<std::shared_ptr<IEvent>> EventCallback;
const uint32 NUM_QUEUES {2};


class EventSystem {
public:
    EventSystem() = default;
    ~EventSystem() = default;

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
};


#endif
