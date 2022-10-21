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
    auto vert_shader = glCreateShader(GL_VERTEX_SHADER);
    auto shader_file = std::ifstream("./Shaders/simple3D.frag");
    std::string str;
    if (shader_file) {
        std::ostringstream ss;
        ss << shader_file.rdbuf(); // reading data
        str = ss.str();
        shader_file.close();
    } else throw std::exception();

    // glShaderSource(vert_shader, ,str, str.length());

}

void Shader3D::use() {

}
