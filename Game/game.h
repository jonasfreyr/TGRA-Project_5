//
// Created by jonas on 19.10.2022.
//
#include "GLFW/glfw3.h"
#ifndef PROJECT5_GAME_H
#define PROJECT5_GAME_H
class Game{
public:
    bool running;
    GLFWwindow* window;

    int init();
    Game();
    void Events();
    void Update(double delta_time);
    void Display();
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};
#endif //PROJECT5_GAME_H
