#include <stdio.h>
#include "datetime.h"

int GetMaxDay(int M, int Y) {
	if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
		return 31;
	}
	else if (M == 4 || M == 6 || M == 9 || M == 11) {
		return 30;
	}
	else if (M == 2) {
		if (Y % 400 == 0) {
			return 29;
		}
		else {
			if (Y % 100 == 0) {
				return 28;
			}
			else {
				if (Y % 4 == 0) {
					return 29;
				}
				else {
					return 28;
				}
			}
		}
	}
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s) {
	if (IsTIMEValid(h, m, s) == true) {
		if (M <= 12 && M >= 1) {
			if (D <= GetMaxDay(M, Y)) {
				return true;
			}
		}
	}	
	return false;
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss) {
	DATETIME temp;
	Day(temp) = DD;
	Month(temp) = MM;
	Year(temp) = YYYY;
	Hour(Time(temp)) = hh;
	Minute(Time(temp)) = mm;
	Second(Time(temp)) = ss;
	*D = temp;
}

void BacaDATETIME(DATETIME *D) {
	DATETIME temp;
	scanf("%d %d %d %d %d %d", &Day(temp), &Month(temp), &Year(temp), &Hour(Time(temp)), &Minute(Time(temp)), &Second(Time(temp)));
	while (IsDATETIMEValid(Day(temp), Month(temp), Year(temp), Hour(Time(temp)), Minute(Time(temp)), Second(Time(temp))) == false) {
		printf("DATETIME tidak valid\n");
		scanf("%d %d %d %d %d %d", &Day(temp), &Month(temp), &Year(temp), &Hour(Time(temp)), &Minute(Time(temp)), &Second(Time(temp)));
	}
	CreateDATETIME(D, Day(temp), Month(temp), Year(temp), Hour(Time(temp)), Minute(Time(temp)), Second(Time(temp)));
}

void TulisDATETIME(DATETIME D) {
	printf("%02d/%02d/%04d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

boolean DEQ(DATETIME D1, DATETIME D2) {
	if (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && Hour(Time(D1)) == Hour(Time(D2)) && Minute(Time(D1)) == Minute(Time(D2)) && Second(Time(D1)) == Second(Time(D2))) {
		return true;
	}
	else {
		return false;
	}
}

boolean DNEQ(DATETIME D1, DATETIME D2) {
	if (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && Hour(Time(D1)) == Hour(Time(D2)) && Minute(Time(D1)) == Minute(Time(D2)) && Second(Time(D1)) == Second(Time(D2))) {
		return false;
	}
	else {
		return true;
	}
}

boolean DLT(DATETIME D1, DATETIME D2) {
	if (Year(D1) < Year(D2)) {
		return true;
	}
	else if (Year(D1) == Year(D2)) {
		if (Month(D1) < Month(D2)) {
			return true;
		}
		else if (Month(D1) == Month(D2)) {
			if (Day(D1) < Day(D2)) {
				return true;
			}
			else if (Day(D1) == (Day(D2))) {
				if (TLT(Time(D1), Time(D2)) == true) {
					return true;
				}
			}
		}
	}
	return false;
}

boolean DGT(DATETIME D1, DATETIME D2) {
	if (Year(D1) < Year(D2)) {
		return false;
	}
	else if (Year(D1) == Year(D2)) {
		if (Month(D1) < Month(D2)) {
			return false;
		}
		else if (Month(D1) == Month(D2)) {
			if (Day(D1) < Day(D2)) {
				return false;
			}
			else if (Day(D1) == (Day(D2))) {
				if (TLT(Time(D1), Time(D2)) == true) {
					return false;
				}
			}
		}
	}
	return true;
}

DATETIME DATETIMENextNDetik(DATETIME D, int N) {
	Time(D) = NextNDetik(Time(D), N);
	if (TIMEToDetik(Time(D)) >= 86400) {
		printf("masuk\n");
		Day(D) += TIMEToDetik(Time(D)) / 86400;
		Time(D) = DetikToTIME(Second(Time(D))%86400);
		if (Day(D) > GetMaxDay(Month(D), Year(D))) {
			Day(D) -= GetMaxDay(Month(D), Year(D));
			Month(D)++;
		}
	}
	return D;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N) {
	Time(D) = PrevNDetik(Time(D), N);
	if (TIMEToDetik(Time(D)) < 0) {
		Day(D) += TIMEToDetik(Time(D)) / 86400;
		Time(D) = DetikToTIME(Second(Time(D))%86400);
		if (Day(D) <= 0) {
			Month(D)--;
			Day(D) += GetMaxDay(Month(D), Year(D));
		}
	}
	return D;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh) {
	long int tahun, bulan, hari, detik;
	tahun = Year(DAkh) - Year(DAw);
	bulan = Month(DAkh) - Month(DAw);
	hari = Day(DAkh) - Day(DAw);
	detik = Durasi(Time(DAw), Time(DAkh));
	return (tahun*3600*24*365 + bulan*3600*24*30 + hari*3600*24 + detik);
}
