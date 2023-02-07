//
// Carson R - 1/23/23
//

// Dependencies
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
// Local Includes
#include "app/GLApp.hxx"
#include "app/App.hxx"

using namespace TitanOfAir;

namespace TitanOfAir::graphics
{
    GLuint RENDERING_PROGRAM;
    GLuint VAOs[cr_numVAOs];


    GLFWwindow* configureGLFW()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        if (!glfwInit())
        {
            spdlog::get(App::LOG)->critical("Unable to initialize OpenGL Windowing Service.");
            glfwTerminate();
            return nullptr;
        }
        spdlog::get(App::LOG)->info("GL windowing service successfully initialized.");
        auto window = glfwCreateWindow(
                600, 600, "TitanOfAir", nullptr, nullptr
                                      );
        glfwMakeContextCurrent(window);
        glfwSwapInterval(2);
        return window;
    }

    void glInit(GLFWwindow* window)
    {
        RENDERING_PROGRAM = glLoadShaders();
        glGenVertexArrays(cr_numVAOs, VAOs);
        glBindVertexArray(VAOs[0]);
    }

    void glDisplay(GLFWwindow* window, double time)
    {
        glUseProgram(RENDERING_PROGRAM);
        glDrawArrays(GL_POINTS, 0, 1);
    }

    GLuint glLoadShaders()
    {
        auto vShader = glCreateShader(GL_VERTEX_SHADER);
        auto fShader = glCreateShader(GL_FRAGMENT_SHADER);

        // glShaderSource(vShader, 1, &shaderSource, nullptr);
        // glShaderSource(fShader, 1, &fShaderSource, nullptr);

        glCompileShader(vShader);
        glCompileShader(fShader);

        auto program = glCreateProgram();
        glAttachShader(program, vShader);
        glAttachShader(program, fShader);

        glLinkProgram(program);
        return program;
    }
}