#include <iostream>
#include "Game.h"
#include "GLGraphics.h"

int main() {
    Game game;
    GLGraphics* graphics = new GLGraphics();
    game.setGraphics(graphics);
    game.runGame();
    game.quit();
    graphics->exit();
    delete graphics;
    return 0;    
}