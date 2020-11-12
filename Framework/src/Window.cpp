#include "Window.h"

namespace nano {
    namespace framework {
        Window::Window(WindowProperties props)
            :properties(props)
        {
            init();
        }
        Window::~Window()
        {
            glfwDestroyWindow(window);
        }

        void Window::setGLContext()
        {
            glfwMakeContextCurrent(window);
        }

        void Window::init()
        {
            // Initialise GLFW
            if (!glfwInit())
            {
                fprintf(stderr, "Failed to initialize GLFW\n");
                getchar();
                return;
            }

            glfwWindowHint(GLFW_SAMPLES, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            // Open a window and create its OpenGL context
            window = glfwCreateWindow(properties.resolution.x,properties.resolution.y,properties.name.c_str(), NULL, NULL);
            if (window == NULL) {
                fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
                getchar();
                glfwTerminate();
                return;
            }
            setGLContext();
        }

    }
}
