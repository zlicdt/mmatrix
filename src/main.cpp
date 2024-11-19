#include <iostream>
#include <vector>
#include "define.h"

int main() {
    while(true) {
        std::cout << "Rows of the first matrix(any non-number to exit): ";
        if (!(std::cin >> rows_m1)) return 0;
        std::cout << "Columns of the first matrix: ";
        std::cin >> columns_m1;
        std::vector<std::vector<lfloat> > matrix_1(rows_m1, std::vector<lfloat>(columns_m1));
        std::cout << "Rows of the second matrix: " << columns_m1 << std::endl;
        std::cout << "Columns of the second matrix: ";
        std::cin >> columns_m2;
        std::vector<std::vector<lfloat> > matrix_2(columns_m1, std::vector<lfloat>(columns_m2));
        std::vector<std::vector<lfloat> > result(rows_m1, std::vector<lfloat>(columns_m2));
        for(int i = 0; i < rows_m1; i++) {
            for(int j = 0; j < columns_m1; j++) {
                std::cout << "Element [" << i << "][" << j << "] of the first matrix: ";
                std::cin >> matrix_1[i][j];
            }
        }
        for(int i = 0; i < columns_m1; i++) {
            for(int j = 0; j < columns_m2; j++) {
                std::cout << "Element [" << i << "][" << j << "] of the second matrix: ";
                std::cin >> matrix_2[i][j];
            }
        }
        std::cout << "Two matrixes are: " << std::endl;
        for(int i = 0; i < rows_m1; i++) {
            for(int j = 0; j < columns_m1; j++) {
                std::cout << matrix_1[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for(int i = 0; i < columns_m1; i++) {
            for(int j = 0; j < columns_m2; j++) {
                std::cout << matrix_2[i][j] << " ";
            }
            std::cout << std::endl;
        }
        for(int i = 0; i < rows_m1; i++) {
            for(int j = 0; j < columns_m2; j++) {
                result[i][j] = 0;
                for(int k = 0; k < columns_m1; k++) {
                    result[i][j] += matrix_1[i][k] * matrix_2[k][j];
                }
            }
        }
        std::cout << "The result matrix is: " << std::endl;
        for (int i = 0; i < rows_m1; i++) {
            for (int j = 0; j < columns_m2; j++) {
                std::cout << result[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}