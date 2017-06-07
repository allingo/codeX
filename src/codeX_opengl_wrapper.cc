/*
 * CodeX Studio Copyright.
 */
#include <iostream>
#include "codeX_opengl_wrapper.h"

using namespace Graphic_Engine;
std::fstream Graphic_Engine::logger;
/*
 * Graphic_Engine_GL Class
 */
Graphic_Engine_GL::Graphic_Engine_GL()
{
    logger.open("OpenGL.log", std::ios_base::out);
    if (!logger.is_open())
    {
        std::cout<<"Open log failed."<<std::endl;
        exit(EXIT_FAILURE);
    }
}

Graphic_Engine_GL::~Graphic_Engine_GL()
{
    logger.close();
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
        CASE(GL_FLOAT_VEC2, 2, GLfloat);
        CASE(GL_FLOAT_VEC3, 3, GLfloat);
        CASE(GL_FLOAT_VEC4, 4, GLfloat);
        CASE(GL_INT, 1, GLint);
        CASE(GL_INT_VEC2, 2, GLint);
        CASE(GL_INT_VEC3, 3, GLint);
        CASE(GL_INT_VEC4, 4, GLint);
        CASE(GL_UNSIGNED_INT, 1, GLuint);
        CASE(GL_UNSIGNED_INT_VEC2, 2, GLuint);
        CASE(GL_UNSIGNED_INT_VEC3, 3, GLuint);
        CASE(GL_UNSIGNED_INT_VEC4, 4, GLuint);
        CASE(GL_BOOL, 1, GLboolean);
        CASE(GL_BOOL_VEC2, 2, GLboolean);
        CASE(GL_BOOL_VEC3, 3, GLboolean);
        CASE(GL_BOOL_VEC4, 4, GLboolean);
        CASE(GL_FLOAT_MAT2, 4, GLfloat);
        CASE(GL_FLOAT_MAT2x3, 6, GLfloat);
        CASE(GL_FLOAT_MAT2x4, 8, GLfloat);
        CASE(GL_FLOAT_MAT3, 9, GLfloat);
        CASE(GL_FLOAT_MAT3x2, 6, GLfloat);
        CASE(GL_FLOAT_MAT3x4, 12, GLfloat);
        CASE(GL_FLOAT_MAT4, 16, GLfloat);
        CASE(GL_FLOAT_MAT4x2, 8, GLfloat);
        CASE(GL_FLOAT_MAT4x3, 12, GLfloat);
        default:
        std::cout<<"Unknown type:"<<type<<std::endl;
        exit(EXIT_FAILURE);
        break;
    }
#undef CASE
    return size;
}

void Graphic_Engine_GL::display_version()
{
    vendorName = glGetString(GL_VENDOR);
    version = glGetString(GL_VERSION);
    renderer = glGetString(GL_RENDERER);
    slversion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    logger<<"vendorName:"<<vendorName<<std::endl;
    logger<<"version:"<<version<<std::endl;
    logger<<"renderer:"<<renderer<<std::endl;
    logger<<"GLSL:"<<slversion<<std::endl;
    logger.flush();
}

void Graphic_Engine_GL::clear(GLbitfield mask)
{
    glClear(mask);
}

const GLchar* Graphic_Engine_GL::ReadShader(const char* filename)
{
    FILE* infile = fopen(filename, "rb");
    if (!infile)
    {
        logger << "Unable to open file '" << filename << "'" << std::endl;
        return NULL;
    }

    fseek(infile, 0, SEEK_END);
    int len = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    GLchar* source = new GLchar[len + 1];

    fread(source, 1, len, infile);
    fclose(infile);

    source[len] = 0;

    return const_cast<const GLchar*>(source);
}

GLuint Graphic_Engine_GL::LoadShaders(ShaderInfo* shaders)
{
    if (NULL == shaders) return 0;

    GLuint program = glCreateProgram();

    ShaderInfo* entry = shaders;
    while (entry->type != GL_NONE)
    {
        GLuint shader = glCreateShader(entry->type);

        entry->shader = shader;

        const GLchar* source = ReadShader(entry->filename);
        if (NULL == source)
        {
            for (entry = shaders; entry->type != GL_NONE; ++entry)
            {
                glDeleteShader(entry->shader);
                entry->shader = 0;
            }

            logger<<"source is NULL."<<std::endl;
            return 0;
        }

        glShaderSource(shader, 1, &source, NULL);
        delete [] source;

        glCompileShader(shader);

        GLint compiled;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled)
        {
            GLsizei len;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);

            GLchar* msg = new GLchar[len + 1];
            glGetShaderInfoLog(shader, len, &len, msg);
            logger << "Shader compilation failed: " << msg << std::endl;
            delete [] msg;
            return 0;
        }

        glAttachShader(program, shader);
        
        ++entry;
    }

    glLinkProgram(program);

    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked)
    {
        GLsizei len;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);

        GLchar* msg = new GLchar[len + 1];
        glGetProgramInfoLog(program, len, &len, msg);
        logger << "Shader linking failed: " << msg << std::endl;
        delete [] msg;
        for (entry = shaders; entry->type != GL_NONE; ++entry)
        {
            glDeleteShader(entry->shader);
            entry->shader = 0;
        }

        return 0;
    }

    return program;
}

