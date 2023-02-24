#ifndef PRIMORDIAL_TESTSYSTEM_H
#define PRIMORDIAL_TESTSYSTEM_H


#include "events/EventSystem.h"
#include "System.h"
#include "events/ApplicationEvent.h"

class TestSystem : public System {
public:
    TestSystem() = default;
    ~TestSystem();

    void SubscribeToEvents(EventSystem& eventBus);
    void Update(entt::registry &registry) override;

private:
    void OnTest(Reference<Event> event);
};


#endif
