//
// Created by jonas on 21.10.2022.
//

#include <sstream>
#include "Shader3D.h"

#if __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glew.h>
#endif

#include "fstream"

Shader3D::Shader3D() {
    // Vertex Shader
    auto vert_shader = glCreateShader(GL_VERTEX_SHADER);
    auto shader_file = std::ifstream("./Shaders/simple3D.vert");;
    std::string str;
    if (shader_file) {
        std::ostringstream ss;
        ss << shader_file.rdbuf(); // reading data
        str = ss.str();
        shader_file.close();
    }
    else exit(-1);

    const char *string = str.c_str();
    int length = str.length();
    glShaderSource(vert_shader, 1, &string, &length);
    glCompileShader(vert_shader);
    int result;
    glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &result);
    if (result != 1){
        perror("Couldn't compile vertex shader");;
        exit(-1);
    }

    // Fragment Shader
    auto frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    shader_file = std::ifstream("./Shaders/simple3D.frag");;
    if (shader_file){
        std::ostringstream ss;
        ss << shader_file.rdbuf(); // reading data
        str = ss.str();
        shader_file.close();
    }
    else exit(-1);
    string = str.c_str();
    length = str.length();
    glShaderSource(frag_shader, 1, &string, &length);
    glCompileShader(frag_shader);
    glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &result);
    if (result != 1){
        perror("Couldn't compile vertex shader");;
        exit(-1);
    }

    // Linking
    renderingProgramID = glCreateProgram();
    glAttachShader(renderingProgramID, vert_shader);
    glAttachShader(renderingProgramID, frag_shader);
    glLinkProgram(renderingProgramID);

    positionLoc = glGetAttribLocation(renderingProgramID, "a_position");
    glEnableVertexAttribArray(positionLoc);

    normalLoc = glGetAttribLocation(renderingProgramID, "a_normal");
    glEnableVertexAttribArray(normalLoc);



    modelMatrixLoc			= glGetUniformLocation(renderingProgramID, "u_model_matrix");


    projectionMatrixLoc = glGetUniformLocation(renderingProgramID, "u_projection_matrix");
    viewMatrixLoc = glGetUniformLocation(renderingProgramID, "u_view_matrix");


    matDifLoc = glGetUniformLocation(renderingProgramID, "u_material_diffuse");

    cameraPosLoc = glGetUniformLocation(renderingProgramID, "u_camera_position");

    matSpecLoc = glGetUniformLocation(renderingProgramID, "u_material_specular");
    shininessLoc = glGetUniformLocation(renderingProgramID, "u_shininess");


    matAmbientLoc = glGetUniformLocation(renderingProgramID, "u_material_ambient");

    lightAmountLoc = glGetUniformLocation(renderingProgramID, "light_amount");


}

void Shader3D::use() {
    try {
        glUseProgram(renderingProgramID);
    }
    catch(std::exception e)  {
        perror("Can't use");
        exit(-1);
    }
}

void Shader3D::set_model_matrix(std::vector<float> matrix_array) {
    float *new_array = &matrix_array[0];
    glUniformMatrix4fv(modelMatrixLoc, 1, true, new_array);
}

void Shader3D::set_projection_matrix(std::vector<float> matrix_array) {
    float *new_array = &matrix_array[0];
    glUniformMatrix4fv(projectionMatrixLoc, 1, true, new_array);
}

void Shader3D::set_view_matrix(std::vector<float> matrix_array) {
    float *new_array = &matrix_array[0];
    glUniformMatrix4fv(viewMatrixLoc, 1, true, new_array);
}

void Shader3D::set_position_attribute(std::vector<float> vertex_array) {
    float *new_array = &vertex_array[0];
    glVertexAttribPointer(positionLoc, 3, GL_FLOAT, false, 0, new_array);
}

void Shader3D::set_normal_attribute(std::vector<float> vertex_array) {
    float *new_array = &vertex_array[0];
    glVertexAttribPointer(normalLoc, 3, GL_FLOAT, false, 0, new_array);
}

void Shader3D::set_light_position(float x, float y, float z, int i) {
    std::string rusl = "u_light_positions[{" + std::to_string(i) + "}]";
    const char *string = rusl.c_str();

    auto loc = glGetUniformLocation(renderingProgramID, string);
    glUniform4f(loc, x, y, z, 1.0);
}

void Shader3D::set_material_diffuse(float r, float g, float b) {
    glUniform4f(matDifLoc, r, g, b, 0.0);
}

void Shader3D::set_light_diffuse(float r, float g, float b, int i) {
    std::string rusl = "u_light_diffuses[{" + std::to_string(i) + "}]";
    const char *string = rusl.c_str();

    auto loc = glGetUniformLocation(renderingProgramID, string);
    glUniform4f(loc, r, g, b, 1.0);
}

void Shader3D::set_camera_position(float x, float y, float z) {
    glUniform4f(cameraPosLoc, x, y, z, 1.0);
}

void Shader3D::set_light_specular(float r, float g, float b, int i) {
    std::string rusl = "u_light_speculars[{" + std::to_string(i) + "}]";
    const char *string = rusl.c_str();

    auto loc = glGetUniformLocation(renderingProgramID, string);
    glUniform4f(loc, r, g, b, 0.0);
}


void Shader3D::set_material_specular(float r, float g, float b) {
    glUniform4f(matSpecLoc, r, g, b, 0.0);
}


void Shader3D::set_material_shininess(float s) {
    glUniform1f(shininessLoc, s);
}

void Shader3D::set_light_ambient(float r, float g, float b, int i) {
    std::string rusl = "u_light_ambients[{" + std::to_string(i) + "}]";
    const char *string = rusl.c_str();

    auto loc = glGetUniformLocation(renderingProgramID, string);

    glUniform4f(loc, r, g, b, 0.0);
}

void Shader3D::set_material_ambient(float r, float g, float b) {
    glUniform4f(matAmbientLoc, r, g, b, 0.0);
}

void Shader3D::set_light_amount(int amount) {
    glUniform1i(lightAmountLoc, amount);
}









