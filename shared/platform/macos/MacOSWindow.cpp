#include <iostream>
#include "Window.h"

static void error_callback(int error, const char* description) {
    std::cout << "Error callback\n";
}

Window::Window(const WindowData* data) {
    title = data->title;
    width = data->width;
    height = data->height;
    vSyncEnabled = data->vSyncEnabled;
    fullscreenEnabled = data->fullscreenEnabled;

    glfwSetErrorCallback(error_callback);

    if(!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if(!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
}

void Window::Close() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

uint32 Window::GetHeight() const {
    return height;
}

uint32 Window::GetWidth() const {
    return width;
}

bool Window::VSyncEnabled() const {
    return vSyncEnabled;
}

bool Window::FullscreenEnabled() const {
    return fullscreenEnabled;
}

GLFWwindow* Window::GetWindow() {
    return window;
}
