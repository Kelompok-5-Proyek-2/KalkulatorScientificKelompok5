#ifndef syaiful_h
#include <math.h>
#include <stdbool.h>
#define true 1
#define false 0

float Hitungpersen(float persen, float total){// mencari persentase
float hasil;
hasil = (persen/total)*100;

return hasil;
}

float Input_htgprsn(){
	float a,b;
	float hsl;
	printf("Berapa persen : ");
	scanf("%f", &a);
	printf("Dari jumlah total : ");
	scanf("%f", &b);
	hsl=Hitungpersen(a,b);
	printf("Adalah : %2.lf Persen\n\n", hsl); 

}

double Hitungdesimal(float pembilang, float penyebut){//mencari desimal
	double hsldsml;
	hsldsml=(double)pembilang/penyebut;
	
	return hsldsml;
}

float Input_desimal(){
	float a,b;
	float hdsml;
	printf("Masukkan pembilang : ");
	scanf("%f", &a);
	printf("Masukkan penyebut : ");
	scanf("%f", &b);
	hdsml=Hitungdesimal(a,b);
	printf("Hasil desimal :%.2f \n",hdsml);
}

bool lebih_besar(bil1,bil2){
	return bil1>bil2;
}

bool lebih_kecil(bil1,bil2){
	return bil1<bil2;
}

bool sama(bil1,bil2){
	return bil1==bil2;
}

void input(){
	int hasil;
	hasil=sama(4,4);
	printf("%d",hasil);
}

//void tampilbln() {
//    int angkaA, angkaB, hslbln;
//    char op;
//    printf("\n\nMasukkan angka pertama: ");
//    scanf("%i", &angkaA);
//    printf("Masukkan angka kedua: ");
//    scanf("%i", &angkaB);
//    printf("Masukkan operator perbandingan(><=): ");
//    scanf(" %c", &op);
//    hslbln = boln(angkaA, angkaB, op);
//    printf("Hasil boolean: %i\n", hslbln);
//}

#endif








