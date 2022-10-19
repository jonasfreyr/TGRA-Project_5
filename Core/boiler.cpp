//
// Created by jonas on 19.10.2022.
//
//
// Created by jonas on 22.8.2022.
//

#include "boiler.h"
#include "GLFW/glfw3.h"

Clock::Clock()
{
    last_tick = 0;
    glfwSetTime(0);
}

double Clock::Tick() {
    double now_tick = glfwGetTime() * 1000;
    double return_tick = now_tick - last_tick;
    last_tick = now_tick;
    return return_tick;
}

