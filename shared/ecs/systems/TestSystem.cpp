#include <iostream>
#include "TestSystem.h"
#include "utility/Logger.h"
#include "events/ApplicationEvent.h"


TestSystem::~TestSystem() {
    EventCallback callback = fastdelegate::MakeDelegate(this, &TestSystem::OnTest);
    EventSystem::GetInstance().UnsubscribeToEvent(EventID::ResolutionChanged, callback);
    std::cout << "Unsubscribing to ResolutionChanged for OnTest\n";
}


void TestSystem::SubscribeToEvents(EventSystem &eventBus) {
    EventCallback callback = fastdelegate::MakeDelegate(this, &TestSystem::OnTest);
    eventBus.SubscribeToEvent(EventID::ResolutionChanged, callback);
}



void TestSystem::OnTest(Reference<Event> event) {
    Reference<ResolutionChangedEvent> eventData = std::static_pointer_cast<ResolutionChangedEvent>(event);
    std::cout << "OnTest! Width: " + std::to_string(eventData->width) << " Width: " + std::to_string(eventData->height) << "\n";
}

void TestSystem::Update(entt::registry &registry) {
    //WORK WOULD GO HERE
}