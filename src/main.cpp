// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <iostream>
// #include <string>

// void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
// {
//     if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//     {
//         glfwSetWindowShouldClose(window, true);
//     }
// }

// void mouse_callback(GLFWwindow *window, double xpos, double ypos)
// {
//     // std::cout << "Mouse position: " << xpos << ", " << ypos << std::endl;
// }

// int main(int argc, char const *argv[])
// {
//     if (!glfwInit())
//     {
//         std::cout << "Failed to initialize GLFW" << std::endl;
//         return -1;
//     }

//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     const int windowWidth = 1280;
//     const int windowHeight = 720;
//     const char *windowTitle = "My Minecraft Clone";

//     GLFWwindow *window;
//     if (argc > 1 && strcmp(argv[1], "-fullscreen") == 0)
//     {
//         GLFWmonitor *monitor = glfwGetPrimaryMonitor();
//         const GLFWvidmode *mode = glfwGetVideoMode(monitor);
//         std::cout << mode->width << std::endl;
//         std::cout << mode->height << std::endl;

//         window = glfwCreateWindow(
//             mode->width,
//             mode->height,
//             windowTitle,
//             monitor,
//             NULL // Share, use this to share resources with another window
//         );
//     }
//     else
//     {
//         window = glfwCreateWindow(
//             windowWidth,
//             windowHeight,
//             windowTitle,
//             NULL,
//             NULL // Share, use this to share resources with another window
//         );
//     }

//     if (window == nullptr)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);

//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }

//     glfwSetKeyCallback(window, key_callback);
//     glfwSetCursorPosCallback(window, mouse_callback);

//     glViewport(0, 0, windowWidth, windowHeight);
//     while (!glfwWindowShouldClose(window))
//     {
//         glfwPollEvents();

//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         glfwSwapBuffers(window);
//     }

//     glfwTerminate();

//     return 0;
// }

#include "input/input.hpp"
#include "window/window.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Window window(1280, 720, "My Minecraft Clone", false);

    while (window.shouldClose() == false)
    {
        window.update();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        if (Input::isKeyPressed(GLFW_KEY_SPACE))
        {
            if (Input::isKeyPressed(GLFW_KEY_F1))
            {
                bool isFullScreen = window.isFullScreen();
                window.setFullScreen(!isFullScreen);
            }
            if (Input::mousePosition.x > 50)
            {
                printf("Mouse position is greater than 50.");
            }
            if (Input::isKeyPressed(GLFW_KEY_ESCAPE))
            {
                window.close();
            }
        }

        window.swapBuffers();
    }

    return 0;
}