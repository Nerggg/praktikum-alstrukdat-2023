#include <stdio.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m) {
	
	ROW_EFF(*m) = nRows;
	COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j) {
	return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m) {
	return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matrix m) {
	return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
	return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
	return (ELMT(m, i, i));
}

void copyMatrix(Matrix mIn, Matrix *mOut) {
	createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
	int row, col;
	for (row = 0; row < ROW_EFF(mIn); row++) {
		for (col = 0; col < COL_EFF(mIn); col++) {
			ELMT(*mOut, row, col) = ELMT(mIn, row, col);
		}
	}
}

void readMatrix(Matrix *m, int nRow, int nCol) {
	createMatrix(nRow, nCol, m);
	int row, col;
	for (row = 0; row < nRow; row++) {
		for (col = 0; col < nCol; col++) {
			scanf("%d", &ELMT(*m, row, col));
		}
	}
}

void displayMatrix(Matrix m) {
	int row, col;
	for (row = 0; row < ROW_EFF(m); row++) {
		for (col = 0; col < COL_EFF(m) - 1; col++) {
			printf("%d ", ELMT(m, row, col));
		}
		printf("%d\n", ELMT(m, row, col));
	}
}

Matrix addMatrix(Matrix m1, Matrix m2) {
	Matrix hasil;
	createMatrix(ROW_EFF(m1), COL_EFF(m1), &hasil);
	int row, col;
	for (row = 0; row < ROW_EFF(m1); row++) {
		for (col = 0; col < COL_EFF(m1); col++) {
			ELMT(hasil, row, col) = ELMT(m1, row, col) + ELMT(m2, row, col);
		}
	}
	return hasil;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
	Matrix hasil;
	createMatrix(ROW_EFF(m1), ROW_EFF(m2), &hasil);
	int row, col;
	for (row = 0; row < ROW_EFF(m1); row++) {
		for (col = 0; col < COL_EFF(m1); col++) {
			ELMT(hasil, row, col) = ELMT(m1, row, col) - ELMT(m2, row, col);
		}
	}
	return hasil;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
	Matrix hasil;
	createMatrix(ROW_EFF(m1), COL_EFF(m2), &hasil);
	int i, j, k, temp;
	for (i = 0; i < ROW_EFF(hasil); i++) {
		for (j = 0; j < COL_EFF(hasil); j++) {
			temp = 0;
			for (k = 0; k < COL_EFF(hasil); k++) {
				temp += ELMT(m1, i, k) * ELMT(m2, k, j);
			}
			ELMT(hasil, i, j) = temp;
		}
	}
	return hasil;
}

Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod) {
	Matrix hasil;
	createMatrix(ROW_EFF(m1), COL_EFF(m2), &hasil);
	int i, j, k, temp;
	for (i = 0; i < ROW_EFF(hasil); i++) {
		for (j = 0; j < COL_EFF(hasil); j++) {
			temp = 0;
			for (k = 0; k < COL_EFF(hasil); k++) {
				temp += ELMT(m1, i, k) * ELMT(m2, k, j);
			}
			ELMT(hasil, i, j) = temp % mod;
		}
	}
	return hasil;
}

Matrix multiplyByConst(Matrix m, ElType x) {
	Matrix hasil;
	createMatrix(ROW_EFF(m), COL_EFF(m), &hasil);
	int i, j;
	for (i = 0; i < ROW_EFF(hasil); i++) {
		for (j = 0; j < COL_EFF(hasil); j++) {
			ELMT(hasil, i, j) *= x;
		}
	}
	return hasil;
}

void pMultiplyByConst(Matrix *m, ElType k) {
	int i, j;
	for (i = 0; i < ROW_EFF(*m); i++) {
		for (j = 0; j < COL_EFF(*m); j++) {
			ELMT(*m, i, j) *= k;
		}
	}
}

