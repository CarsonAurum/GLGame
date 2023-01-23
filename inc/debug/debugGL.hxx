//
// Carson R - 1/22/2023
//

#ifndef TITANOFAIR_DEBUGGL_HXX
#define TITANOFAIR_DEBUGGL_HXX

#include <GL/glew.h>

namespace TitanOfAir::utils
{
    void glPrintShaderLogs(GLuint shader);
    void glPrintProgramLog(GLuint program);
    //bool glCheckError();
}

#endif //TITANOFAIR_DEBUGGL_HXX
