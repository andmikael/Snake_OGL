#include <iostream>
#include "GLGraphics.h"

GLGraphics::GLGraphics() 
{

}

void GLGraphics::init() {
    if (SDL_Init(SDL_INIT_VIDEO != 0)) {
        SDL_LogError(1, "Error initializing SDL");
    }

    SDL_Window* window = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0); // when using opengl change 0 to SDL_WINDOW_OPENGL

    if (window == NULL) {
        SDL_LogError(1, "Error initializing window");
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0); // change possible flags for renderer if needed with opengl

    if (renderer == NULL) {
        SDL_LogError(1, "Error initializing window");
    }
}

void GLGraphics::exit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

