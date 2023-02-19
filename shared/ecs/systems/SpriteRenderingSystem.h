#ifndef PRIMORDIAL_SPRITERENDERINGSYSTEM_H
#define PRIMORDIAL_SPRITERENDERINGSYSTEM_H


#include "System.h"
#include "rendering/Renderer2D.h"
#include "ecs/entt/entt.hpp"
#include "events/EventBus.h"

class SpriteRenderingSystem : public System {
public:
    SpriteRenderingSystem(Renderer2D* renderer);
    ~SpriteRenderingSystem();

    void Update(entt::registry& registry) override;

private:
    Renderer2D* renderer;
};


#endif
