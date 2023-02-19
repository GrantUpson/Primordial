#ifndef PRIMORDIAL_TESTSYSTEM_H
#define PRIMORDIAL_TESTSYSTEM_H


#include "events/EventBus.h"
#include "System.h"

class TestSystem : public System {
public:
    TestSystem() = default;
    ~TestSystem() = default;

    void SubscribeToEvents(EventBus& eventBus);
    void Update(entt::registry &registry) override;

private:
    void OnTest(ResolutionChangedEvent& event);
};


#endif
