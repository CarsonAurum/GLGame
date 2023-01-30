//
// Carson R - 1/22/2023
//

#ifndef TITANOFAIR_DEBUGGL_HXX
#define TITANOFAIR_DEBUGGL_HXX

#include <glad/glad.h>

namespace TitanOfAir::utils
{
    /**
     * Access the logs for a given OpenGL shader.
     * @param shader The shader whose info should be queried.
     * @post The log data is written to the [debug] priority within the general logger.
     */
    void glPrintShaderLogs(GLuint shader);

    /**
     * Access the logs for a given OpenGL program.
     * @param program The program whose info should be queried.
     * @post The log data is written to the [debug] priority within the general logger.
     */
    void glPrintProgramLog(GLuint program);

    /**
     * Check for *any* errors within the OpenGL error mask.
     * @return `true` if any error is detected, `false` otherwise.
     */
    bool glCheckError();
}

#endif //TITANOFAIR_DEBUGGL_HXX
