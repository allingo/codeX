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
#include <iostream>

extern size_t
TypeSize(GLenum type);
