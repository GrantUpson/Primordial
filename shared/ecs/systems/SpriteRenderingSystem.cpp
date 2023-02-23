#include "SpriteRenderingSystem.h"
#include "ecs/components/TransformComponent.h"
#include "ecs/components/SpriteComponent.h"
#include "events/ApplicationEvent.h"


SpriteRenderingSystem::SpriteRenderingSystem() {

}


SpriteRenderingSystem::~SpriteRenderingSystem() {

}

void SpriteRenderingSystem::Update(entt::registry &registry) {

    auto view = registry.view<TransformComponent, SpriteComponent>();

    for(auto [entity, transform, sprite]: view.each()) {
        renderer->BeginScene();



        renderer->EndScene();
    }
}


void SpriteRenderingSystem::SubscribeToEvents(EventSystem &eventBus) {
    EventCallback callback = fastdelegate::MakeDelegate(this, &SpriteRenderingSystem::OnDeath);
    eventBus.SubscribeToEvent(EventID::PlayerDied, callback);
}


void SpriteRenderingSystem::OnDeath(const Reference<Event> &event) {
    std::cout << "On Death! ID: \n" + std::to_string(eventData->id);
}
