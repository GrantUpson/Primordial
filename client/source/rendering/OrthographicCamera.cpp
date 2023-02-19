#include "OrthographicCamera.h"


void OrthographicCamera::SetProjection(float left, float right, float bottom, float top) {
    projectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
    viewProjectionMatrix = projectionMatrix * viewMatrix;
}


void OrthographicCamera::RecalculateViewMatrix() {
    Matrix4 transform = glm::translate(Matrix4(1.0f), position) *
            glm::rotate(Matrix4(1.0f), glm::radians(rotation), Vector3(0, 0, 1));

    viewMatrix = glm::inverse(transform);
    viewProjectionMatrix = projectionMatrix * viewMatrix;
}


