/*
 * CodeX Studio Copyright.
 */
#include "codeX_opengl_wrapper.h"

using namespace Graphic_Engine;

Graphic_Engine_GL::Graphic_Engine_GL()
{
    log.open("OpenGL.log", std::ios_base::out);
}

Graphic_Engine_GL::~Graphic_Engine_GL()
{
    log.close();
}
int
Graphic_Engine_GL::TypeSize(GLenum type)
{
    int size;
#define CASE(Enum, Count, Type) \
    case Enum: size = Count * sizeof(Type); break;
    switch(type)
    {
        CASE(GL_FLOAT, 1, GLfloat);
        default:
        log<<"Unknown type: 0x" << std::hex << type << std::endl;
        size = -1;
        break;
    }
#undef CASE
    return size;
}
