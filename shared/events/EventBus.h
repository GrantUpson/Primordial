#ifndef PRIMORDIAL_EVENTBUS_H
#define PRIMORDIAL_EVENTBUS_H


#include <map>
#include <typeindex>
#include <memory>
#include <list>
#include "Event.h"
#include "utility/Utility.h"


class IEventCallback {
public:
    virtual ~IEventCallback() = default;
    void Invoke(Event event) { Call(event); }

private:
    virtual void Call(Event& event) = 0;
};


template <typename TOwner, typename TEvent>
class EventCallback : public IEventCallback {
private:
    typedef void (TOwner::*CallbackFunction)(TEvent&);
    TOwner* ownerInstance;
    CallbackFunction callbackFunction;

    void Call(Event& event) override {
        std::invoke(callbackFunction, ownerInstance, static_cast<TEvent&>(event));
    }

public:
    EventCallback(TOwner* ownerInstance, CallbackFunction callbackFunction) {
        this->ownerInstance = ownerInstance;
        this->callbackFunction = callbackFunction;
    };

    ~EventCallback() override = default;
};


using CallbackHandlers = std::list<Scope<IEventCallback>>;


class EventBus {
public:
    EventBus() = default;
    ~EventBus() = default;

    template <typename TEvent, typename TOwner>
    void SubscribeToEvent(TOwner* ownerInstance, void(TOwner::*callbackFunction)(TEvent& event)) {
        if(!subscribers[typeid(TEvent)].get()) {
            subscribers[typeid(TEvent)] = std::make_unique<CallbackHandlers>();
        }

        auto subscriber = std::make_unique<EventCallback<TOwner, TEvent>>(ownerInstance, callbackFunction);
        subscribers[typeid(TEvent)]->push_back(std::move(subscriber));
    }


    template <typename TOwner>
    void UnsubscribeToEvent(TOwner* ownerInstance, std::type_index type) {
        if(subscribers[typeid(type)].get()) {
            std::remove(subscribers.begin(), subscribers.end(), ownerInstance);
        }
    }


    template <typename TEvent, typename ...TArgs>
    void DispatchEvent(TArgs&& ...args) {
        auto handlers = subscribers[typeid(TEvent)].get();

        if(handlers) {
            for(auto& it : *handlers) {
                IEventCallback* handler = it.get();
                TEvent event(std::forward<TArgs>(args)...);
                handler->Invoke(event);
            }
        }
    }


    template <typename TEvent, typename ...TArgs>
    void QueueEvent(TArgs&& ...args) {
        auto handlers = subscribers[typeid(TEvent)].get();

        if(handlers) {
            for(auto& it : *handlers) {
                IEventCallback* handler = it.get();
                TEvent event(std::forward<TArgs>(args)...);
                handler->Invoke(event);
            }
        }
    }


    void Reset() { subscribers.clear(); }

private:
    std::map<std::type_index, Scope<CallbackHandlers>> subscribers;
};


#endif
