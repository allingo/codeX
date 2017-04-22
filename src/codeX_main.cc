/*
 *
 */
#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut.h>
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
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("GLEW Test");//get an openGL context

    //openGL生产商及版本
    display_version();
    return 0;
}
