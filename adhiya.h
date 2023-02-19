#ifndef Konversi_Suhu_H
#define Konversi_Suhu_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* KONVERSI SUHU */
//CELCIUS
float konversi_celciusfahrenheit (float celcius){
	float fahrenheit;
	fahrenheit = (celcius * 1.8) + 32;
	return fahrenheit;
}

float konversi_celciuskelvin (float celcius){
	float kelvin;
	kelvin = celcius * 273.15;
	return kelvin;
}

float konversi_celciusreamur (float celcius){
	float reamur;
	reamur = 0.8 * celcius;
	return reamur;
}

//KELVIN
float konversi_kelvincelcius (float kelvin){
	float celcius;
	celcius = kelvin - 273.15;
	return celcius;
}
float konversi_kelvinfahrenheit (float kelvin){
	float fahrenheit;
	fahrenheit = (kelvin * 1.8) - 459.67;
	return fahrenheit;
}

float konversi_kelvinreamur (float kelvin){
	float reamur;
	reamur = (kelvin - 273.15) * 0.8;
	return reamur;
}

//FAHRENHEIT
float konversi_fahrenheitcelcius (float fahrenheit){
	float celcius;
	celcius = (fahrenheit - 32) / 1.8;
	return celcius;
}

float konversi_fahrenheitkelvin (float fahrenheit){
	float kelvin;
	kelvin = (fahrenheit + 459.67) / 1.8;
	return kelvin;
}

float konversi_fahrenheitreamur (float fahrenheit){
	float reamur;
	reamur = (fahrenheit - 32) * 0.5556;
	return reamur;
}

//REAMUR
float konversi_reamurcelcius (float reamur){
	float celcius;
	celcius = 0.8 * reamur;
	return celcius;
}

float konversi_reamurkelvin (float reamur){
	float kelvin;
	kelvin = 0.8 * (reamur + 273.15);
	return kelvin;
}

float konversi_reamurfahrenheit (float reamur){
	float fahrenheit;
	fahrenheit = 2.25 * reamur + 32;
	return fahrenheit;
}

void input_suhu(){
	float celcius, kelvin, fahrenheit, reamur;
	int pilihan;
	system("cls");
	printf("\n\t1. Celcius\n\t2. Fahrenheit\n\t3. Kelvin\n\t4. Reamur\n");
	printf("\tMasukan satuan suhu awal : ");
	scanf("%d",&pilihan); 
	system("cls"); 
	if (pilihan==1){ //mengubah satuan awal celcius
		printf("Masukan suhu celcius :");
		scanf("%f", &celcius);
		fahrenheit = konversi_celciusfahrenheit(celcius);
		kelvin = konversi_celciuskelvin(celcius);
		reamur = konversi_celciusreamur(celcius);
		printf ("%.2f celcius = %.2f fahrenheit\n", celcius, fahrenheit);
		printf ("%.2f celcius = %.2f kelvin\n", celcius, kelvin);
		printf ("%.2f celcius = %.2f reamur\n", celcius, reamur);
	} else if (pilihan==2){ //mengubah satuan awal fahrenheit
		printf("Masukan suhu Fahrenheit :"); 
		scanf("%f", &fahrenheit);
		celcius = konversi_fahrenheitcelcius(fahrenheit);
		kelvin = konversi_fahrenheitkelvin(fahrenheit);
		reamur = konversi_fahrenheitreamur(fahrenheit);
		printf ("%.2f fahrenheit = %.2f celcius\n", fahrenheit, celcius);
		printf ("%.2f fahrenheit = %.2f kelvin\n", fahrenheit, kelvin);
		printf ("%.2f fahrenheit = %.2f reamur\n", fahrenheit, reamur);
	} else if (pilihan==3){ //mengubah satuan awal kelvin
		printf("Masukan suhu Kelvin :"); 
		scanf("%f", &kelvin);
		celcius = konversi_kelvincelcius(kelvin);
		fahrenheit = konversi_kelvinfahrenheit(kelvin);
		reamur = konversi_kelvinreamur(kelvin);
		printf ("%.2f kelvin = %.2f celcius\n", kelvin, celcius);
		printf ("%.2f kelvin = %.2f fahrenheit\n", kelvin, fahrenheit);
		printf ("%.2f kelvin = %.2f reamur\n", kelvin, reamur);	
	} else if (pilihan==4) { //mengubah satuan awal reamur
		printf("Masukan suhu reamur :"); 
		scanf("%f", &reamur);
		celcius = konversi_reamurcelcius(reamur);
		fahrenheit = konversi_reamurfahrenheit(reamur);
		kelvin = konversi_reamurkelvin(reamur);
		printf ("%.2f reamur = %.2f celcius\n", reamur, celcius);
		printf ("%.2f reamur = %.2f fahrenheit\n", reamur, fahrenheit);
		printf ("%.2f reamur = %.2f reamur\n", reamur, kelvin);	
	} else {
		printf("Angka yang anda masukan salah\n");
	}
	system("pause");
}


