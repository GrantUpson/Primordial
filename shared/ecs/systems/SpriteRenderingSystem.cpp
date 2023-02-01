#include "SpriteRenderingSystem.h"
#include "ecs/components/TransformComponent.h"
#include "ecs/components/SpriteComponent.h"


SpriteRenderingSystem::SpriteRenderingSystem(Renderer2D* renderer2D) {
    this->renderer = renderer2D;
}


SpriteRenderingSystem::~SpriteRenderingSystem() {
    delete renderer;
}

void SpriteRenderingSystem::Update(entt::registry &registry) {

    auto view = registry.view<TransformComponent, SpriteComponent>();

    for(auto [entity, transform, sprite]: view.each()) {
        renderer->BeginScene();



        renderer->EndScene();
    }
}



