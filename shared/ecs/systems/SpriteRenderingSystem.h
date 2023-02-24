#ifndef PRIMORDIAL_SPRITERENDERINGSYSTEM_H
#define PRIMORDIAL_SPRITERENDERINGSYSTEM_H


#include "System.h"
#include "rendering/Renderer2D.h"
#include "ecs/entt/entt.hpp"
#include "events/EventSystem.h"

class SpriteRenderingSystem : public System {
public:
    SpriteRenderingSystem();
    ~SpriteRenderingSystem();

    void SubscribeToEvents(EventSystem& eventSystem);
    void Update(entt::registry& registry) override;
};


#endif

