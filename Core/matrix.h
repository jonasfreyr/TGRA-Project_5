//
// Created by jonas on 19.10.2022.
//

#ifndef PROJECT5_MATRIX_H
#define PROJECT5_MATRIX_H


#include <vector>

class matrix {
private:
    int num_cols = 0;
    int num_rows = 0;

    std::vector<std::vector<float>> _matrix;
public:
    matrix(std::vector<std::vector<float>> &matrix);
    matrix(int rows, int cols);

    int get_num_cols() const;
    int get_num_rows() const;

    std::vector<std::vector<float>> get_rows();
    float &operator [](int row, int col);
    std::vector<float> &operator [](int row);

    matrix operator+(const matrix &m);
    matrix operator-(const matrix &m);
    matrix operator*(const matrix &m);
    float& ToArray();


};


#endif //PROJECT5_MATRIX_H
