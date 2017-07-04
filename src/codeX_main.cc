/*
 * CodeX Studio Copyright.
 */
#include <iostream>
#include "codeX_opengl_wrapper.h"
#include "codeX_mesh.h"

#define WINDOW_WIDTH  1920
#define WINDOW_HEIGHT 1200

using namespace std;
using namespace Engine;

enum VAO_IDs{Triangle, NumVAOs};
enum Buffer_IDs{ArrayBuffer, NumBuffers};
enum Attrib_IDs{vPosition = 0};
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

Assert::Mesh *m_pMesh = new Assert::Mesh();

void init()
{
#ifdef __APPLE__
    ShaderInfo shaders[] = {
        {GL_VERTEX_SHADER, "shader/vertext_mac.vert"},
        {GL_FRAGMENT_SHADER, "shader/fragment_mac.frag"},
        {GL_NONE, NULL}
    };
#else
    ShaderInfo shaders[] = {
        {GL_VERTEX_SHADER, "shader/vertext_linux.vert"},
        {GL_FRAGMENT_SHADER, "shader/fragment_linux.frag"},
        {GL_NONE, NULL}
    };
#endif
    GLuint program = OpenGL.LoadShaders(shaders);
    if (0 == program)
    {
        exit(EXIT_FAILURE);
    }
    glUseProgram(program);
    m_pMesh->LoadMesh("Assert/phoenix_ugv.md2");
}

void display(void)
{
    OpenGL.clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_pMesh->Render();
    glutSwapBuffers();
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
    OpenGL.display_version();
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
