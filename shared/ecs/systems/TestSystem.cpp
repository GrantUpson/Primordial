#include <iostream>
#include "TestSystem.h"
#include "RenderCommand.h"
#include "utility/Logger.h"
#include "events/ApplicationEvent.h"

void TestSystem::SubscribeToEvents(EventSystem &eventBus) {
    std::function<void(Reference<Event>&)> callback = [this](auto && PH1) { OnTest(std::forward<decltype(PH1)>(PH1)); };
    eventBus.SubscribeToEvent(EventID::ResolutionChanged, callback);
}


void TestSystem::OnTest(const Reference<Event>& event) {
    Reference<ResolutionChangedEvent> eventData = std::static_pointer_cast<ResolutionChangedEvent>(event);

    std::cout << "OnTest! Width: " + std::to_string(eventData->width) << " Width: " + std::to_string(eventData->height);
}

void TestSystem::Update(entt::registry &registry) {

}
