#include "Renderer2D.h"
#include "RenderCommand.h"



void Renderer2D::Initialize() {
    RenderCommand::SetClearColour({0.7, 0.3f, 0.9f, 1.0f});
}


void Renderer2D::Destroy() {

}


void Renderer2D::BeginScene() {
    RenderCommand::ClearScreen();

    //TESTING
    float vertices[] = {
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.5f,  0.5f,
            -0.5f,  0.5f
    };

    uint32 indices[] = {
            0, 1, 2,
            2, 3, 0
    };

    Reference<VertexArray> va(new VertexArray());
    Reference<VertexBuffer> vb(new VertexBuffer(vertices, sizeof(vertices)));

    std::string name = "Position";
    //Set the layout of the vertex buffer
    vb->SetLayout({
        { BufferElement(name, ShaderDataType::Float2) }
    });

    //Add the vertex buffer and its layout to the vertex array
    va->AddVertexBuffer(vb);

    Reference<IndexBuffer> ib(new IndexBuffer(indices, 6));

    va->SetIndexBuffer(ib);

    RenderCommand::DrawIndexed(va, 6);

    // view_position = position + (speed * interpolation) for updating rendered things between frames
}


void Renderer2D::EndScene() {


}


void Renderer2D::DrawQuad(const Vector2 &position, const Vector2 &size, const Vector4 &colour) {

}


void Renderer2D::DrawQuad(const Vector3 &position, const Vector2 &size, const Vector4 &colour) {

}
