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
	printf("Pembilang : ");
	scanf("%f", &a);
	printf("Penyebut : ");
	scanf("%f", &b);
	hdsml=Hitungdesimal(a,b);
	printf("Hasil desimal :%.2f ",hdsml);
}

int boln(int angkaA,int angkaB){// mencari boolean
	char hslbln;
	if (angkaA>angkaB){
		printf("%i > %i : benar\n",&angkaA, &angkaB);
	}else{
		printf(">  : salah\n");
	}
	if (angkaA==angkaB){
		printf(">= : benar\n");
	}else{
		printf(">= : salah\n");
	}
	if (angkaA<angkaB){
		printf("<  : benar\n");
	}else{
		printf("<  : salah\n");
	}if (angkaA==angkaB){
		printf("<= : benar\n");
	}else{
		printf("<= : salah\n");
	}if (angkaA==angkaB){
		printf("=  : benar\n");
	}else{
		printf("=  : salah\n");
	}
}

void tampilbln(){
	int a,b;
	int hasilbln;
	printf("\n\nangka pertama :");
	scanf("%d", &a);
	printf("angka kedua :");
	scanf("%d", &b);
	hasilbln=boln(a,b);
}
 
#endif








