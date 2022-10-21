//
// Created by jonas on 19.10.2022.
//

#ifndef PROJECT5_MATRIX_H
#define PROJECT5_MATRIX_H


#include <vector>
#include "vector3.h"

class ModelMatrix{
private:
    std::vector<float> matrix;

    std::vector<std::vector<float>> stack;
    int stack_count = 0;
    int stack_capacity = 0;
public:
    ModelMatrix();
    void load_identity();
    std::vector<float> copy_matrix();
    void add_transformation(std::vector<float> &matrix2);
    void add_translation(float x, float y, float z);
    void add_scale(float x, float y, float z);
    void add_rotation(float x, float y, float z);
    void push_matrix();
    void pop_matrix();
};

class ViewMatrix{
private:
    vector3 eye = vector3(0, 0, 0);
    vector3 u = vector3(1, 0, 0);
    vector3 v = vector3(0, 1, 0);
    vector3 n = vector3(0, 0, 1);
public:
    void look(vector3 new_eye, vector3 center, vector3 up);
    void slide(float delU, float  delV, float delN);
    void roll(float angle);
    void yaw(float angle);
    void pitch(float angle);
    std::vector<float> get_matrix();
};

class ProjectionMatrix{
private:
    float left = -1;
    float right = 1;
    float bottom = -1;
    float top = 1;
    float near = -1;
    float far = 1;
public:
    void set_perspective(float fovy, float aspect, float N, float F);
    std::vector<float> get_matrix();
};

#endif //PROJECT5_MATRIX_H
