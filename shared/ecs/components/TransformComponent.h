#ifndef PRIMORDIAL_TRANSFORM_H
#define PRIMORDIAL_TRANSFORM_H

#include "utility/Utility.h"

struct Transform {
    Vector2 position {};
    Vector2 scale {};
    float rotation {};

    explicit Transform(Vector2 position = Vector2(0, 0), Vector2 scale = Vector2(1, 1), float rotation = 0.0f) :
            position(position), scale(scale), rotation(rotation) {};

};

#endif
