#include <stdio.h>
#include "matrix.h"

void searchSubmatrix(Matrix m, int x, int y, int *max) {
    int i, j, k, l;
    for (i = 0; i <= (ROW_EFF(m) - y); i++) {
        for (j = 0; j <= (COL_EFF(m) - x); j++) {
            int sum = 0;
            for (k = i; k < (i + y); k++) {
                for (l = j; l < (j + x); l++) {
                    sum += ELMT(m, k, l);
                }
            }
            if (sum > *max) {
                *max = sum;
            }
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    Matrix mat;
    readMatrix(&mat, n, m);

    int i;
    int max = 0;
    for (i = 1; i <= k; i++) {
        if (k % i == 0) {
            int j = k / i;
            if (i > COL_EFF(mat) || j > ROW_EFF(mat)) {
                continue;
            }
            searchSubmatrix(mat, i, j, &max);
        }
    }

    printf("%d\n", max);
    return 0;
}