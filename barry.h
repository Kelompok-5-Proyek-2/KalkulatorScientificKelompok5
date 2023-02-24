#ifndef barry_h
#define barry_h
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Statistika, mencari nilai modus, median dan mean

int compare_ints(const void *a, const void *b) {
  int *x = (int *) a;
  int *y = (int *) b;
  return *x - *y;
}

float HitungMean(int BanyakData, float inputData[])
{
	int x;
	float sum = 0.0;
	for (x = 0; x < BanyakData; ++x)
	{
		sum += inputData[x];
	}
	return sum / BanyakData;
}

double HitungMedian(int BanyakData, float inputData[]) {
	qsort(inputData, BanyakData, sizeof(float), compare_ints);
	if (BanyakData % 2 == 0) {
    	return (inputData[BanyakData / 2 - 1] + inputData[BanyakData / 2]) / 2.0;
  	} else {
    	return inputData[BanyakData / 2];
  	}
}

void HitungModus(int BanyakData, float inputData[], float *modus, int *frekuensi) {
  int i, j, hitung;
  
  *frekuensi = 0;
  for (i = 0; i < BanyakData; ++i) {
    hitung = 0;
    for (j = 0; j < BanyakData; ++j) {
      if (inputData[j] == inputData[i]) {
        ++hitung;
      }
    }
    if (hitung > *frekuensi) {
      *frekuensi = hitung;
      *modus = inputData[i];
    }
  }
}

void input_Statistika() {
	int BanyakData, x, frekuensi;
	float modus;
  	float inputData[25];
  	system("cls");
  	printf("Jumlah data yang akan dimasukkan :  ");
  	scanf("%d", &BanyakData);
  	for (x = 0; x < BanyakData; ++x)
	{
    	printf("Masukkan angka : ");
    	scanf("%f", &inputData[x]);
	}
	HitungModus(BanyakData, inputData, &modus, &frekuensi);
	if (frekuensi > 1) {
		printf("Nilai Modus data tersebut = %.2f", modus);
		printf("\nSebanyak %d nilai", frekuensi);	
	} else {
		printf("\nTidak ada Nilai Modus");
	}
  	printf("\nNilai Mean data tersebut = %.2f", HitungMean(BanyakData, inputData));
  	printf("\nNilai Median data tersebut = %.2f\n", HitungMedian(BanyakData, inputData));
  	system("pause");
}

// Mencari nilai cotangen, cosecan dan secan

double perform_trig_operation(double sudut, char op[]) {
    if (strcmp(op, "sec(") == 0) {
    	sudut = sudut * M_PI/180;
		float nilai_cos = cos(sudut);
		return 1.0 / nilai_cos;
    } else if (strcmp(op, "csc(") == 0) {
       	sudut = sudut * M_PI/180;
		float nilai_sin = sin(sudut);
		return 1.0 / nilai_sin;
    } else if (strcmp(op, "cot(") == 0) {
        sudut = sudut * M_PI/180;
		float nilai_tan = tan(sudut);
		return 1.0 / nilai_tan;
    } else if (strcmp(op, "sin(") == 0) {
    	sudut = sudut * M_PI/180;
    	return sin(sudut);
    } else if (strcmp(op, "cos(") == 0) {
    	sudut = sudut * M_PI/180;
        return cos(sudut);
    } else if (strcmp(op, "tan(") == 0) {
    	sudut = sudut * M_PI/180;
        return tan(sudut);
    } else {
        return 0;
    }
}

float calculate_cot(float sudut) {
	float nilai_tan = tan(sudut);
	return 1.0 / nilai_tan;
}

float calculate_csc(float sudut) {
	float nilai_sin = sin(sudut);
	return 1.0 / nilai_sin;
}

float calculate_sec(float sudut) {
	float nilai_cos = cos(sudut);
	return 1.0 / nilai_cos;
}

void inputSudut() {
  	float sudut, result;
  	int i;
	printf("Masukkan nilai : ");
  	scanf("%g", &sudut);
  	printf("Pilih mau apa yang dikerjain\n1.Ngitung Cot\n2.Ngitung Csc\n3.Ngitung Sec\n");
  	scanf("%d", &i);
	if (i == 1){
		result = calculate_cot(sudut);
	} else if (i == 2){
		result = calculate_csc(sudut);
	} else {
		result = calculate_sec(sudut);
	}
	printf("Hasilnya adalah : %.2f", result);
}

#endif
