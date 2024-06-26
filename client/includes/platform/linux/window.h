#ifndef PRIMORDIAL_WINDOW_H
#define PRIMORDIAL_WINDOW_H

#include <utility>
#include "types.h"
#include "glad/glad.h"

struct WindowData {
    std::string title;
    uint32 width;
    uint32 height;

    explicit WindowData(std::string title = "Primordial", uint32 width = 1920, uint32 height = 1080) :
               title(std::move(title)), width(width), height(height) {};
};

class Window {
public:
    explicit Window(const WindowData* data);
    ~Window() = default;

    uint32 GetWidth() const;
    uint32 GetHeight() const;
    void Close();

private:
    std::string title;
    uint32 width;
    uint32 height;
};


#endif
