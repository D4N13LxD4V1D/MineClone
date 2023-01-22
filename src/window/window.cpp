#include "window.hpp"

Window::Window(int width, int height, const char *title, bool fullscreen = false) {
    if (fullscreen)
    {
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        std::cout << mode->width << std::endl;
        std::cout << mode->height << std::endl;

        window = glfwCreateWindow(
            mode->width,
            mode->height,
            title,
            monitor,
            NULL // Share, use this to share resources with another window
        );
    }
    else
    {
        window = glfwCreateWindow(
            width,
            height,
            title,
            NULL,
            NULL // Share, use this to share resources with another window
        );
    }
}