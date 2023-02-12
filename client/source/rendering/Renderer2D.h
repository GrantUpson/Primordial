#ifndef PRIMORDIAL_RENDERER2D_H
#define PRIMORDIAL_RENDERER2D_H


#include "utility/Utility.h"

class Renderer2D {
public:
    Renderer2D() = default;
    ~Renderer2D() = default;

    void Initialize();
    void Destroy();
    void BeginScene(/*ortho camera?*/);
    void EndScene();

    void DrawQuad(const Vector2& position, const Vector2& size, const Vector4& colour);
    void DrawQuad(const Vector3& position, const Vector2& size, const Vector4& colour);
};


#endif
