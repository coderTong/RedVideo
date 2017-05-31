#include "RedGL/RedGL.hpp"

GLProgram::GLProgram()
{
    ProgramId = glCreateProgram();
}

void GLProgram::AddShader(GLShader * shader)
{
    ShaderList.push_back(shader);
}

void GLProgram::LinkProgram()
{
    int size = ShaderList.size();
    for(int i=0;i<size;i++){
        glAttachShader(ProgramId, ShaderList[i]->ShaderId);
    }

    glLinkProgram(ProgramId);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Check the program
    glGetProgramiv(ProgramId, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramId, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(ProgramId, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }
}
