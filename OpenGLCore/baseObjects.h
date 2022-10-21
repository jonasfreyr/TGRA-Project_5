//
// Created by Sigmar Snær Sigurðsson on 21.10.2022.
//

#ifndef PROJECT5_BASEOBJECTS_H
#define PROJECT5_BASEOBJECTS_H
#include "vector"
#include "GLFW/glfw3.h"

class Cube {
public:
    std::vector<float> position_array;
    std::vector<float>  normal_array;

    void init();
    Cube();
    //void draw(Shader3D shader);
    void draw();
};

#endif //PROJECT5_BASEOBJECTS_H
