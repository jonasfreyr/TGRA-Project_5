//
// Created by jonas on 19.10.2022.
//

#include "game.h"
#include "../Core/boiler.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <map>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

std::map<int, bool> key_pushed = {
        {GLFW_KEY_UP,    false},
        {GLFW_KEY_DOWN,  false},
        {GLFW_KEY_RIGHT, false},
        {GLFW_KEY_LEFT,  false},
        {GLFW_KEY_SPACE, false},
};


Game::Game() {
    running = true;
    window = nullptr;
    // shader = Shader3D();
    // shader.use();

    model_matrix = ModelMatrix();

    view_matrix = ViewMatrix();
    projection_matrix = ProjectionMatrix();

    shader.set_view_matrix(view_matrix.get_matrix());
    shader.set_projection_matrix(projection_matrix.get_matrix());
    projection_matrix.set_perspective(90, 16.0f / 9.0f, 1, 100);

    model_matrix = ModelMatrix();

    cube = Cube();
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

void Game::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    return;
}

void Game::Events() {
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        key_pushed[GLFW_KEY_UP] = true;
    } else {
        key_pushed[GLFW_KEY_UP] = false;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        key_pushed[GLFW_KEY_DOWN] = true;
    } else {
        key_pushed[GLFW_KEY_DOWN] = false;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        key_pushed[GLFW_KEY_RIGHT] = true;
    } else {
        key_pushed[GLFW_KEY_RIGHT] = false;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        key_pushed[GLFW_KEY_LEFT] = true;
    } else {
        key_pushed[GLFW_KEY_LEFT] = false;
    }


}

void Game::Update(double delta_time) {
    //glfwSetKeyCallback(window, key_callback);
    Events();

}

void Game::testing() {

    model_matrix.push_matrix();
    model_matrix.add_translation(0, 0, -3);
    model_matrix.add_scale(2, 2, 2);
    model_matrix.add_rotation(45, 0, 0);
    shader.set_model_matrix(model_matrix.matrix);
    shader.set_view_matrix(view_matrix.get_matrix());

    shader.set_material_diffuse(1, 0, 0);
    shader.set_material_specular(1, 1, 1);
    cube.draw(shader);
    //shader.set_material_ambient(.1, 0, 0);
}


void Game::Display() {
    glEnable(GL_DEPTH_TEST);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, 800, 600);

    shader.set_light_position(0, 5, 5, 0);
    shader.set_camera_position(view_matrix.eye.x, view_matrix.eye.y, view_matrix.eye.z);
    shader.set_light_diffuse(1, 1, 1, 0);
    shader.set_light_specular(1, 1, 1, 0);
    shader.set_light_ambient(0.5, 0.5, 0.5, 0);


}
