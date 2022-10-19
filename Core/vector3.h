//
// Created by jonas on 19.10.2022.
//

#ifndef PROJECT5_VECTOR3_H
#define PROJECT5_VECTOR3_H


class vector3 {
public:
    float x;
    float y;
    float z;

    vector3(float x, float y, float z);
    vector3 operator+(const vector3& other);
    vector3 operator-(const vector3& other);
    float operator*(const vector3& other);
    vector3 operator*(float scalar);

    float Length();
    vector3 Cross(vector3& other);
    void normalize();
};


#endif //PROJECT5_VECTOR3_H
