#include "Buffer.h"
#include "glad/glad.h"



VertexBuffer::VertexBuffer(uint32 size) {
    glGenBuffers(1, &rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}


VertexBuffer::VertexBuffer(float* vertices, uint32 size) {
    glGenBuffers(1, &rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}


VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &rendererID);
}


void VertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
}


void VertexBuffer::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void VertexBuffer::SetData(float* vertices, uint32 size) {
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
    glBufferSubData(GL_ARRAY_BUFFER, 0, size, vertices);
}


/**
 * INDEX BUFFER
 */


IndexBuffer::IndexBuffer(uint32 *indices, uint32 count) : count(count) {
    glGenBuffers(1, &rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32), indices, GL_STATIC_DRAW);
}


IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &rendererID);
}


void IndexBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
}


void IndexBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


/**
 * BUFFER LAYOUT
 */


void BufferLayout::CalculateOffsetAndStride() {
    size_t offset = 0;
    stride = 0;

    for(auto& element: elements) {
        element.offset = offset;
        offset += element.size;
        stride += element.size;
    }
}
