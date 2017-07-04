/*
 * CodeX Studio Copyright.
 */

#include "codeX_shader.h"

using namespace Base;
using namespace Shader;
using namespace Engine;

Shader::Shader(ShaderInfo* shaders)
{   
    program = OpenGL.LoadShaders(shaders);
    if (0 == program)
    {
        logger<<"Load shaders failed."<<std::endl;
        exit(EXIT_FAILURE);
    }
}


