//
// Created by jonas on 19.10.2022.
//

#include "game.h"
#include "../Core/boiler.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#if __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

Game::Game(){
    running = true;
    window = nullptr;
}

int Game::init() {
    /**
 * Makes a window and sets the current context to that window
 * Then sets the clear color
*/

    if (!glfwInit()) return 0;

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(100, 200, "Title", NULL, NULL);
    if (!window) {
        glfwTerminate();

        return 0;
    }

    glfwMakeContextCurrent(window);

    if (window == nullptr) return 0;

    glClearColor(0, 0, 0, 0);

    glfwSetWindowTitle(window, "3D Game");

    glEnable(GL_BLEND); //Enable blending.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.

    return 1;
}

void Game::Events() {

}

void Game::Update(double delta_time) {

}

void Game::Display() {

}