/* KONVERSI JARAK */

void input_jarak(){
	float km, hm, dam, m, dm, cm, mm, x;
	int pilihan;
	system("cls");
	printf("\n\t1. km\n\t2. hm\n\t3. dam\n\t4. m\n\t5. dm\n\t6. cm\n\t7. mm\n");
	printf("\tMasukan satuan jarak awal : ");
	scanf("%d",&pilihan); 
	system("cls"); 
	if (pilihan==1){ //mengubah satuan awal km
		printf("Masukan jarak dalam-km :");
		scanf("%f", &x);
		hm = x*10; dam = x*100; m = x*1000;	dm = x*10000; cm = x*100000; mm = x*1000000;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f km = %.2f hm, %.2f dam, %.2f m, %.2f dm, %.2f cm, %.2f mm\n", x, hm, dam, m, dm, cm, mm);
	} else if (pilihan==2){ //mengubah satuan awal hm
		printf("Masukan jarak dalam-hm :");
		scanf("%f", &x);
		km = x/10; dam = x*10; m = x*100; dm = x*1000; cm = x*10000; mm = x*100000;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f hm = %.2f km, %.2f dam, %.2f m, %.2f dm, %.2f cm, %.2f mm\n", x, km, dam, m, dm, cm, mm);
	} else if (pilihan==3){ //mengubah satuan awal dam
		printf("Masukan jarak dalam-dam :");
		scanf("%f", &x);
		km = x/100; hm = x/10; m = x*10; dm = x*100; cm = x*1000; mm = x*10000;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f dam = %.2f km, %.2f hm, %.2f m, %.2f dm, %.2f cm, %.2f mm\n", x, km, hm, m, dm, cm, mm);
	} else if (pilihan==4) { //mengubah satuan awal m
		printf("Masukan jarak dalam-m :");
		scanf("%f", &x);
		km = x/1000; hm = x/100; dam = x/10; dm = x*10; cm = x*100; mm = x*1000;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f m = %.2f km, %.2f hm, %.2f dam, %.2f dm, %.2f cm, %.2f mm\n", x, km, hm, dam, dm, cm, mm);
	} else if (pilihan==5) { //mengubah satuan awal dm
		printf("Masukan jarak dalam-dm :");
		scanf("%f", &x);
		km = x/10000; hm = x/1000; dam = x/100; m = x/10; cm = x*10; mm = x*100;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f dm = %.2f km, %.2f hm, %.2f dam, %.2f m, %.2f cm, %.2f mm\n", x, km, hm, dam, m, cm, mm);
	} else if (pilihan==6) { //mengubah satuan awal cm
		printf("Masukan jarak dalam-cm :");
		scanf("%f", &x);
		km = x/100000; hm = x/10000; dam = x/1000; m = x/100; dm = x/10; mm = x*10;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f cm = %.2f km, %.2f hm, %.2f dam, %.2f m, %.2f dm, %.2f mm\n", x, km, hm, dam, m, dm, mm);
	} else if (pilihan==7) { //mengubah satuan awal mm
		printf("Masukan jarak dalam-mm :");
		scanf("%f", &x);
		km = x/1000000; hm = x/100000; dam = x/10000; m = x/1000; dm = x/100; cm = x/10;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f mm = %.2f km, %.2f hm, %.2f dam, %.2f m, %.2f dm, %.2f cm\n", x, km, hm, dam, m, dm, cm);
	} else {
		printf("Angka yang anda masukan salah\n");
	}
	system("pause");
}

/* KONVERSI MASSA */

