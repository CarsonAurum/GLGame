//
// Carson R - 1/10/2023
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "app/GLApp.hxx"
#include "debug/Logging.hxx"

using namespace TitanOfAir;

int main()
{
    logging::configureLoggers();
    spdlog::get("TitanOfAir")->info("Starting TitanOfAir v0.0.0-alpha.");
    auto window = graphics::configureGLFW();
    if (!window) return -1;
    int glVersion = gladLoadGL();
    if (glVersion == 0)
    {
        spdlog::get("TitanOfAir")->critical("Failed to initialize the OpenGL context.");
        glfwTerminate();
        return -2;
    }
    int verMajor, verMinor;
    glGetIntegerv(GL_MAJOR_VERSION, &verMajor);
    glGetIntegerv(GL_MINOR_VERSION, &verMinor);
    spdlog::get("TitanOfAir")->info("Loaded OpenGL {}.{}.", verMajor, verMinor);
    glfwTerminate();
    return 0;
}
