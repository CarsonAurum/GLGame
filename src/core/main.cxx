//
// Carson R - 1/10/2023
//

// Dependencies
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
// Local Includes
#include "app/App.hxx"
#include "app/GLApp.hxx"
#include "debug/Logging.hxx"

using namespace TitanOfAir;

int main()
{
    logging::configureLoggers();
    spdlog::get(App::LOG)->info("Starting TitanOfAir v0.0.0-alpha.");

    // Configure OpenGL Runtime.
    auto window = graphics::configureGLFW();
    if (!window) return -1;
    int glVersion = gladLoadGL();
    if (glVersion == 0)
    {
        spdlog::get(App::LOG)->critical("Failed to initialize the OpenGL context.");
        glfwTerminate();
        return -2;
    }
    int verMajor, verMinor;
    glGetIntegerv(GL_MAJOR_VERSION, &verMajor);
    glGetIntegerv(GL_MINOR_VERSION, &verMinor);
    spdlog::get(App::LOG)->info("Loaded OpenGL {}.{}.", verMajor, verMinor);

    spdlog::get(App::LOG)->info("Loading game mechanics.");
    App::shared()->init();
    spdlog::get(App::LOG)->info("Init game mechanics complete.");

    // ...

    // End Game Logic.

    // ...

    // Terminate the program!
    glfwTerminate();
    return 0;
}