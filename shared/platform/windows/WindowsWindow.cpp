#include <iostream>
#include "Window.h"

Window::Window(const WindowData* data) {
    std::cout << "Windows Window\n";
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

