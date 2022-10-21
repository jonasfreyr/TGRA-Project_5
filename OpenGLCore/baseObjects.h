//
// Created by Sigmar Snær Sigurðsson on 21.10.2022.
//

#ifndef PROJECT5_BASEOBJECTS_H
#define PROJECT5_BASEOBJECTS_H

#include "vector"
#include "cmath"
#include "GLFW/glfw3.h"
#include "Shader3D.h"
#include "../Core/matrix.h"

class Sphere {
public:
    int slices;
    int stacks;
    int vertex_count;
    std::vector<float> vertex_array;

    void init(int stacks_inp, int slices_inp);

    Sphere();

    void draw(Shader3D shader);

    void init_openGL(Shader3D shader, ModelMatrix model);
};

class Cube {
public:
    std::vector<float> position_array;
    std::vector<float> normal_array;

    void init();

    Cube();

    void draw(Shader3D shader);

};

#endif //PROJECT5_BASEOBJECTS_H
