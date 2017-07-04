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
#include "codeX_base.h"

namespace Engine
{
    struct ShaderInfo
    {
        GLenum       type;
        const char*  filename;
        GLuint       shader;
    };

    struct Vertex
    {
        Base::Vector3f m_pos;
        Base::Vector2f m_tex;
        Base::Vector3f m_normal;

        Vertex() {}

        Vertex(const Base::Vector3f& pos,
                const Base::Vector2f& tex,
                const Base::Vector3f& normal)
        {
            m_pos    = pos;
            m_tex    = tex;
            m_normal = normal;
        }
    };

    class Graphic_Engine
    {
        private:
            /* openGL生产商及版本 */
            const GLubyte* vendorName;
            const GLubyte* version;
            const GLubyte* renderer;
            const GLubyte* slversion;
            const GLchar* ReadShader(const char* filename);
        public:
            Graphic_Engine();
            ~Graphic_Engine();
            int TypeSize(GLenum type);
            void display_version();
            void clear(GLbitfield mask);
            GLuint LoadShaders(ShaderInfo* shaders);
    };

    extern std::fstream logger;
    extern Graphic_Engine OpenGL;
}
#endif
