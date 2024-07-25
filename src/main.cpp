#include <iostream>
#include "Game.h"
#include "GLGraphics.h"

int main() {
    Game game;
    GLGraphics* graphics = new GLGraphics();
    game.runGame();
    delete graphics;

    /*if (SDL_Init(SDL_INIT_VIDEO != 0)) {
        SDL_LogError(1, "Error initializing SDL");
        return -1;
    }

    std::cout << "SDL intialized" << std::endl;

    SDL_Window* window = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0); // when using opengl change 0 to SDL_WINDOW_OPENGL

    if (window == NULL) {
        SDL_LogError(1, "Error initializing window");
    }

    std::cout << "SDL window initialized" << std::endl;

    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0); // change possible flags for renderer if needed with opengl

    if (renderer == NULL) {
        SDL_LogError(1, "Error initializing window");
    }

    std::cout << "SDL renderer intialized" << std::endl;

    int quit = 1;
    SDL_Event event;

    while (quit != 0) {
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    quit = 0;
                    break;
                }
            default:
                continue;
        }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();*/
    return 0;    
}