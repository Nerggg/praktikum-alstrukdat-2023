#include <stdio.h>
#include <math.h>
# include "point.h"

#ifndef M_PI
#define M_PI   3.14159265358979323846264338327950288
#endif

void CreatePoint (POINT * P, float X, float Y) {
	POINT s;
	Absis(s) = X;
	Ordinat(s) = Y;
	*P = s;
}

void BacaPOINT (POINT * P) {
	float x, y;
	scanf("%f %f", &x, &y);
	CreatePoint(P, x, y);
} 

void TulisPOINT (POINT P) {
	printf("(%f,%f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2) {
	if (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2)) {
		return true;
	}
	else {
		return false;
	}
}

boolean NEQ (POINT P1, POINT P2) {
	if (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2)) {
		return false;
	}
	else {
		return true;
	}
}

boolean IsOrigin (POINT P) {
	if (Absis(P) == 0 && Ordinat(P) == 0) {
		return true;
	}
	else {
		return false;
	}
}

boolean IsOnSbX (POINT P) {
	if (Ordinat(P) == 0) {
		return true;
	}
	else {
		return false;
	}
}

boolean IsOnSbY (POINT P) {
	if (Absis(P) == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Kuadran (POINT P) {
	if (Absis(P) > 0 && Ordinat(P) > 0) {
		return 1;
	}
	else if (Absis(P) < 0 && Ordinat(P) > 0) {
		return 2;
	}
	else if (Absis(P) < 0 && Ordinat(P) < 0) {
		return 3;
	}
	else if (Absis(P) > 0 && Ordinat(P) < 0) {
		return 4;
	}
}

POINT NextX (POINT P) {
	Absis(P)++;
	return P;
}

POINT NextY (POINT P) {
	Ordinat(P)++;
	return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
	Absis(P) += deltaX;
	Ordinat(P) += deltaY;
	return P;
}

POINT MirrorOf (POINT P, boolean SbX) {
	if (SbX == true) {
		Ordinat(P) *= -1;
	}
	else if (SbX == false) {
		Absis(P) *= -1;
	}
	return P;
}

float Jarak0 (POINT P) {
	return (sqrt(pow(Absis(P), 2) + (pow(Ordinat(P), 2))));
}

float Panjang (POINT P1, POINT P2) {
	return (sqrt(pow(Absis(P1) - Absis(P2), 2) + (pow(Ordinat(P1) - Ordinat(P2), 2))));
}

void Geser (POINT *P, float deltaX, float deltaY) {
	POINT s = *P;
	Absis(s) += deltaX;
	Ordinat(s) += deltaY;
	*P = s;
}

void GeserKeSbX (POINT *P) {
	POINT s = *P;
	Ordinat(s) = 0;
	*P = s;
}

void GeserKeSbY (POINT *P) {
	POINT s = *P;
	Absis(s) = 0;
	*P = s;
}

void Mirror (POINT *P, boolean SbX) {
	POINT s = *P;
	if (SbX == true) {
		Ordinat(s) *= -1;
	}
	else if (SbX == false) {
		Absis(s) *= -1;
	}
	*P = s;
}	

void Putar (POINT *P, float Sudut) {
	POINT s1 = *P, s2 = *P ;
	float radians = Sudut * M_PI / 180.0;
	Absis(s2) = Absis(s1) * cos(radians) - Ordinat(s1) * sin(radians);
	Ordinat(s2) = Absis(s1) * sin(radians) + Ordinat(s1) * cos(radians);
	*P = s2;
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2) {
	int m = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
	int b = Ordinat(P1) - m*Absis(P1);
	printf("(%d,%d)", m, b);
}
