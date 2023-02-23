#include <iostream>
#include "TestSystem.h"
#include "RenderCommand.h"
#include "utility/Logger.h"
#include "events/ApplicationEvent.h"

void TestSystem::SubscribeToEvents(EventSystem &eventBus) {

    eventBus.SubscribeToEvent(EventID::ResolutionChanged, callback);
}


void TestSystem::OnTest(const Reference<Event>& event) {
    Reference<ResolutionChangedEvent> eventData = std::static_pointer_cast<ResolutionChangedEvent>(event);
    std::cout << "OnTest! Width: " + std::to_string(eventData->width) << " Width: " + std::to_string(eventData->height);
}

void TestSystem::Update(entt::registry &registry) {

}
