#ifndef syaiful_h
#include <math.h>

float Hitungpersen(float persen, float total){
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
	printf("Adalah : %0.lf Persen", hsl);  
}

#endif







