#include "RedGL.hpp"

GLVAO::GLVAO()
{
    glGenVertexArrays(1, &VAOId);
}

GLVAO::~GLVAO()
{

}

void GLVAO::SetEBO(GLuint * EBOdata,int bufferSize)
{
    printf("Size:%d\n",bufferSize);
    glBindVertexArray(VAOId);

    glGenBuffers(1,&EBOId);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, EBOdata, GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void GLVAO::AddVBO(GLfloat * VBOdata,int bufferSize,int layout,int size)
{
    glBindVertexArray(VAOId);

    GLuint VBO;
    glGenBuffers(1,&VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, bufferSize, VBOdata, GL_STATIC_DRAW);

    glVertexAttribPointer(layout, size, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(layout);

    glBindVertexArray(0);
}

void GLVAO::DrawVAO()
{
    glBindVertexArray(0);

    glBindVertexArray(VAOId);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void GLVAO::DeleteVAO()
{
    glDeleteVertexArrays(1, &VAOId);
}


