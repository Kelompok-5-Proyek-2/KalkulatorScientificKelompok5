#ifndef Konversi_Suhu_H
#define Konversi_Suhu_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float konversi_suhufahrenheit (float celcius){
	float fahrenheit;
	fahrenheit = (celcius * 1.8) + 32;
	return fahrenheit;
}

float konversi_suhureamur (float celcius){
	float reamur;
	reamur = celcius * 4/5;
	return reamur;
}

/*Kelvin
float konversi_suhucelcius (float kelvin){
	float celcius;
	celcius = kelvin - 273.15;
	return celcius;
}

float konversi_suhufahrenheit (float kelvin){
	float fahrenheit;
	fahrenheit = 1.8 * (kelvin - 273.15) + 32;
	return fahrenheit;
}

float konversi_suhureamur (float kelvin){
	float reamur;
	reamur = kelvin - 273.15 * 0.8;
	return reamur;
}*/


void input_suhu(){
	float celcius, kelvin, fahrenheit, reamur;
	int pilihan;
	printf("Masukan suhu celsius: ");
	scanf("%f",&celcius);
	printf("\n");
	kelvin = konversi_suhukelvin(celcius);
	fahrenheit = konversi_suhufahrenheit(celcius);
	reamur = konversi_suhureamur(celcius);
	printf ("%.2f derajat celcius = %.2f derajat kelvin\n", celcius, kelvin);
	printf ("%.2f derajat celcius = %.2f derajat fahrenheit\n", celcius, fahrenheit);
	printf ("%.2f derajat celcius = %.2f derajat reamur", celcius, reamur);
}


/* KONVERSI JARAK */
float konversi_jarakkm (float x){
	float km;
	km = x/1000;
	return km;
}

float konversi_jarakhm (float x){
	float hm;
	hm=x/100;
	return hm;
}

float konversi_jarakdam (float x){
	float dam;
	dam=x/10;
	return dam;
}

float konversi_jarakm (float x){
	float m;
	m=x;
	return m;
}

float konversi_jarakdm (float x){
	float dm;
	dm=x*10;
	return dm;
}

float konversi_jarakcm (float x){
	float cm;
	cm=x*100;
	return cm;
}

float konversi_jarakmm (float x){
	float mm;
	mm=x*1000;
	return mm;
}

void input_jarak(){
	float km, hm, dam, m, dm, cm, mm, x, hasil;
	printf("Masukkan Jarak Yang Ditempuh dalam-meter:");
	scanf("%f", &x);
	printf("----------------------------------------------\n");
	
	km = konversi_jarakkm (x);
	hm = konversi_jarakhm (x);
	dam = konversi_jarakdam (x);
	m = konversi_jarakm (x);
	dm = konversi_jarakdm (x);	
	cm = konversi_jarakcm (x);
	mm = konversi_jarakmm (x);
	
	printf("\t Hasil Konversi\n");
	printf("Jarak %f m = %f km\n", x, km);
	printf("Jarak %f m = %f hm\n", x, hm);
	printf("Jarak %f m = %f dam\n", x, dam);
	printf("Jarak %f m = %f m\n", x, m);
	printf("Jarak %f m = %f dm\n", x, dm);
	printf("Jarak %f m = %f cm\n", x, cm);
	printf("Jarak %f m = %f mm\n", x, mm);
}

/* KONVERSI MASSA */
float konversi_massakg (float x){
	float kg;
	kg = x/1000;
	return kg;
}

float konversi_massahg (float x){
	float hg;
	hg=x/100;
	return hg;
}

float konversi_massadag (float x){
	float dag;
	dag=x/10;
	return dag;
}

float konversi_massag (float x){
	float g;
	g=x;
	return g;
}

float konversi_massadg (float x){
	float dg;
	dg=x*10;
	return dg;
}

float konversi_massacg (float x){
	float cg;
	cg=x*100;
	return cg;
}

float konversi_massamg (float x){
	float mg;
	mg=x*1000;
	return mg;
}

void input_massa(){
	float kg, hg, dag, g, dg, cg, mg, x, hasil;
	printf("Masukkan massa dalam-gram:");
	scanf("%f", &x);
	printf("----------------------------------------------\n");
	
	kg = konversi_massakg (x);
	hg = konversi_massahg (x);
	dag = konversi_massadag (x);
	g = konversi_massag (x);
	dg = konversi_massadg (x);	
	cg = konversi_massacg (x);
	mg = konversi_massamg (x);
	
	printf("\t Hasil Konversi\n");
	printf("Massa %f gram = %f kg\n", x, kg);
	printf("Massa %f gram = %f hg\n", x, hg);
	printf("Massa %f gram = %f dag\n", x, dag);
	printf("Massa %f gram = %f gram\n", x, g);
	printf("Massa %f gram = %f dg\n", x, dg);
	printf("Massa %f gram = %f cg\n", x, cg);
	printf("Jarak %f gram = %f mg\n", x, mg);
}


void menu(){
	int pilihan;
	printf(" 1. Konversi Suhu\n 2. Konversi Jarak\n 3. Konversi Massa\n");
	printf("Konversi yang dicari : ");
	scanf("%d", &pilihan);
	system ("cls");
	switch (pilihan){
		case 1 : {
			input_suhu();
			break;
		}
		system ("cls");
		case 2 : {
			input_jarak();
			break;
		}
		system ("cls");
		case 3 : {
			input_massa();
			break;
		}
	}
}
#endif
