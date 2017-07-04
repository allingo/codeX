/*
 * CodeX Studio Copyright.
 */

#include <iostream>
#include "codeX_texture.h"

using namespace Engine;
using namespace Assert;

/*
 * Texture Class
 */
Texture::Texture(GLenum TextureTarget, const std::string& FileName)
{
    filename = FileName;
    target = TextureTarget;
}

bool
Texture::Load()
{
    data = SOIL_load_image(filename.c_str(), &image_width,
            &image_height, &image_channels, SOIL_LOAD_AUTO);
    if (NULL == data)
    {
        logger<<"Load texture image failed."<<std::endl;
        logger.flush();
        return false;
    }

    glGenTextures(1, &object);
    glBindTexture(target, object);
    glTexImage2D(target, 0, GL_RGBA, image_width,
            image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameterf(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    
    glBindTexture(target, 0); 

    return true;
}

void
Texture::Bind(GLenum TextureUnit)
{
    glActiveTexture(TextureUnit);
    glBindTexture(target, object);
}

