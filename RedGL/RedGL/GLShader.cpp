#include "RedGL.hpp"

GLShader::GLShader(GLenum type, const GLchar * src)
{
    ShaderId = glCreateShader(type);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Compile Shader
    printf("Compiling shader : %s\n", src);
    glShaderSource(ShaderId, 1, &src , NULL);
    glCompileShader(ShaderId);

    // Check Vertex Shader
    glGetShaderiv(ShaderId, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(ShaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(ShaderId, InfoLogLength, NULL, &ShaderErrorMessage[0]);
        printf("%s\n", &ShaderErrorMessage[0]);
    }
}

void GLShader::DeleteShader()
{
    glDeleteShader(ShaderId);
}
