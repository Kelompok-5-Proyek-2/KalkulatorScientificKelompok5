#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "daniar.h"
#include "jek.h"
#include "syaiful.h"
#include "adhiya.h"
#include "barry.h"

double perform_trig_operation(double sudut, char op[]) {
    if (strcmp(op, "sec(") == 0) {
		return 1.0 / cosinuss(sudut);
    } else if (strcmp(op, "csc(") == 0) {
		return 1.0 / sinuss(sudut);
    } else if (strcmp(op, "cot(") == 0) {
		return 1.0 / tangenn(sudut);
    } else if (strcmp(op, "sin(") == 0) {
    	return sinuss(sudut);
    } else if (strcmp(op, "cos(") == 0) {
        return cosinuss(sudut);
    } else if (strcmp(op, "tan(") == 0) {
        return tangenn(sudut);
    } else {
        return 0;
    }
}

void mainMenu(){
	    
    int opsi, subopsi;
    system("cls");
	printf("\tKalkulator Scientific Kelompok 5\n");
    printf("\n\t1. Scientific Calculator\n\t2. Dll");
    printf("\n\tMasukkan pilihan : ");
    scanf("%d", &opsi);
    switch(opsi){
    	case 1 :
    		CalArit();
    		mainMenu();
    		break;
    	case 2 :
    		system("cls");
    		printf("\t1. Statistika\n\t2. Konversi (suhu,massa,jarak)\n\tMasukkan Pilihan : ");
    		scanf("%d", &subopsi);
    		switch(subopsi){
    			case 1 :
    				input_Statistika();
    				break;
    			case 2:
    				konversi();
    				break;
			}
    		
    		
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
            return perkalian(bil1,bil2);
        case '/':
            return pembagian(bil1,bil2);
        case '+':
            return penjumlahan(bil1, bil2);
        case '-':
            return pengurangan(bil1, bil2);
        case 'V':
        	return sqroot(bil1, bil2);
        case '=':
        	return sama(bil1, bil2);
        case '>':
        	return lebih_besar(bil1,bil2);
        case '<':
        	return lebih_kecil(bil1,bil2);
        case '%':
        	return mod(bil1,bil2);
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
	        } else if (input[i] == '[') {
                i++;
                char number[100];
                int number_top = 0;
                while (input[i] != ']') {
                    number[number_top++] = input[i++];
                }
                number[number_top] = '\0';
                operand_stack[++operand_top] = atof(number);
                operand_stack[operand_top] = operand_stack[operand_top];
            } else if(input[i]=='|'){
            	i++;
            	char number[100];
                int number_top = 0;
                while (input[i] != '|') {
                    number[number_top++] = input[i++];
                }
                number[number_top] = '\0';
                operand_stack[++operand_top] = atof(number);
                operand_stack[operand_top] = nilai_mutlak(operand_stack[operand_top]);
			} else if (input[i] == 's' || input[i] == 'c' || input[i] == 't'){
            	char trigono[5];
            	int j=0;
            	char number[100];
            	int bil;
            	int number_top = 0;
            	while(input[i]!=')'){
            		if(isdigit(input[i]) || input[i] == '.'){
            			number[number_top++] = input[i++];
					}else {
				        // menyimpan operator trigonometri
				        trigono[j++] = input[i++];
				        trigono[4] = '\0';
				    }
				}
				operand_stack[++operand_top] = atof(number);
				bil = operand_stack[operand_top];
				operand_stack[operand_top]=perform_trig_operation(bil, trigono);
			} else if(input[i]=='!'){
				int j = i - 1;
				int k;
				char number[100];
				double bil;
				int result;
				int index = 0;
			    while (j >= 0 && isdigit(input[j])) {
			        j--;
			    }
			    for (k = j + 1; k < i; k++) {
			    	number[index] = input[k];
			        index++;
			    }
			    
			    operand_stack[++operand_top] = atof(number);
				bil = operand_stack[operand_top];
				result = faktorial(bil);
				operand_stack[--operand_top]=(double)result;
				
			} else if (input[i] == 'l'){
	        	char log[6];
	        	int j=0;
	        	char number[100];
	        	int number_top = 0;
	        	while(input[i]!=')'){
	        		if(isdigit(input[i]) || input[i] == '.'){
	        			number[number_top++] = input[i++];
					}else {
				        log[j++] = input[i++];
				        log[6] = '\0';
				    }
				}
				operand_stack[++operand_top] = atof(number);
				bil2 = operand_stack[operand_top--];
				bil1 = operand_stack[operand_top--];
				operand_stack[++operand_top]=logbase(bil2, bil1);
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
