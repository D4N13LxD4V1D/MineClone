#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
    Window(int width, int height, const char *title, bool fullscreen = false);
    ~Window();

    void update();
    bool shouldClose();

    void setKeyCallback(GLFWkeyfun callback);
    void setMouseCallback(GLFWcursorposfun callback);

private:
    GLFWwindow *window;
};