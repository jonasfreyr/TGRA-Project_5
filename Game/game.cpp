//
// Created by jonas on 19.10.2022.
//

#include "game.h"
#include "../Core/boiler.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <map>

#if __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

std::map<int, bool> key_pushed = {
        {GLFW_KEY_UP, false},
        {GLFW_KEY_DOWN, false},
        {GLFW_KEY_RIGHT, false},
        {GLFW_KEY_LEFT, false},
};


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

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Title", NULL, NULL);
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

void Game::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    return;
}

void Game::Events() {
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        key_pushed[GLFW_KEY_UP] = true;
    }else{
        key_pushed[GLFW_KEY_UP] = false;
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        key_pushed[GLFW_KEY_DOWN] = true;
    }else{
        key_pushed[GLFW_KEY_DOWN] = false;
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        key_pushed[GLFW_KEY_RIGHT] = true;
    }else{
        key_pushed[GLFW_KEY_RIGHT] = false;
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        key_pushed[GLFW_KEY_LEFT] = true;
    }else{
        key_pushed[GLFW_KEY_LEFT] = false;
    }


}

void Game::Update(double delta_time) {
    //glfwSetKeyCallback(window, key_callback);
    Events();

}

void Game::Display() {
    glEnable(GL_DEPTH_TEST);

    /*
    shader.set_light_position(0, 5, 5);
    shader.set_camera_position(self.view_matrix.eye.x, self.view_matrix.eye.y, self.view_matrix.eye.z)
    shader.set_light_diffuse(1, 1, 1)
    shader.set_light_specular(1, 1, 1)
    shader.set_light_ambient(0.5, 0.5, 0.5)
    */

}
