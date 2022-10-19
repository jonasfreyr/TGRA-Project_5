//
// Created by jonas on 19.10.2022.
//

#include "vector3.h"
#include <cmath>

vector3::vector3(float x, float y, float z) {
    this->x=x;
    this->y=y;
    this->z=z;
}

vector3 vector3::operator+(const vector3 &other) {
    return {x+other.x, y+other.y, z+other.z};
}

vector3 vector3::operator-(const vector3 &other) {
    return {x-other.x, y-other.y, z-other.z};
}

vector3 vector3::operator*(float scalar) {
    return {x*scalar, y*scalar, z*scalar};
}

float vector3::operator*(const vector3 &other) {
    return x*other.x + y*other.y + z*other.z;
}

float vector3::Length() {
    return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

vector3 vector3::Cross(vector3& other) {
    return {y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x};
}

void vector3::normalize() {
    float len = Length();
    x /= len;
    y /= len;
    z /= len;
}