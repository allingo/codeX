/*
 * CodeX Studio Copyright.
 */
#include <iostream>
#include "codeX_opengl_wrapper.h"

using namespace std;

void display_version()
{
    //openGL生产商及版本
    const GLubyte* vendorName = glGetString(GL_VENDOR);
    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* slversion =
        glGetString(GL_SHADING_LANGUAGE_VERSION);
    cout<<"vendorName:"<<vendorName<<endl;
    cout<<"version:"<<version<<endl;
    cout<<"renderer:"<<renderer<<endl;
    cout<<"GLSL:"<<slversion<<endl;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
#ifdef __APPLE__
    glutInitDisplayMode(GLUT_RGBA|GLUT_3_2_CORE_PROFILE);
#else
    glutInitDisplayMode(GLUT_RGBA);
#endif
    glutCreateWindow("Matrix.");//get an openGL context

    //openGL生产商及版本
    display_version();
    return 0;
}
