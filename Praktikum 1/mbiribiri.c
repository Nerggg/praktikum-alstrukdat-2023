#include <stdio.h>
#include <math.h>
#include "garis.h"
#include "boolean.h"

float jarak (GARIS L, POINT P) {
	float a = Gradien(L), b = -1, c = (Ordinat(PAwal(L)) - Gradien(L)*Absis(PAwal(L)));
	float atas = a * Absis(P) + b * Ordinat(P) + c;
	if (atas < 0) {
		atas *= -1;
	}
	float bawah = sqrt(pow(a, 2) + pow(b, 2));
	return (atas/(float)bawah);
}

int main () {
	float b;
	int i, jlh_sheep, save_count = 0;
	GARIS wolf;
	POINT sheep;
	scanf("%f", &b);
	scanf("%f %f", &Absis(PAwal(wolf)), &Ordinat(PAwal(wolf)));
	scanf("%f %f", &Absis(PAkhir(wolf)), &Ordinat(PAkhir(wolf)));	
	scanf("%d", &jlh_sheep);
	for (i = 0; i < jlh_sheep; i++) {
		scanf("%f %f", &Absis(sheep), &Ordinat(sheep));
		if (jarak(wolf, sheep) <= b) {
			save_count++;
		}
	}
	printf("%d\n", save_count);
}
