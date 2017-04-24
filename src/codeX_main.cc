/*
 *
 */
#include <iostream>
#ifdef __APPLE__
#include <OPENGL/gl3.h>
#define __gl_h_
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/freeglut.h>
#endif
using namespace std;

void display_version()
{
    //openGL生产商及版本
    const char* vendorName = reinterpret_cast<const
        char*>(glGetString(GL_VENDOR));
    const char* version = reinterpret_cast<const
        char*>(glGetString(GL_VERSION));
    cout<<"vendorName:"<<vendorName<<endl;
    cout<<"version:"<<version<<endl;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
#ifdef __APPLE__
    glutInitDisplayMode(GLUT_RGBA|GLUT_3_2_CORE_PROFILE);
#else
    glutInitDisplayMode(GLUT_RGBA);
#endif
    glutCreateWindow("GLEW Test");//get an openGL context

    //openGL生产商及版本
    display_version();
    return 0;
}
