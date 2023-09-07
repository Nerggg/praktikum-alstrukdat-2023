#include <stdio.h>
#include <math.h>
#include "../garis.h"

void CreateGaris (GARIS * L, POINT P1, POINT P2) {
	GARIS p;
	Absis(PAwal(p)) = Absis(P1);
	Ordinat(PAwal(p)) = Ordinat(P1);
	Absis(PAkhir(p)) = Absis(P2);
	Ordinat(PAkhir(p)) = Ordinat(P2);
	*L = p;
}

void BacaGARIS (GARIS * L) {
	POINT awal, akhir;
	scanf("%f %f", &Absis(awal), &Ordinat(awal));
	scanf("%f %f", &Absis(akhir), &Ordinat(akhir));	
	while (Absis(awal) == Absis(akhir) && Ordinat(awal) == Ordinat(akhir)) {
		printf("Garis tidak valid\n");
		scanf("%f %f", &Absis(awal), &Ordinat(awal));
		scanf("%f %f", &Absis(akhir), &Ordinat(akhir));
	}
	CreateGaris(L, awal, akhir);
}

void TulisGARIS (GARIS L) {
	printf("((%0.2f,%0.2f),(%0.2f,%0.2f))", Absis(PAwal(L)), Ordinat(PAwal(L)), Absis(PAkhir(L)), Ordinat(PAkhir(L)));
}

float PanjangGARIS (GARIS L) {
	return (sqrt(pow(Absis(PAwal(L)) - Absis(PAkhir(L)), 2) + pow(Ordinat(PAwal(L)) - Ordinat(PAkhir(L)), 2)));
}

float Gradien (GARIS L) {
	return ((Ordinat(PAkhir(L)) - Ordinat(PAwal(L)))/(float)(Absis(PAkhir(L)) - Absis(PAwal(L))));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY) {
	GARIS temp = *L;
	Absis(PAwal(temp)) += deltaX;
	Absis(PAkhir(temp)) += deltaX;
	Ordinat(PAwal(temp)) += deltaY;
	Ordinat(PAkhir(temp)) += deltaY;	
	*L = temp;
}

boolean IsTegakLurus (GARIS L1, GARIS L2) {
	if (Gradien(L1)*Gradien(L2) == -1) {
		return true;
	}
	else {
		return false;
	}
}

boolean IsSejajar (GARIS L1, GARIS L2) {
	if (Gradien(L1) == Gradien(L2)) {
		return true;
	}
	else {
		return false;
	}
}

float JarakGARIS (GARIS L, POINT P) {
	// y - y1 = m(x-x1)
	// y - y1 = mx - mx1
	// y - mx = y1 - mx1
	// mx - y = mx1 - y1
	// mx - y + (y1 - mx1) = 0
	// maka a = m, b = -1, c = (y1 - mx1)
	float a = Gradien(L), b = -1, c = (Ordinat(PAwal(L)) - Gradien(L)*Absis(PAwal(L)));
	float atas = a * Absis(P) + b * Ordinat(P) + c;
	if (atas < 0) {
		atas *= -1;
	}
	float bawah = sqrt(pow(a, 2) + pow(b, 2));
	return (atas/(float)bawah);
}

boolean IsPointMemenuhiGaris (GARIS L, POINT P) {
	float a = Gradien(L), b = -1, c = (Ordinat(PAwal(L)) - Gradien(L)*Absis(PAwal(L)));	
	if (a * Absis(P) + b * Ordinat(P) + c == 0) {
		return true;
	}
	else {
		return false;
	}
}

