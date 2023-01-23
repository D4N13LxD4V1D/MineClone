#include "window.hpp"

Window::Window(int width, int height, const char *title, bool fullscreen = false)
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    glfwSetKeyCallback(window, Input::keyCallback);
    glfwSetCursorPosCallback(window, Input::mousePositionCallback);

    glViewport(0, 0, width, height);
}

Window::~Window()
{
    glfwDestroyWindow(window);
}

void Window::swapBuffers()
{
    glfwSwapBuffers(window);
}

void Window::update()
{
    glfwPollEvents();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::close()
{
    glfwSetWindowShouldClose(window, true);
}

bool Window::isFullScreen()
{
    return glfwGetWindowMonitor(window) != NULL;
}

void Window::setFullScreen(bool fullscreen)
{
    if (fullscreen)
    {
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        std::cout << mode->width << std::endl;
        std::cout << mode->height << std::endl;

        glfwSetWindowMonitor(
            window,
            monitor,
            0,
            0,
            mode->width,
            mode->height,
            mode->refreshRate);
    }
    else
    {
        glfwSetWindowMonitor(
            window,
            NULL,
            0,
            0,
            1280,
            720,
            0);
    }
}