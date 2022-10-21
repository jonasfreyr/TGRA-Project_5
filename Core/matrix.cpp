//
// Created by jonas on 19.10.2022.
//

#include "matrix.h"
#include <cmath>
#include <iostream>

ModelMatrix::ModelMatrix() {
    int counter = 0;
    for (int i = 0; i < 16; ++i) {
        if (counter == 0){
            matrix.push_back(1);
            counter = 4;
        }
        else {
            matrix.push_back(0);
            counter--;
        }
    }
}

void ModelMatrix::load_identity() {
    int counter = 0;
    for (float & i : matrix) {
        if (counter == 0){
            i = 1;
            counter = 4;
        }
        else {
            i = 0;
            counter--;
        }
    }
}

std::vector<float> ModelMatrix::copy_matrix() {
    std::vector<float> new_matrix;
    for (float & i : matrix){
        new_matrix.push_back(i);
    }

    return new_matrix;
}

void ModelMatrix::add_transformation(std::vector<float> &matrix2) {
    int counter = 0;
    float new_matrix[16] {};

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            for (int i = 0; i < 4; ++i) {
                new_matrix[counter] += matrix[row*4 + i]*matrix2[col + 4*i];
            }
            counter++;
        }
    }

    for (int i = 0; i < 16; ++i) {
        matrix[i] = new_matrix[i];
    }

}

void ModelMatrix::add_translation(float x, float y, float z) {
    std::vector<float> m = {
            1, 0, 0, x,
            0, 1, 0, y,
            0, 0, 1, z,
            0, 0, 0, 1
    };

    add_transformation(m);
}

void ModelMatrix::add_scale(float x, float y, float z) {
    std::vector<float> m = {
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1
    };

    add_transformation(m);
}

void ModelMatrix::add_rotation(float x, float y, float z) {
    static const float halfC = M_PI / 180;
    x = x * halfC;
    y = y * halfC;
    z = z * halfC;

    std::vector<float> matrix_x = {
            1, 0, 0, 0,
            0, cosf(x), -sinf(x), 0,
            0, sinf(x), cosf(x), 0,
            0, 0, 0, 1
    };

    std::vector<float> matrix_y = {
            cosf(y), 0, sinf(y), 0,
            0, 1, 0, 0,
            -sinf(y), 0, cosf(y), 0,
            0, 0, 0, 1
    };

    std::vector<float> matrix_z = {
            cosf(z), -sinf(z), 0, 0,
            sinf(z), cosf(z), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
    };

    add_transformation(matrix_x);
    add_transformation(matrix_y);
    add_transformation(matrix_z);
}

void ModelMatrix::push_matrix() {
    stack.push_back(copy_matrix());
}

void ModelMatrix::pop_matrix() {
    matrix = stack.back();
    stack.pop_back();
}


void ViewMatrix::look(vector3 new_eye, vector3 center, vector3 up) {
    eye = new_eye;
    n = eye - center;
    u = up.Cross(n);
    v = n.Cross(u);
}

void ViewMatrix::slide(float delU, float delV, float delN) {
    eye.x += delU * u.x + delV * v.x + delN * n.x;
    eye.y += delU * u.y + delV * v.y + delN * n.y;
    eye.y += delU * u.z + delV * v.z + delN * n.z;
}

void ViewMatrix::roll(float angle) {
    static const float halfC = M_PI / 180;
    angle = angle * halfC;
    float angCos = cosf(angle);
    float angSin = sinf(angle);

    vector3 t = u * 1;
    u = (t * angCos) + (v * angSin);
    v = (t * -angSin) + (v * angCos);
}

void ViewMatrix::yaw(float angle) {
    static const float halfC = M_PI / 180;
    angle = angle * halfC;
    float angCos = cosf(angle);
    float angSin = sinf(angle);

    vector3 t = u * 1;
    u = (t *  angCos) + (n * angSin);
    n = (t * -angSin) + (n * angCos);
}

void ViewMatrix::pitch(float angle) {
    static const float halfC = M_PI / 180;
    angle = angle * halfC;
    float angCos = cosf(angle);
    float angSin = sinf(angle);

    vector3 t = v * 1;
    v = (t * angCos) + (n * angSin);
    n = (t * -angSin) + (n * angCos);
}

std::vector<float> ViewMatrix::get_matrix() {
    vector3 minusEye = vector3(-this->eye.x, -this->eye.y, -this->eye.z);
    return std::vector<float> {
        u.x, u.y, u.z, minusEye * u,
        v.x, v.y, v.z, minusEye * v,
        n.x, n.y, n.z, minusEye * n,
        0,   0,   0,   1
    };
}

void ProjectionMatrix::set_perspective(float fovy, float aspect, float N, float F) {
    static const float halfC = M_PI / 180;
    fovy = fovy * halfC;

    std::cout << aspect << std::endl;

    top = N * tanf(fovy / 2);
    bottom = -top;
    right = top * aspect;
    left = -right;
    near = N;
    far = F;

    std::cout << top << std::endl;
    std::cout << bottom << std::endl;
    std::cout << right << std::endl;
    std::cout << left << std::endl;
    std::cout << near << std::endl;
    std::cout << far << std::endl;
    std::cout << "-----" << std::endl;
}

std::vector<float> ProjectionMatrix::get_matrix() {
    float _0_0 = (2 * near) / (right - left);
    float  _0_2 = (right + left) / (right - left);
    float _1_1 = (2 * near) / (top - bottom);
    float _1_2 = (top + bottom) / (top - bottom);
    float _2_2 = -(far + near) / (far - near);
    float _2_3 = (-2 * far * near) / (far - near);

    return std::vector<float> {
            _0_0, 0,    _0_2, 0,
            0,    _1_1, _1_2, 0,
            0,    0,    _2_2, _2_3,
            0,    0,    -1,   0};
}
