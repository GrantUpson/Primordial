#include <iostream>
#include "TestSystem.h"
#include "RenderCommand.h"
#include "utility/Logger.h"

void TestSystem::SubscribeToEvents(EventBus &eventBus) {
    eventBus.SubscribeToEvent<ResolutionChangedEvent>(this, &TestSystem::OnTest);
}


void TestSystem::OnTest(ResolutionChangedEvent& event) {
    //RenderCommand::SetViewport(0, 0, event.width, event.height);
    std::cout << "OnTest Called\n";
}

void TestSystem::Update(entt::registry &registry) {

}
