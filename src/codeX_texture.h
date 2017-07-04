/*
 * CodeX Studio Copyright.
 */

#ifndef __CODEX_TEXTURE_H__
#define __CODEX_TEXTURE_H__
#include <iostream>
#include <SOIL/SOIL.h>
#include "codeX_opengl_wrapper.h"

namespace Assert
{
    class Texture
    {
        private:
            std::string filename;
            GLenum target;
            GLuint object;
            int image_width;
            int image_height;
            int image_channels;
            unsigned char* data;
        public:
            Texture(GLenum TextureTarget, const std::string& FileName);
            bool Load();
            void Bind(GLenum TextureUnit);
    };
}

#endif

