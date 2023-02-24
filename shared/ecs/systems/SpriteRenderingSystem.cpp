#include "SpriteRenderingSystem.h"
#include "ecs/components/TransformComponent.h"
#include "ecs/components/SpriteComponent.h"


SpriteRenderingSystem::SpriteRenderingSystem() {

}


SpriteRenderingSystem::~SpriteRenderingSystem() {

}


void SpriteRenderingSystem::SubscribeToEvents(EventSystem &eventBus) {

}


void SpriteRenderingSystem::Update(entt::registry &registry) {
    auto view = registry.view<TransformComponent, SpriteComponent>();

    for(auto [entity, transform, sprite]: view.each()) {
        Renderer2D::BeginScene();

        //TODO

        Renderer2D::EndScene();
    }
}



