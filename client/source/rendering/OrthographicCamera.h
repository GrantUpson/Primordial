#ifndef PRIMORDIAL_ORTHOGRAPHICCAMERA_H
#define PRIMORDIAL_ORTHOGRAPHICCAMERA_H

#include "utility/Utility.h"


class OrthographicCamera {
public:
    OrthographicCamera(float left, float right, float bottom, float top) :
        projectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)) {};

    void SetProjection(float left, float right, float bottom, float top);

    const Vector3& GetPosition() const { return position; }
    void SetPosition(const Vector3 newPosition) { position = newPosition; RecalculateViewMatrix(); }

    const Matrix4& GetProjectionMatrix() { return projectionMatrix; }
    const Matrix4& GetViewMatrix() { return viewMatrix; }
    const Matrix4& GetViewProjectionMatrix() { return viewProjectionMatrix; }
private:
    Matrix4 projectionMatrix {};
    Matrix4 viewMatrix {};
    Matrix4 viewProjectionMatrix {};
    Vector3 position {0.0f, 0.0f, 0.0f};
    float rotation {1.0f};

    void RecalculateViewMatrix();
};


#endif
