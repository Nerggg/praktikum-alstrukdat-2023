#include <stdio.h>

// membuat definisi array sendiri karena tidak dikatakan di soal untuk menggunakan ADT List Statik
int main() {
	int nRumah, nJalan, i, j, waktu = 0;

	scanf("%d", &nRumah);
	int rumah[nRumah];
	for (i = 0; i < nRumah; i++) {
		scanf("%d", &rumah[i]);
	}

	scanf("%d", &nJalan);
	int jalan[nJalan];
	for (i = 0; i < nJalan; i++) {
		scanf("%d", &jalan[i]);
	}

	int cek, last = -1;
	for (cek = 1; cek <= 3; cek++) {
		//printf("mulai pengecekan untuk sampah ke %d\n", cek);
		for (i = 0; i < nRumah; i++) {
			if(rumah[i] == cek) {
				last = i;
			}
		}

		if (last == -1) {
			//printf("sampah %d gaada\n", cek);
			cek++;
		}
		else {
			//printf("sampah paling belakang ada di %d\n", last);
			for (i = 0; i <= last; i++) {
				if (rumah[i] == cek) {
					//printf("sampah jumpa di %d\n", i);
					waktu++;
					//printf("waktu jadi %d\n", waktu);
				}
				if (i > 0) {
					waktu += 2 * jalan[i - 1];
					//printf("waktu jalan jadi %d\n", waktu);
				}
			}
		}

		last = -1;
	}
	printf("%d\n", waktu);
}
