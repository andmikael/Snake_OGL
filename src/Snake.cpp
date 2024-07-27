#include "Snake.h"
#include <iostream>

    GLfloat vertices[] = {
        -0.5f, -0.5f, 0,
        0, 0.5f, 0,
        0.5f, -0.5f, 0
    };

Snake::Snake() {
    pos = {
        glm::vec3(-0.5f, -0.5f, 0),
        glm::vec3(0, 0.5f, 0),
        glm::vec3(0.5f, -0.5f, 0)
    };

    glCreateVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //glBufferData(GL_ARRAY_BUFFER, pos.size() * sizeof(glm::vec3), pos.data(), GL_STATIC_DRAW);


    /*glCreateVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);*/
}

void Snake::Move(Key key) {
    switch(key) {
        case UP:
            vertices[1] += 0.05f;
            vertices[4] += 0.05f;
            vertices[7] += 0.05f;
            break;
        case DOWN:
            vertices[1] -= 0.05f;
            vertices[4] -= 0.05f;
            vertices[7] -= 0.05f;
            break;
        case LEFT:
            vertices[0] -= 0.05f;
            vertices[3] -= 0.05f;
            vertices[6] -= 0.05f;
            break;
            case RIGHT:
            vertices[0] += 0.05f;
            vertices[3] += 0.05f;
            vertices[6] += 0.05f;
            break;
    }
}

void Snake::Draw(GLuint shader) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    glUseProgram(0);
}

void Snake::Update() {
    glCreateVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}



Snake::~Snake() {
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}