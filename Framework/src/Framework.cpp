#include <GL/glew.h>

#include "Framework.h"
#include <cstdio>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <InputProcessor.h>
using namespace glm;

namespace  nano
{
    namespace framework
    {
        void Framework::renderLoop()
        {
            GLFWwindow* window = globWindow->GetGLFWWindow();
            if (glewInit() != GLEW_OK) {
                fprintf(stderr, "Failed to initialize GLEW\n");
                getchar();
                glfwTerminate();
                return;
            }

            glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

            do {
                glClear(GL_COLOR_BUFFER_BIT);
                InputProcessor::get().update();
                glfwSwapBuffers(window);
                
            }
            while (!InputProcessor::get().isKeyPressed( GLFW_KEY_ESCAPE) &&
                !globWindow->shouldClose());

            glfwTerminate();
        }
        void Framework::init()
        {
            if (globWindow == nullptr) {
                WindowProperties properties;
                globWindow = std::make_shared<Window>(properties);
            }
            
        }
    }
}
