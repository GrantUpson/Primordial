#include "RenderCommand.h"
#include "glad/glad.h"


//TODO may not need to pass in index count if it can also be determined by the indexBuffer inside the vertex array?
void RenderCommand::DrawIndexed(const Reference<VertexArray> &vertexArray, uint32 indexCount) {
    vertexArray->Bind();
   // uint32 count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
}


void RenderCommand::SwapBuffers(GLFWwindow* windowHandle) {
    glfwSwapBuffers(windowHandle);
}


void RenderCommand::SetViewport(uint32 x, uint32 y, uint32 width, uint32 height) {
    glViewport(x, y, width, height);
}


void RenderCommand::ClearScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void RenderCommand::SetClearColour(Vector4 colour) {
    glClearColor(colour.r, colour.g, colour.b, colour.a);
}
