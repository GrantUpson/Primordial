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
    std::function<void(Reference<Event>&)> callback = [this](auto && PH1) { OnDeath(std::forward<decltype(PH1)>(PH1)); };
    eventBus.SubscribeToEvent(EventID::PlayerDied, callback);
}


void SpriteRenderingSystem::OnDeath(const Reference<Event> &event) {
    Reference<PlayerDeathEvent> eventData = std::static_pointer_cast<PlayerDeathEvent>(event);
    std::cout << "On Death! ID: \n" + std::to_string(eventData->id);
}
