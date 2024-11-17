#include <stdio.h>
int main() {
    for(;;) {
        printf("Rows of the first matrix: ");
        int rows_m1;
        int columns_m1;
        int columns_m2;
        scanf("%d", &rows_m1);
        printf("Columns of the first matrix: ");
        scanf("%d", &columns_m1);
        int matrix_1[rows_m1][columns_m1];
        printf("Columns of the second matrix: ");
        scanf("%d", &columns_m2);
        int matrix_2[columns_m1][columns_m2];
        int result[rows_m1][columns_m2];
        for(int i = 0; i < rows_m1; i++) {
            for(int j = 0; j < columns_m1; j++) {
                printf("Element [%d][%d] of the first matrix: ", i, j);
                scanf("%d", &matrix_1[i][j]);
            }
        }
        for(int i = 0; i < columns_m1; i++) {
            for(int j = 0; j < columns_m2; j++) {
                printf("Element [%d][%d] of the second matrix: ", i, j);
                scanf("%d", &matrix_2[i][j]);
            }
        }
        for(int i = 0; i < rows_m1; i++) {
            for(int j = 0; j < columns_m2; j++) {
                result[i][j] = 0;
                for(int k = 0; k < columns_m1; k++) {
                    result[i][j] += matrix_1[i][k] * matrix_2[k][j];
                }
            }
        }
        for (int i = 0; i < rows_m1; i++) {
            for (int j = 0; j < columns_m2; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}