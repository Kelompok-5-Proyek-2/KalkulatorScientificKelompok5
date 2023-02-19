#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "daniar.h"
#include "jek.h"
#include "syaiful.h"
#include "adhiya.h"
#include "barry.h"


void mainMenu(){
	    
    int opsi;
    system("cls");
	printf("\tKalkulator Scientific Kelompok 5\n");
    printf("\n\t1. Operasi Aritmatika\n\t2. Statiska (Median, Modus, Mean)\n\t3. Konversi Satuan (Suhu, Jarak, Massa)");
    printf("\n\tMasukkan pilihan : ");
    scanf("%d", &opsi);
    switch(opsi){
    	case 1 :
    		CalArit();
    		mainMenu();
    		break;
    	case 2 :
    		input_Statistika();
    		mainMenu();
    		break;
    	case 3 :
    		konversi();
    		mainMenu();
    		break;
    	default :
    		exit(1);
	}
}

double operasi(double bil1, double bil2, char operator) {
    switch (operator) {
        case '^':
            return exponent(bil1, bil2);
        case '*':
            return bil1 * bil2;
        case '/':
            return Hitungdesimal(bil1, bil2);
        case '+':
            return penjumlahan(bil1, bil2);
        case '-':
            return bil1 - bil2;
        case 'V':
        	return sqroot(bil1, bil2);
        default:
            printf("Invalid operator: %c", operator);
            return 0;
    }
}

void CalArit(){
	for(;;){
    	char input[100];
		double bil2, bil1, operand_stack[100];
	    int operand_top = -1;
	    char operator_stack[100], operator;
	    int operator_top = -1;
	    int i;
    	system("cls");
    	printf("Input : ");
	    scanf("%s", input);
	    for (i = 0; input[i]; i++) {
	        if (isdigit(input[i])) {
	            char number[100];
	            int number_top = 0;
	            while (isdigit(input[i]) || input[i] == '.') {
	                number[number_top++] = input[i++];
	            }
	            number[number_top] = '\0';
	            operand_stack[++operand_top] = atof(number);
	            i--;
	        } else if (input[i] == '(') {
	            operator_stack[++operator_top] = input[i];
	        } else if (input[i] == ')') {
	            while (operator_stack[operator_top] != '(') {
	                bil2 = operand_stack[operand_top--];
	                bil1 = operand_stack[operand_top--];
	                operator = operator_stack[operator_top--];
	                operand_stack[++operand_top] = operasi(bil1, bil2, operator);
	            }
	            operator_top--;
	        } else {
	            while (operator_top >= 0 && prioritas(operator_stack[operator_top]) >= prioritas(input[i])) {
	                bil2 = operand_stack[operand_top--];
	                bil1 = operand_stack[operand_top--];
	                operator = operator_stack[operator_top--];
	                operand_stack[++operand_top] = operasi(bil1, bil2, operator);
	            }
	            operator_stack[++operator_top] = input[i];
			}
		}
		while (operator_top >= 0) {
		    bil2 = operand_stack[operand_top--];
		    bil1 = operand_stack[operand_top--];
		    operator = operator_stack[operator_top--];
		    operand_stack[++operand_top] = operasi(bil1, bil2, operator);
		}
		
		printf("Result: %g\n", operand_stack[0]);
		system("pause");
		
    	if(prioritas(operator_stack[operator_top])==-1){
    		break;
		}
	}
}

int main(){
	
    mainMenu();
    return 0;
}
