/*
 * CodeX Studio Copyright.
 */
#include <iostream>
#include "codeX_opengl_wrapper.h"

using namespace std;
using namespace Graphic_Engine;

Graphic_Engine_GL GL;
enum VAO_IDs{Triangle, NumVAOs};
enum Buffer_IDs{ArrayBuffer, NumBuffers};
enum Attrib_IDs{vPosition = 0};
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
const GLuint NumVertices = 6;

void init()
{
    glGenVertexArrays(NumVAOs, VAOs);
    glBindVertexArray(VAOs[Triangle]);
    GLfloat vertices[NumVertices][2] =
    {
        {-0.90, -0.90},
        {0.85, -0.90},
        {-0.90, 0.85},
        {0.90, -0.85},
        {0.90, 0.90},
        {-0.85, 0.90}
    };
    glGenBuffers(NumBuffers, Buffers);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
#ifdef __APPLE__
    ShaderInfo shaders[] = {
        {GL_VERTEX_SHADER, "shader/vertext_mac.vert"},
        {GL_FRAGMENT_SHADER, "shader/fragment_mac.frag"},
        {GL_NONE, NULL}
#else
    ShaderInfo shaders[] = {
        {GL_VERTEX_SHADER, "shader/vertext_linux.vert"},
        {GL_FRAGMENT_SHADER, "shader/fragment_linux.frag"},
        {GL_NONE, NULL}
#endif
    };
    GLuint program = GL.LoadShaders(shaders);
    if (0 == program)
    {
        exit(EXIT_FAILURE);
    }
    glUseProgram(program);
    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(vPosition);
}

void display(void)
{
    GL.clear(GL_COLOR_BUFFER_BIT);
    glBindVertexArray(VAOs[Triangle]);
    glDrawArrays(GL_TRIANGLES, 0, NumVertices);
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
#ifdef __APPLE__
    glutInitDisplayMode(GLUT_RGBA|GLUT_3_2_CORE_PROFILE);
#else
    glutInitDisplayMode(GLUT_RGBA);
#endif
    glutInitWindowSize(512, 512);
    glutCreateWindow("Matrix.");

#ifndef __APPLE__
    if(GLEW_OK != glewInit())
    {
        cout<<"glew initialize error"<<endl;
        exit(EXIT_FAILURE);
    }
#endif
    GL.display_version();
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
