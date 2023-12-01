#include "matrix.c"

int main() {
	Matrix mat;
	createMatrix(0, 0, &mat);
	readMatrix(&mat, 3, 3);
	printf("%f\n", determinant(mat));
}
