//
// Created by jonas on 19.10.2022.
//

#include "matrix.h"

matrix::matrix(int rows, int cols) {
    auto matrix = std::vector<std::vector<float>>(rows);

    for (int i = 0; i < rows; i++){
        auto row = std::vector<float>(cols);
        matrix[i] = row;
    }
    _matrix = matrix;
    num_cols = cols;
    num_rows = rows;

}

matrix::matrix(std::vector<std::vector<float>> &matrix) {
    _matrix = matrix;
    num_rows = matrix.size();
    num_cols = matrix[0].size();
}
