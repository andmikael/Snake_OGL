#pragma once 

#include "GLGraphics.h"
#include <iostream>

class Game {
    private:
        GLGraphics* graphics;
        bool isPlaying = false;
    public:
        Game();
        void initGame();
        void runGame();
        void captureInput(SDL_Event& e);
        void updateGame();
        void renderGame();
        void setGraphics(GLGraphics* graphics);
        void quit();
};