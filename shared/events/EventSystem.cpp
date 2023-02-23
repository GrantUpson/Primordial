#include "EventSystem.h"


void EventSystem::SubscribeToEvent(const EventID id, EventCallback& callback) {
    subscribers[id].push_back(std::move(callback));
}


void EventSystem::UnsubscribeToEvent(const EventID id, const EventCallback& callback) {
    auto handlers = subscribers.find(id);

    if(handlers != subscribers.end()) {
        std::list<EventCallback> callbacks = handlers->second;

        for(auto it = callbacks.begin(); it != callbacks.end(); ++it) {
            if(callback == (*it)) {
                callbacks.erase(it);
                break;
            }
        }
    }
}


void EventSystem::QueueEvent(const Reference<Event>& event) {
    eventQueue[activeQueue].push_back(event);
}


void EventSystem::DispatchEvent(Reference<Event>& event) {
    auto handlers = subscribers.find(event->GetEventID());

    std::list<EventCallback> callbacks = handlers->second;

    for(const EventCallback& callback : callbacks) {
        callback(event);
    }
}


void EventSystem::CancelEvent(EventID eventID, bool allOfType) {
    auto it = eventQueue[activeQueue].begin();

    while(it != eventQueue[activeQueue].end()) {
        EventID x = it->get()->GetEventID();

        if(x == eventID) {
            std::cout << "FOUND!";
            it = eventQueue[activeQueue].erase(it);

            if(!allOfType) {
                break;
            }
        } else {
            it++;
        }
    }
}


void EventSystem::ProcessEvents() {
    uint32 queueToProcess = activeQueue;
    activeQueue = (activeQueue + 1) % NUM_QUEUES;
    eventQueue[activeQueue].clear();

    while(!eventQueue[queueToProcess].empty()) {
        Reference<Event> event = eventQueue[queueToProcess].front();
        eventQueue[queueToProcess].pop_front();

        DispatchEvent(event);
    }
}


void EventSystem::ClearEvents() {
    subscribers.clear();
}