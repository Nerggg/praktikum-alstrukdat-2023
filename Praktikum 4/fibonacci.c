#include <stdio.h>
#include "matrix.h"

Matrix pangkat(Matrix m, long long int power, int mod) {
    if (power == 0) {
        Matrix identity;
        createMatrix(2, 2, &identity);
        ELMT(identity, 0, 0) = 1;
        ELMT(identity, 1, 1) = 1;
        ELMT(identity, 0, 1) = 0;
        ELMT(identity, 1, 0) = 0;
        return identity;
    }
    else if (power == 1) {
        return m;
    }
    else{
        Matrix m2 = pangkat(m, power/2, mod);
        Matrix hasil = multiplyMatrixWithMod(m2, m2, mod);
        if (power % 2 == 1) {
            hasil = multiplyMatrixWithMod(hasil, m, mod);
        }    
        return hasil;
    }
}

int main() {
    long long int k;
    Matrix mat;
    createMatrix(2, 2, &mat);
    ELMT(mat, 0, 0) = 1;
    ELMT(mat, 0, 1) = 1;
    ELMT(mat, 1, 0) = 1;
    ELMT(mat, 1, 1) = 0;
    scanf("%lld", &k);
    mat = pangkat(mat, k-1, 2003);
    printf("%lld\n", ELMT(mat, 0, 0));
}
