#include "Game.h"

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
        Game::updateGame();
    }
}

void Game::captureInput(SDL_Event& e) {
    switch(e.type) {
        case SDL_KEYDOWN:
            switch(e.key.keysym.scancode) {
                case SDL_SCANCODE_ESCAPE:
                    this->quit();
                    break;
                case SDL_SCANCODE_W:
                    this->graphics->MoveSnake(UP);
                    break;
                case SDL_SCANCODE_S:
                    this->graphics->MoveSnake(DOWN);
                    break;
                case SDL_SCANCODE_A:
                    this->graphics->MoveSnake(LEFT);
                    break;
                case SDL_SCANCODE_D:
                    this->graphics->MoveSnake(RIGHT);
                    break;
            }
    }
}

void Game::updateGame() {
    this->graphics->update();
}

void Game::setGraphics(GLGraphics* graphics) {
    this->graphics = graphics;
}

void Game::quit() {
    this->isPlaying = false;
    //this->graphics->exit();
}