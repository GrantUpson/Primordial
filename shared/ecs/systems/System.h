#ifndef PRIMORDIAL_SYSTEM_H
#define PRIMORDIAL_SYSTEM_H


#include "ecs/entt/entity/registry.hpp"

class System {
public:
    System() = default;
    ~System() = default;

    virtual void Update(entt::registry& registry) = 0;
};


#endif
