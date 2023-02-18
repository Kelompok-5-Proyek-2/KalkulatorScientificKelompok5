#ifndef syaiful_h
#include <math.h>
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

float Hitungdesimal(float pembilang, float penyebut){//mencari desimal
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
	printf("Hasil desimal :%.2f ",hdsml);
}

int boln(int angkaA, int angkaB, char op) {
    int hslbln = 0;
    switch (op) {
        case '>':
            if (angkaA > angkaB) {
                printf("%i > %i : benar\n", angkaA, angkaB);
                hslbln = 1;
            } else {
                printf(">  : salah\n");
            }
            break;
        case '=':
            if (angkaA == angkaB) {
                printf("%i = %i : benar\n", angkaA, angkaB);
                hslbln = 1;
            } else {
                printf("=  : salah\n");
            }
            break;
        default:
            printf("Operator tidak valid\n");
            break;
    }
    return hslbln;
}

void tampilbln() {
    int angkaA, angkaB, hslbln;
    char op;
    printf("\n\nMasukkan angka pertama: ");
    scanf("%i", &angkaA);
    printf("Masukkan angka kedua: ");
    scanf("%i", &angkaB);
    printf("Masukkan operator perbandingan(><=): ");
    scanf(" %c", &op);
    hslbln = boln(angkaA, angkaB, op);
//    printf("Hasil boolean: %i\n", hslbln);
}

#endif








