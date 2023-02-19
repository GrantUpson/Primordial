#ifndef PRIMORDIAL_INPUT_H
#define PRIMORDIAL_INPUT_H

#include "utility/Utility.h"
#include "InputCodes.h"

class Input
{
public:
    static bool IsKeyPressed(KeyCode key);

    static bool IsMouseButtonPressed(MouseCode button);
    static Vector2 GetMousePosition();
    static float GetMouseX();
    static float GetMouseY();
};


#endif
