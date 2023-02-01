#ifndef PRIMORDIAL_SPRITECOMPONENT_H
#define PRIMORDIAL_SPRITECOMPONENT_H


#include "utility/Utility.h"

struct SpriteComponent {
    Vector2 position {};
    Vector2 scale {};
    float rotation {};

    explicit SpriteComponent(Vector2 position = Vector2(0, 0), Vector2 scale = Vector2(1, 1), float rotation = 0.0f) :
            position(position), scale(scale), rotation(rotation) {};

};


#endif
