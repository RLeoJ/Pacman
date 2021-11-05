#include "../engine/game.h"
#include "../engine/texture.h"

#include <cstdlib>
#include <ctime>
#include <cmath>

Game::Game() : isRunning(false), windowWidth(0), windowHeight(0) {}

Game::~Game() {}

void Game::init(int screenWidth, int screenHeight) {
    windowWidth = screenWidth;
    windowHeight = screenHeight;
    isRunning = true;
}

void Game::load() {
    cube = Cube();
    cube.load();

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    shader.compileVertexShader();
    shader.compileFragmentShader();
    shader.createShaderProgram();

    shader.use();
}

void Game::handleInputs() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    isRunning = false;
                }
                break;

            default:
                break;
        }
    }
}

void Game::update(float dt) {
    timeSinceStart += dt;
    const float t = timeSinceStart * 0.3f;
}

void Game::render() {
    static const GLfloat bgColor[] = {0.0f, 0.0f, 0.2f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);

    cube.draw(shader);
    
    shader.setMatrix4("proj_matrix", projection);
}

void Game::clean() {
    glDeleteVertexArrays(1, &vao);
}