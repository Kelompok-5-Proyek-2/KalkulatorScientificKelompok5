#include <stdio.h>
#include <stdlib.h>
#include "daniar.h"
#include "jek.h"
#include "syaiful.h"
#include "adhiya.h"
#include "barry.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int opsi;
	printf("1. Eksponen\n2. Konversi Suhu\n3. Aritmatika\n4. Penjumlahan\n5. Statistika");
	printf("\nMasukkan Pilihan : ");
	scanf("%d",&opsi);
	
	switch(opsi){
		case 1: input_exponent(); break;
		case 2: input_kelvin();break;
		case 3: Input_htgprsn();break;
		case 4: inputData();break;
		case 5: input_Statistika_Mean();break;
		default : break;	
	} 
	return 0;
}
