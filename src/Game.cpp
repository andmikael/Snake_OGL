#include "Game.h"
#include "GLGraphics.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game() 
{

}

void Game::initGame() {
    this->graphics->init();
}

void Game::runGame() {
    Game::initGame();
    this->isPlaying = true;
    SDL_Event event;

    while(this->isPlaying) {
        while(SDL_PollEvent(&event)) {
            this->captureInput(event);
        }

    }
}

void Game::captureInput(SDL_Event& e) {
    switch(e.type) {
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            //std::cout << "test" << std::endl;
            switch(e.key.keysym.scancode) {
                case SDL_SCANCODE_ESCAPE:
                    this->quit();
                    break;
            }
    }
}

void Game::setGraphics(GLGraphics* graphics) {
    this->graphics = graphics;
}

void Game::quit() {
    this->isPlaying = false;
}