//
// Carson R - 1/10/2023
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include "app/GLApp.hxx"
#include "debug/Logging.hxx"
#include "api/entities/Entity.hxx"

using namespace TitanOfAir;

/**
 *
 * @return
 *      0  = Success.
 *      -1 = GLFW failure.
 *      -2 = OpenGL failure.
 */
int main()
{
    logging::configureLoggers();
    spdlog::get("TitanOfAir")->info("Starting TitanOfAir v0.0.0-alpha.");

    // Configure OpenGL Runtime.
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

    // Start Game Logic.

    // ...

    // End Game Logic.

    // ...

    // Terminate the program!
    glfwTerminate();
    return 0;
}
