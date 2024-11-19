#include "define.h"
void calc(int rows_m1, int columns_m2, int columns_m1, lfloat result[rows_m1][columns_m2], lfloat matrix_1[rows_m1][columns_m1], lfloat matrix_2[columns_m1][columns_m2]) {
    for(int i = 0; i < rows_m1; i++) {
        for(int j = 0; j < columns_m2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < columns_m1; k++) {
                result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
}