/*
 * CodeX Studio Copyright.
 */
#ifndef __CODEX_OPENGL_WRAPPER_H__
#define __CODEX_OPENGL_WRAPPER_H__
#ifdef __APPLE__
#include <OPENGL/gl3.h>
#define __gl_h_
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/freeglut.h>
#endif
#include <fstream>

namespace Graphic_Engine
{
    typedef struct
    {
        GLenum       type;
        const char*  filename;
        GLuint       shader;
    } ShaderInfo;

    class Graphic_Engine_GL
    {
        private:
            std::fstream log;
            /* openGL生产商及版本 */
            const GLubyte* vendorName;
            const GLubyte* version;
            const GLubyte* renderer;
            const GLubyte* slversion;
            const GLchar* ReadShader(const char* filename);
        public:
            Graphic_Engine_GL();
            ~Graphic_Engine_GL();
            int TypeSize(GLenum type);
            void display_version();
            void clear(GLbitfield mask);
            GLuint LoadShaders(ShaderInfo* shaders);
    };
}
#endif
