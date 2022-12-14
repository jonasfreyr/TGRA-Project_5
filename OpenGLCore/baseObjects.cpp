//
// Created by Sigmar Snær Sigurðsson on 21.10.2022.
//

#include "baseObjects.h"
#include "vector"


Sphere::Sphere(int stacks_inp, int slices_inp) {
    stacks = stacks_inp;
    slices = slices_inp;
    vertex_count = 0;
    vertex_array = {};

    float stack_interval = M_PI / stacks;
    float slice_interval = 2.0f * M_PI / slices;

    float stack_angle;
    float slice_angle;
    for (int stack_count = 0; stack_count < stacks; stack_count++) {
        stack_angle = stack_count * stack_interval;
        for (int slice_count = 0; slice_count < slices + 1; slice_count++) {
            slice_angle = slice_count * slice_interval;
            vertex_array.push_back(sin(stack_angle) * cos(slice_angle));
            vertex_array.push_back(cos(stack_angle));
            vertex_array.push_back(sin(stack_angle) * sin(slice_angle));

            vertex_array.push_back(sin(stack_angle + stack_interval) * cos(slice_angle));
            vertex_array.push_back(cos(stack_angle + stack_interval));
            vertex_array.push_back(sin(stack_angle + stack_interval) * sin(slice_angle));
            vertex_count += 2;
        }

    }
}


void Sphere::draw(Shader3D shader) {
    shader.set_position_attribute(vertex_array);
    shader.set_normal_attribute(vertex_array);

    for (int i = vertex_count; i < (slices + 1) * 2; i++) {
        glDrawArrays(GL_TRIANGLE_STRIP, i, (slices + 1) * 2);
    }

}


Cube::Cube() {
    position_array = {
            -0.5, -0.5, -0.5,
            -0.5, 0.5, -0.5,
            0.5, 0.5, -0.5,
            0.5, -0.5, -0.5,
            -0.5, -0.5, 0.5,
            -0.5, 0.5, 0.5,
            0.5, 0.5, 0.5,
            0.5, -0.5, 0.5,
            -0.5, -0.5, -0.5,
            0.5, -0.5, -0.5,
            0.5, -0.5, 0.5,
            -0.5, -0.5, 0.5,
            -0.5, 0.5, -0.5,
            0.5, 0.5, -0.5,
            0.5, 0.5, 0.5,
            -0.5, 0.5, 0.5,
            -0.5, -0.5, -0.5,
            -0.5, -0.5, 0.5,
            -0.5, 0.5, 0.5,
            -0.5, 0.5, -0.5,
            0.5, -0.5, -0.5,
            0.5, -0.5, 0.5,
            0.5, 0.5, 0.5,
            0.5, 0.5, -0.5};

    normal_array = {
            0.0, 0.0, -1.0,
            0.0, 0.0, -1.0,
            0.0, 0.0, -1.0,
            0.0, 0.0, -1.0,
            0.0, 0.0, 1.0,
            0.0, 0.0, 1.0,
            0.0, 0.0, 1.0,
            0.0, 0.0, 1.0,
            0.0, -1.0, 0.0,
            0.0, -1.0, 0.0,
            0.0, -1.0, 0.0,
            0.0, -1.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 1.0, 0.0,
            -1.0, 0.0, 0.0,
            -1.0, 0.0, 0.0,
            -1.0, 0.0, 0.0,
            -1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0
    };
}

void Cube::draw(Shader3D *shader) {

    shader->set_position_attribute(position_array);
    shader->set_normal_attribute(normal_array);

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDrawArrays(GL_TRIANGLE_FAN, 4, 4);
    glDrawArrays(GL_TRIANGLE_FAN, 8, 4);
    glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
    glDrawArrays(GL_TRIANGLE_FAN, 16, 4);
    glDrawArrays(GL_TRIANGLE_FAN, 20, 4);
}

