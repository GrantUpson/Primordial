#include "VertexArray.h"
#include "glad/glad.h"


static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {
    switch (type) {
        case ShaderDataType::None:      return GL_INVALID_ENUM;
        case ShaderDataType::Float:     return GL_FLOAT;
        case ShaderDataType::Float2:    return GL_FLOAT;
        case ShaderDataType::Float3:    return GL_FLOAT;
        case ShaderDataType::Float4:    return GL_FLOAT;
        case ShaderDataType::Mat3:      return GL_FLOAT;
        case ShaderDataType::Mat4:      return GL_FLOAT;
        case ShaderDataType::Int:       return GL_INT;
        case ShaderDataType::Int2:      return GL_INT;
        case ShaderDataType::Int3:      return GL_INT;
        case ShaderDataType::Int4:      return GL_INT;
        case ShaderDataType::Boolean:   return GL_BOOL;
    }

    return 0;
}


VertexArray::VertexArray() {
    glGenVertexArrays(1, &rendererID);
}


VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &rendererID);
}


void VertexArray::Bind() const {
    glBindVertexArray(rendererID);
}


void VertexArray::Unbind() const {
    glBindVertexArray(0);
}


void VertexArray::AddVertexBuffer(const Reference<VertexBuffer>& vertexBuffer) {
    glBindVertexArray(rendererID);
    vertexBuffer->Bind();

    const auto& layout = vertexBuffer->GetLayout();

    for(const auto& element : layout) {
        switch(element.type) {
            case ShaderDataType::None:
            case ShaderDataType::Float:
            case ShaderDataType::Float2:
            case ShaderDataType::Float3:
            case ShaderDataType::Float4: {
                glEnableVertexAttribArray(vertexBufferIndex);
                glVertexAttribPointer(vertexBufferIndex, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.type),
                                      element.normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)element.offset);
                vertexBufferIndex++;
                break;
            }

            case ShaderDataType::Int:
            case ShaderDataType::Int2:
            case ShaderDataType::Int3:
            case ShaderDataType::Int4:
            case ShaderDataType::Boolean: {
                glEnableVertexAttribArray(vertexBufferIndex);
                glVertexAttribIPointer(vertexBufferIndex, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.type),
                                      layout.GetStride(), (const void*)element.offset);
                vertexBufferIndex++;
                break;
            }

            case ShaderDataType::Mat3:
            case ShaderDataType::Mat4: {
                uint8 count = element.GetComponentCount();
                for (uint8 i = 0; i < count; i++)
                {
                    glEnableVertexAttribArray(vertexBufferIndex);
                    glVertexAttribPointer(vertexBufferIndex, count, ShaderDataTypeToOpenGLBaseType(element.type),
                                          element.normalized ? GL_TRUE : GL_FALSE, layout.GetStride(),
                                          (const void*)(element.offset + sizeof(float) * count * i));
                    glVertexAttribDivisor(vertexBufferIndex, 1);
                    vertexBufferIndex++;
                }
                break;
            }
        }
    }

    vertexBuffers.push_back(vertexBuffer);
}


void VertexArray::SetIndexBuffer(const Reference<IndexBuffer>& newIndexBuffer) {
    glBindVertexArray(rendererID);
    newIndexBuffer->Bind();
    indexBuffer = newIndexBuffer;
}
