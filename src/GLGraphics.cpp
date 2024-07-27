#include "GLGraphics.h"

GLGraphics::GLGraphics() 
{

}

void GLGraphics::init() {
    if (SDL_Init(SDL_INIT_VIDEO != 0)) {
        SDL_LogError(1, "Error initializing SDL");
    }

    this->window = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
    if (this->window == NULL) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Couldn't create the main window.", NULL);
    }

    this->openGLContext = SDL_GL_CreateContext(this->window);
    if (this->openGLContext == NULL) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Couldn't create OpenGL context.", NULL);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    if(glewInit() != GLEW_OK) {
        std::cout << glewGetErrorString(glewInit()) << std::endl;
    }

    this->shaderProgram = this->CreateShaders();
    this->snake = new Snake();
}

void GLGraphics::update() {
    this->snake->Update();
    this->snake->Draw(this->shaderProgram);
    SDL_GL_SwapWindow(this->window);
}

void GLGraphics::MoveSnake(Key key) {
    this->snake->Move(key);
}

/*void GLGraphics::update(Key key) {
    this->snake->Update();
    this->snake->Draw(this->shaderProgram);
    SDL_GL_SwapWindow(this->window);
    std::cout << "moved image rendered" << std::endl;
}*/

GLuint GLGraphics::CreateShaders() {
    return loadShaders("../shaders/shader.vert", "../shaders/shader.frag");
}

void GLGraphics::exit() {
    glDeleteProgram(shaderProgram);
    SDL_GL_DeleteContext(this->openGLContext);
    SDL_DestroyWindow(window);
    delete this->snake;
    SDL_Quit();
}

