/*
 * CodeX Studio Copyright.
 */

#ifndef __CODEX_SHADER_H__
#define __CODEX_SHADER_H__
#include "codeX_base.h"
#include "codeX_opengl_wrapper.h"

namespace Shader
{

    class Shader
    {
        public:
            Shader(ShaderInfo* shaders);
            ~Shader();
        private:
            GLuint program;
            Vector3f model_scale;
            Vector3f model_rotation;
            Vector3f model_position;
            Matrix4f model_transform_matix;
    }

}

#endif

