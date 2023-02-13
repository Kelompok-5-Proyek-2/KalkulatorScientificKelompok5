#ifndef jek_h
#include <math.h>


int penjumlahan(int angkapertama, int angkakedua){
	int jumlah;
	jumlah = angkapertama + angkakedua;
	return jumlah;
}

void inputData(){
	int angkapertama;
	int angkakedua;
	int jumlah;
	printf("Masukkan angka pertama: ");
	scanf("%d", &angkapertama);
	printf("Masukkan angka kedua: ");
	scanf("%d", &angkakedua);
	jumlah = penjumlahan(angkapertama, angkakedua);
	printf("Jumlah: %d", jumlah);
}

#endif