boolean isMatrixEqual(Matrix m1, Matrix m2) {
	if (countElmt(m1) == countElmt(m2) && getLastIdxCol(m1) == getLastIdxCol(m2)) {
		int i, j;
		for (i = 0; i < ROW_EFF(m1); i++) {
			for (j = 0; j < COL_EFF(m1); j++) {
				if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
					return false;
				}
			}
		}
	}
	return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
	if (countElmt(m1) == countElmt(m2) && getLastIdxCol(m1) == getLastIdxCol(m2)) {
		int i, j;
		for (i = 0; i < ROW_EFF(m1); i++) {
			for (j = 0; j < COL_EFF(m1); j++) {
				if (ELMT(m1, i, j) == ELMT(m2, i, j)) {
					return false;
				}
			}
		}
	}
	return true;
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
	return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(Matrix m){
	return (COL_EFF(m) * ROW_EFF(m));
}

boolean isSquare(Matrix m) {
	return (COL_EFF(m) == ROW_EFF(m));
}

boolean isSymmetric(Matrix m) {
	if (isSquare(m) == false) {
		return false;
	}
	else {
		int i, j;
		for (i = 0; i < ROW_EFF(m); i++) {
			for (j = 0; j < COL_EFF(m); j++) {
				if (ELMT(m, i, j) != ELMT(m, j, i)) {
					return false;
				}
			}		
		}
		return true;
	}
}

boolean isIdentity(Matrix m) {
	int i, j;
	for (i = 0; i < ROW_EFF(m); i++) {
		for (j = 0; j < COL_EFF(m); j++) {
			if (i == j) {
				if (ELMT(m, i, j) != 1) {
					return false;
				}
			}
			else {
				if (ELMT(m, i, j) != 0) {
					return false;
				}
			}
		}
	}
	return true;
}

boolean isSparse(Matrix m) {
	int i, j, batas = countElmt(m) * 5/100;
	int notzero = 0;
	for (i = 0; i < ROW_EFF(m); i++) {
		for (j = 0; j < COL_EFF(m); j++) {
			if (ELMT(m, i, j) != 0) {
				notzero++;
			}
		}
	}
	return (notzero <= batas);
}

Matrix negation(Matrix m) {
	return multiplyByConst(m, -1);
}

void pNegation(Matrix *m) {
	pMultiplyByConst(m, -1);
}

Matrix transpose(Matrix m) {
	Matrix temp = m;
	int i, j;
	for (i = 0; i < ROW_EFF(m); i++) {
		for (j = 0; j < COL_EFF(m); j++) {
			ELMT(m, j, i) = ELMT(temp, i, j);
		}
	}
	return m;
}

void pTranspose(Matrix *m) {
	Matrix temp = *m;
	int i, j;
	for (i = 0; i < ROW_EFF(*m); i++) {
		for (j = 0; j < COL_EFF(*m); j++) {
			ELMT(*m, j, i) = ELMT(temp, i, j);
		}
	}
}

int kofaktor(Matrix m, int baris, int kolom) {
	int n = COL_EFF(m), i;
	Matrix temp;
	createMatrix(n-1, n-1, &temp);
	int minorBaris = 0;
	for (i = 0; i < n; i++) {
		if (i == baris) {
			continue;
		}
		int minorKolom = 0;
		for (int j = 0; j < n; j++) {
			if (j == kolom) {
				continue;
			}
			ELMT(temp, minorBaris, minorKolom) = ELMT(m, i, j);
			minorKolom++;
		}
		minorBaris++;
	}
	if (baris + kolom % 2 == 0) {
		return determinant(temp);
	}
	else {
		return -1 * determinant(temp);
	}
}

float determinant(Matrix m) {
	int n = COL_EFF(m);
	if (n == 1) {
		return ELMT(m, 0, 0);
	}
	if (n == 2) {
		return ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0);
	}
	int i, det = 0;
	for (i = 0; i < n; i++) {
		det += ELMT(m, 0, i) * kofaktor(m, 0, i);
	}
	return det;
}
