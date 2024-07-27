#pragma once

#include "core.h"

class Snake {
    private:
        uint32_t VAO;
        uint32_t VBO;
        std::vector<glm::vec2> pos;
    public:
        Snake();
        ~Snake();

        void Move(Key key);
        void Draw(GLuint shader);
        void Update();
};