void input_massa(){
	float kg, hg, dag, g, dg, cg, mg, y;
	int pilihan;
	system("cls");
	printf("\n\t1. kg\n\t2. hg\n\t3. dag\n\t4. g\n\t5. dg\n\t6. cg\n\t7. mg\n");
	printf("\tMasukan satuan jarak awal : ");
	scanf("%d",&pilihan); 
	system("cls"); 
	if (pilihan==1){ //mengubah satuan awal kg
		printf("Masukan massa dalam-kg :");
		scanf("%f", &y);
		hg = y*10; dag = y*100; g = y*1000;	dg = y*10000; cg = y*100000; mg = y*1000000;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f kg = %.2f hg, %.2f dag, %.2f g, %.2f dg, %.2f cg, %.2f mg\n", y, hg, dag, g, dg, cg, mg);
	} else if (pilihan==2){ //mengubah satuan awal hg
		printf("Masukan massa dalam-hg :");
		scanf("%f", &y);
		kg = y/10; dag = y*10; g = y*100; dg = y*1000; cg = y*10000; mg = y*100000;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f hg = %.2f kg, %.2f dag, %.2f g, %.2f dg, %.2f cg, %.2f mg\n", y, kg, dag, g, dg, cg, mg);
	} else if (pilihan==3){ //mengubah satuan awal dag
		printf("Masukan massa dalam-dag :");
		scanf("%f", &y);
		kg = y/100; hg = y/10; g = y*10; dg = y*100; cg = y*1000; mg = y*10000;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f dag = %.2f kg, %.2f hg, %.2f g, %.2f dg, %.2f cg, %.2f mg\n", y, kg, hg, g, dg, cg, mg);
	} else if (pilihan==4) { //mengubah satuan awal g
		printf("Masukan massa dalam-g :");
		scanf("%f", &y);
		kg = y/1000; hg = y/100; dag = y/10; dg = y*10; cg = y*100; mg = y*1000;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f g = %.2f kg, %.2f hg, %.2f dag, %.2f dg, %.2f cg, %.2f mg\n", y, kg, hg, dag, dg, cg, mg);
	} else if (pilihan==5) { //mengubah satuan awal dg
		printf("Masukan massa dalam-dg :");
		scanf("%f", &g);
		kg = y/10000; hg = y/1000; dag = y/100; g = y/10; cg = y*10; mg = y*100;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f dg = %.2f kg, %.2f hg, %.2f dag, %.2f g, %.2f cg, %.2f mg\n", y, kg, hg, dag, g, cg, mg);
	} else if (pilihan==6) { //mengubah satuan awal cg
		printf("Masukan massa dalam-cg :");
		scanf("%f", &y);
		kg = y/100000; hg = y/10000; dag = y/1000; g = y/100; dg = y/10; mg = y*10;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f cg = %.2f kg, %.2f hg, %.2f dag, %.2f g, %.2f dg, %.2f mg\n", y, kg, hg, dag, g, dg, mg);
	} else if (pilihan==7) { //mengubah satuan awal mg
		printf("Masukan massa dalam-mg :");
		scanf("%f", &y);
		kg = y/1000000; hg = y/100000; dag = y/10000; g = y/1000; dg = y/100; cg = y/10;
		printf("\nHasil Konversi\n");
		printf("Jarak %.2f mg = %.2f kg, %.2f hg, %.2f dag, %.2f g, %.2f dg, %.2f cg\n", y, kg, hg, dag, g, dg, cg);
	} else {
		printf("Angka yang anda masukan salah\n");
	}
	system("pause");
}


void konversi(){
	
int pilih;
    system("cls");
    printf("\n\t1. Konversi Satuan Suhu\n\t2. Konversi Satuan Jarak\n\t3. Konversi Satuan Massa\n\t4. Menu utama");
    printf("\n\tMasukkan pilihan : ");
    scanf("%d", &pilih);
    switch(pilih){
    	case 1 :
    		system("cls");
    		input_suhu();
    		konversi();
    		break;
    	case 2 :
    		input_jarak();
    		konversi();
    		break;
    	case 3 :
    		input_massa();
    		konversi();
    		break;
    	case 4 :
    		mainMenu();
    		break;
		default :
    		exit(1);
	}
}
#endif
