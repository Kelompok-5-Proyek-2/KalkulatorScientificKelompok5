#ifndef Konversi_Suhu_H
#define Konversi_Suhu_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float konversi_suhukelvin (float celcius){
	float kelvin;
	kelvin = celcius + 273.15;
	return kelvin;
}

void input_kelvin(){
	float celcius, kelvin, hasil;
	printf("Masukan suhu celsius: ");
	scanf("%f",&celcius);
	printf("\n");
	hasil = konversi_suhukelvin(celcius);
	printf ("%.2f derajat celcius = %.2f derajat kelvin", celcius, hasil);
}


	
#endif
