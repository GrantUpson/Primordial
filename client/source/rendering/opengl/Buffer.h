#ifndef PRIMORDIAL_BUFFER_H
#define PRIMORDIAL_BUFFER_H


#include "utility/Utility.h"


enum class ShaderDataType { None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Boolean };

static uint32 ShaderDataTypeSize(ShaderDataType type) {
    switch(type) {
        case ShaderDataType::None:      return 0;
        case ShaderDataType::Float:     return 4;
        case ShaderDataType::Float2:    return 4 * 2;
        case ShaderDataType::Float3:    return 4 * 3;
        case ShaderDataType::Float4:    return 4 * 4;
        case ShaderDataType::Mat3:      return 4 * 3 * 3;
        case ShaderDataType::Mat4:      return 4 * 4 * 4;
        case ShaderDataType::Int:       return 4;
        case ShaderDataType::Int2:      return 4 * 2;
        case ShaderDataType::Int3:      return 4 * 3;
        case ShaderDataType::Int4:      return 4 * 4;
        case ShaderDataType::Boolean:   return 1;
    }

    return 0;
}


struct BufferElement {
    std::string name {};
    ShaderDataType type {};
    uint32 size {};
    size_t offset {};
    bool normalized {};

    BufferElement() = default;
    BufferElement(std::string& name, ShaderDataType type, bool normalized = false)
        : name(name), type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized) {}

    [[nodiscard]] uint32 GetComponentCount() const {
        switch(type) {
            case ShaderDataType::None:      return 0;
            case ShaderDataType::Float:     return 1;
            case ShaderDataType::Float2:    return 2;
            case ShaderDataType::Float3:    return 3;
            case ShaderDataType::Float4:    return 4;
            case ShaderDataType::Mat3:      return 3;
            case ShaderDataType::Mat4:      return 4;
            case ShaderDataType::Int:       return 1;
            case ShaderDataType::Int2:      return 2;
            case ShaderDataType::Int3:      return 3;
            case ShaderDataType::Int4:      return 4;
            case ShaderDataType::Boolean:   return 1;
        }

        return 0;
    }
};


class BufferLayout {
public:
    BufferLayout() = default;
    BufferLayout(std::initializer_list<BufferElement> elements) : elements(elements) { CalculateOffsetAndStride(); }
    ~BufferLayout() = default;

    [[nodiscard]] uint32 GetStride() const { return stride; }
    [[nodiscard]] const std::vector<BufferElement>& GetElements() const { return elements; }

    std::vector<BufferElement>::iterator begin() { return elements.begin(); }
    std::vector<BufferElement>::iterator end() { return elements.end(); }
    [[nodiscard]] std::vector<BufferElement>::const_iterator begin() const { return elements.begin(); }
    [[nodiscard]] std::vector<BufferElement>::const_iterator end() const { return elements.end(); }
private:
    std::vector<BufferElement> elements;
    uint32 stride {0};

    void CalculateOffsetAndStride();
};


class VertexBuffer {
public:
    explicit VertexBuffer(uint32 size);
    VertexBuffer(float* vertices, uint32 size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;

    void SetData(float* vertices, uint32 size);
    void SetLayout(const BufferLayout& newLayout) { layout = newLayout; };
    [[nodiscard]] const BufferLayout& GetLayout() const { return layout; };
private:
    uint32 rendererID;
    BufferLayout layout {};
};


class IndexBuffer {
public:
    IndexBuffer(uint32* indices, uint32 count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;
    [[nodiscard]] uint32 GetCount() const { return count; };

private:
    uint32 rendererID;
    uint32 count;
};





#endif
