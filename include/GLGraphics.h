#pragma once

#include <SDL2/SDL.h>

class GLGraphics {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        GLGraphics();
        void init();
        void render();
        void exit();
};