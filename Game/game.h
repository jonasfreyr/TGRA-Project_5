//
// Created by jonas on 19.10.2022.
//

#ifndef PROJECT5_GAME_H
#include "../OpenGLCore/Shader3D.h"
#include "../Core/matrix.h"
#include "../Core/boiler.h"
#include "../OpenGLCore/baseObjects.h"
#define PROJECT5_GAME_H

class Game {
public:
    bool running;
    GLFWwindow *window;
    Shader3D *shader;

    ViewMatrix view_matrix;
    ProjectionMatrix projection_matrix;

    ModelMatrix model_matrix;

    Cube cube;

    void testing(); // remove this

    int init();

    Game();

    void Events();

    void Update(double delta_time);

    void Display();

    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
};

#endif //PROJECT5_GAME_H
