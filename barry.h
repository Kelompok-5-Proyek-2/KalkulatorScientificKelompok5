#ifndef barry_h
#define barry_h
#include <math.h>
#include <stdio.h>

float HitungMean(int BanyakData, float mean[])
{
	int x;
	float sum = 0.0;
	
	for (x = 0; x < BanyakData; ++x)
	{
		sum += mean[x];
	}
	return sum / BanyakData;
}

void input_Statistika_Mean()
{
	int BanyakData, x;
  	float mean[25];
  	printf("Jumlah data yang akan dimasukkan :  ");
  	scanf("%d", &BanyakData);

  	for (x = 0; x < BanyakData; ++x)
	{
    	printf("Masukkan angka : ");
    	scanf("%f", &mean[x]);
	}

  	printf("Nilai Mean = %.2f", HitungMean(BanyakData, mean));
}

#endif
