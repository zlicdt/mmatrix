#include <iostream>
#include <vector>
#include <sstream>
#ifdef __GNUC__
#include <algorithm>
#endif
#include "define.h"
int main() {
    std::vector<std::vector<lfloat> >   _matrix;
    std::vector<std::vector<lfloat> >   __matrix;
    std::string                         __line;
    std::cout << "The first matrix: " << std::endl;
    while (std::getline(std::cin, __line)) {
        if (__line.empty()) break;
        std::istringstream              __stream(__line);
        std::vector<lfloat>             __row;
        lfloat                          __value;

        while (__stream >> __value) __row.push_back(__value);

        if (!__row.empty()) {
            _matrix.push_back(__row);
            rows_operator++;
        }
    }
    std::vector<unsigned>               _matrix_row_sizes;
    for (unsigned i = 0; i < rows_operator; i++) _matrix_row_sizes.push_back(_matrix[i].size());
    std::sort(_matrix_row_sizes.begin(), _matrix_row_sizes.end());
    _matrix_max_row_size = _matrix_row_sizes.back();
    for (int i = 0; i < rows_operator; i++) {
        if (_matrix[i].size() < _matrix_max_row_size) {
            for (int j = _matrix[i].size(); j < _matrix_max_row_size; j++) _matrix[i].push_back(0);
        }
    }
    for (unsigned i = 0; i < rows_operator; i++) {
        for (unsigned j = 0; j < _matrix[i].size(); j++) std::cout << _matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "The second matrix: " << std::endl;
    while (std::getline(std::cin, __line)) {
        if (__line.empty()) break;
        std::istringstream      __stream(__line);
        std::vector<lfloat>     __row;
        lfloat                  __value;

        while (__stream >> __value) __row.push_back(__value);

        if (!__row.empty()) {
            __matrix.push_back(__row);
            columns_operator++;
        }
    }
    std::vector<unsigned> __matrix_row_sizes;
    for (unsigned i = 0; i < columns_operator; i++) __matrix_row_sizes.push_back(__matrix[i].size());
    std::sort(__matrix_row_sizes.begin(), __matrix_row_sizes.end());
    __matrix_max_row_size = __matrix_row_sizes.back();
    for (int i = 0; i < columns_operator; i++) {
        if (__matrix[i].size() < __matrix_max_row_size) {
            for (int j = __matrix[i].size(); j < __matrix_max_row_size; j++) __matrix[i].push_back(0);
        }
    }
    for (unsigned i = 0; i < columns_operator; i++) {
        for (unsigned j = 0; j < __matrix[i].size(); j++) std::cout << __matrix[i][j] << " ";
        std::cout << std::endl;
    }
    if (_matrix[0].size() != __matrix.size()) {
        std::cout << "The matrices cannot be multiplied." << std::endl;
        return 0;
    }
    std::cout << "The result matrix: " << std::endl;
    for (int i = 0; i < rows_operator; i++) {
        for (int j = 0; j < __matrix_max_row_size; j++) {
            lfloat __sum = 0;
            for (int k = 0; k < _matrix_max_row_size; k++) __sum += _matrix[i][k] * __matrix[k][j];
            std::cout << __sum << " ";
        }
        std::cout << std::endl;
    }
}