//
// Carson R - 1/22/2023
//

// Dependencies
#include <cstdlib>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
// Local Includes
#include <app/App.hxx>
#include "debug/debugGL.hxx"


namespace TitanOfAir::utils
{
    void glPrintShaderLogs(GLuint shader)
    {
        spdlog::get(App::LOG)->trace("Attempting to print shader log.");
        int len = 0, count = 0;
        char *log;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
        if (len > 0)
        {
            log = static_cast<char *>(malloc(len));
            glGetShaderInfoLog(shader, len, &count, log);
            spdlog::get(App::LOG)->debug("Shader Log: {}", log);
            free(log);
        }
        else
        {
            spdlog::get(App::LOG)->error("Failed to print shader log.");
        }
    }

    void glPrintProgramLog(GLuint program)
    {
        spdlog::get(App::LOG)->trace("Attempting to print program info log.");
        int len = 0, count = 0;
        char *log;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
        if (len > 0)
        {
            log = static_cast<char *>(malloc(len));
            glGetProgramInfoLog(program, len, &count, log);
            spdlog::get(App::LOG)->debug("Program Info Log: {}.", log);
            free(log);
        }
        else
        {
            spdlog::get(App::LOG)->error("Failed to print program info log.");
        }
    }

    bool glCheckError()
    {
        spdlog::get(App::LOG)->trace("Checking for GL errors.");
        auto foundError = false;
        auto error = glGetError();
        while (error != GL_NO_ERROR)
        {
            spdlog::get(App::LOG)->debug("GLError: {}.", error);
            foundError = true;
            error = glGetError();
        }
        if (!foundError)
        {
            spdlog::get(App::LOG)->debug("No GL errors found.");
        }
        return foundError;
    }
}