#include "RedGL.hpp"
#include <SOIL.h>

GLTexture::GLTexture()
{
    glGenTextures(1, &TextureId);
    glBindTexture(GL_TEXTURE_2D, TextureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void GLTexture::LoadImage(char * filePath)
{
    glBindTexture(GL_TEXTURE_2D, TextureId);

    int width, height;
    unsigned char* image = SOIL_load_image(filePath, &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    printf("width:%d,height:%d\n",width,height);
    SOIL_free_image_data(image);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void GLTexture::SetData(unsigned char * data,int width,int height,GLenum internalFormat,GLenum format)
{
    glBindTexture(GL_TEXTURE_2D, TextureId);
    glBindTexture(GL_TEXTURE_2D, 0);
}
