#pragma once
#include <iostream>
#include "core.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "Shader.h"
#include "Snake.h"


class GLGraphics {
    private:
        SDL_Window* window;
        SDL_GLContext openGLContext;
        Snake* snake;
        GLuint shaderProgram;
        
    public:
        GLGraphics();
        void init();
        void render();
        void update();
        void MoveSnake(Key key);
        //void update(Key key);
        GLuint CreateShaders();
        void exit();
};