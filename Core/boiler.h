//
// Created by jonas on 19.10.2022.
//



#ifndef PROJECT5_BOILER_H
#include "GL/glew.h"
#if __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif
#include "GL/gl.h"
#include "GLFW/glfw3.h"




#define PROJECT5_BOILER_H

class Clock{
private:
    double last_tick;
public:
    Clock();
    double Tick();
};
#endif //PROJECT5_BOILER_H
