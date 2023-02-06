#include <stdio.h>
#include <stdlib.h>
#include "daniar.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int opsi;
	printf("1. Eksponen\n2. Konversi Suhu\n3. Aritmatika\n");
	printf("Masukkan Pilihan : ");
	scanf("%d",&opsi);
	
	switch(opsi){
		case 1: input_exponent(); break;
		default : break;	
	} 
	return 0;
}
