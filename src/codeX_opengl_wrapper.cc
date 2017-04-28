/*
 * CodeX Studio Copyright.
 */
#include "codeX_opengl_wrapper.h"

size_t
TypeSize(GLenum type)
{
    size_t size;
#define CASE(Enum, Count, Type) \
    case Enum: size = Count * sizeof(Type); break;
    switch(type)
    {
        CASE(GL_FLOAT, 1, GLfloat);
        default:
        fprintf(stderr, "Unknown type: 0x%x\n", type);
        exit(EXIT_FAILURE);
        break;
    }
#undef CASE
    return size;
}
