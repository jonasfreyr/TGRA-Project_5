//
// Created by jonas on 21.10.2022.
//

#ifndef PROJECT5_SHADER3D_H
#define PROJECT5_SHADER3D_H


#include <vector>
#include "../Core/boiler.h"

class Shader3D {
private:
    GLint renderingProgramID;
    GLint positionLoc;
    GLint normalLoc;
    GLint modelMatrixLoc;
    GLint projectionMatrixLoc;
    GLint viewMatrixLoc;
    GLint matDifLoc;
    GLint cameraPosLoc;
    GLint matSpecLoc;
    GLint shininessLoc;
    GLint matAmbientLoc;
    GLint lightAmountLoc;
public:
    Shader3D();

    void use();

    void set_model_matrix(std::vector<float> matrix_array);
    void set_projection_matrix(std::vector<float>  matrix_array);
    void set_view_matrix(std::vector<float>  matrix_array);
    void set_position_attribute(std::vector<float>  vertex_array);
    void set_normal_attribute(std::vector<float>  vertex_array);

    void set_light_position(float x, float y, float z, int i);
    void set_material_diffuse(float r, float g, float b);
    void set_light_diffuse(float r, float g, float b, int i);

    void set_camera_position(float x, float y, float z);
    void set_light_specular(float r, float g, float b, int i);
    void set_material_specular(float r, float g, float b);
    void set_material_shininess(float s);
    void set_light_ambient(float r, float g, float b, int i);
    void set_material_ambient(float r, float g, float b);
    void set_light_amount(int amount);
};


#endif //PROJECT5_SHADER3D_H
