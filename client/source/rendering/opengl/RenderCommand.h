#ifndef PRIMORDIAL_RENDERCOMMAND_H
#define PRIMORDIAL_RENDERCOMMAND_H


#include "glad/glad.h"
#include "utility/Utility.h"
#include "VertexArray.h"
#include "glfw3.h"

class RenderCommand {
public:
    static void DrawIndexed(const Reference<VertexArray>& vertexArray, uint32 indexCount);
    static void SwapBuffers(GLFWwindow* windowHandle);
    static void SetViewport(uint32 x, uint32 y, uint32 width, uint32 height);
    static void ClearScreen();
    static void SetClearColour(Vector4 colour);
};


#endif
