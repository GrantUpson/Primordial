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


using Callbacks = std::list<std::function<void(Reference<Event>&)>>;
const uint32 NUM_QUEUES {2};

class EventSystem {
public:
    EventSystem() { activeQueue = 0; }
    ~EventSystem() = default;


    void SubscribeToEvent(EventID id, std::function<void(Reference<Event>&)> callback) {
        if(!subscribers[id]) {
            subscribers[id] = std::make_unique<Callbacks>();
        }

        subscribers[id]->push_back(std::move(callback));
    }


    void UnsubscribeToEvent(EventID id, std::function<void(Reference<Event>&)> callback) {
        auto handlers = subscribers[id].get();

       // handlers->remove(callback);
    }


    void QueueEvent(const Reference<Event>& event) {
        eventQueue[activeQueue].push_back(event);s
    }


    void DispatchEvent(Reference<Event>& event) {
        auto handlers = subscribers[event->GetEventID()].get();

        if(handlers) {
            for(auto& it : *handlers) {
                it(event);
            }
        }
    }


    void CancelEvent(EventID eventID, bool allOfType = false) {
        auto it = eventQueue[activeQueue].begin();

        while(it != eventQueue[activeQueue].end()) {
            EventID x = it->get()->GetEventID();
            if(x == eventID) {
                std::cout << "FOUND!";
                it = eventQueue[activeQueue].erase(it);

                if(!allOfType) { break; }
            } else {
                it++;
            }
        }
    }


    void ProcessEvents() {
        uint32 queueToProcess = activeQueue;
        activeQueue = (activeQueue + 1) % NUM_QUEUES;
        eventQueue[activeQueue].clear();

        while(!eventQueue[queueToProcess].empty()) {
            Reference<Event> event = eventQueue[queueToProcess].front();
            eventQueue[queueToProcess].pop_front();

            DispatchEvent(event);
        }
    }


    void Clear() { subscribers.clear(); }

private:
    uint32 activeQueue {};

    std::list<Reference<Event>> eventQueue[NUM_QUEUES];
    std::map<EventID, Scope<Callbacks>> subscribers;
};


#endif
