#ifndef PRIMORDIAL_TRANSFORMCOMPONENT_H
#define PRIMORDIAL_TRANSFORMCOMPONENT_H

#include "utility/Utility.h"

struct TransformComponent {
    Vector2 position {};
    Vector2 scale {};
    float rotation {};

    explicit TransformComponent(Vector2 position = Vector2(0, 0), Vector2 scale = Vector2(1, 1), float rotation = 0.0f) :
            position(position), scale(scale), rotation(rotation) {};

};

#endif
