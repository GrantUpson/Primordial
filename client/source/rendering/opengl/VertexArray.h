#ifndef PRIMORDIAL_VERTEXARRAY_H
#define PRIMORDIAL_VERTEXARRAY_H


#include "utility/Utility.h"
#include "Buffer.h"

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;

    void AddVertexBuffer(const Reference<VertexBuffer>& vertexBuffer);
    void SetIndexBuffer(const Reference<IndexBuffer>& indexBuffer);

    [[nodiscard]] const std::vector<Reference<VertexBuffer>>& GetVertexBuffers() const { return vertexBuffers; };
    [[nodiscard]] const Reference<IndexBuffer>& GetIndexBuffer() const { return indexBuffer; };

private:
    uint32 rendererID;
    uint32 vertexBufferIndex = 0;
    std::vector<Reference<VertexBuffer>> vertexBuffers;
    Reference<IndexBuffer> indexBuffer;
};


#endif
