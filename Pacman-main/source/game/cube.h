#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>
#include "../engine/shader.h"
#include "../engine/matrix4.h"

class Cube{
    public:
    Cube();
    ~Cube();

    void load();
    void draw(Shader& shader);

    private:
    GLfloat vertexPositions[108];
    GLuint vao;
    GLuint buffer;

    Matrix4 transform;
};

#endif