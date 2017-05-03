/*
 * CodeX Studio Copyright.
 */
#ifdef __APPLE__
#include <OPENGL/gl3.h>
#define __gl_h_
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/freeglut.h>
#endif
#include <fstream>

namespace Graphic_Engine
{
    class Graphic_Engine_GL
    {
        public:
            Graphic_Engine_GL();
            ~Graphic_Engine_GL();
            int TypeSize(GLenum type);
            std::fstream log;
    };
}
