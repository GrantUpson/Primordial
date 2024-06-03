#include <iostream>
#include "window.h"

Window::Window(const WindowData* data) {
    std::cout << "Linux Window\n";
    title = data->title;
    width = data->width;
    height = data->height;
}

uint32 Window::GetHeight() const {
    return height;
}

uint32 Window::GetWidth() const {
    return width;
}
