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
		return 1.0 / cosinus(sudut);
    } else if (strcmp(op, "csc(") == 0) {
		return 1.0 / sinus(sudut);
    } else if (strcmp(op, "cot(") == 0) {
		return 1.0 / tangen(sudut);
    } else if (strcmp(op, "sin(") == 0) {
    	return sinus(sudut);
    } else if (strcmp(op, "cos(") == 0) {
        return cosinus(sudut);
    } else if (strcmp(op, "tan(") == 0) {
        return tangen(sudut);
    } else {
    	printf("invalid operator trigonometri, example 'sin(), cos(), tan(), sec(), cot(), csc()'\n");
    	system("pause");
        return 0;
    }
}


double operasi(double bil1, double bil2, char operator) {
	if(isOperator(operator)){
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
        default:
            return lebih_kecil(bil1,bil2);
    	}
	}else{
		printf("Invalid Operator %c\n", operator);
		return 0;
	}
    
}

bool isOperator(char op){
	if(op=='+' || op=='-' || op=='*' || op =='/' || op =='V' || op == '>' || op =='<' || op=='=' || op =='^' || op=='(' || op ==')'){
		return true;
	}else{
		return false;
	}
}

void CalArit(){
	char input[100];
    bool cekNegative;
	double bil2, bil1, operand_stack[100];
	char operator_stack[100], operator;

	for(;;){
	    int operand_top = -1;
	    int operator_top = -1;
	    int i;
	    int p=0;
    	system("cls");
    	printf("\tKalkulator Scientific Kelompok 5\n\n");
    	printf("Input : ");
	    scanf("%s", &input);
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
	            
	        }
			else if (input[i]=='(' && isNegative(&input[i+1], i)){
	        	char number[100];
	        	int k;
	        	k = i+2;
	            int number_top = 0;
	            while (isdigit(input[k]) || input[k] == '.') {
					number[number_top++] = input[k++];	
	            }
	            number[number_top] = '\0';
	            operand_stack[++operand_top] = -atof(number);
	            i = k--;
			}
			 else if (input[i] == '(') {
	            operator_stack[++operator_top] = input[i];
	        } else if (input[i] == ')') {
	            while (operator_stack[operator_top] != '(') {
	                bil2 = operand_stack[operand_top--];
	                bil1 = operand_stack[operand_top--];
	                operator = operator_stack[operator_top--];
	                operand_stack[++operand_top] = operasi(bil1, bil2, operator);
	                if(operand_top == -1){
	                	break;
					}
	            }
	            operator_top--;
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
            	char nomor[100], cek;
            	int bil, negative;
            	int nomor_top = 0;
            	negative = 0;
			    cek = input[i+4]; // Skip "sin(" or "cos(" or "tan("
				
				//Handle angka sebelum sin
				if(isdigit(input[i-1])){
					printf("invalid expression for trigonometri, example 'sin(90) or sec(90) etc'\n");
				}		
			    // Handle negative number
			    if (cek == '-') {
			    	negative = 1;
			    }
            	while(input[i] != ')' && (input[i] != '+' || input[i] != '*' || input[i] != '/') && input[i] != ' '){
            		if(isdigit(input[i]) || input[i] == '.'){
            			nomor[nomor_top++] = input[i++];
            			
					}else {
				        // menyimpan operator trigonometri
				        trigono[j++] = input[i++];
				        trigono[4] = '\0';
				    }
				}
				nomor[nomor_top] = '\0';
				if(negative){
					j--;
				}
				if(j!=4){
					printf("invalid expression for trigonometri, example 'sin(90) or sec(90) etc'\n");
				}else{
					if (negative) { // jika bilangan negatif, konversi ke nilai negatif saat disimpan di stack
			            operand_stack[++operand_top] = -1 * atof(nomor);
			        } else {
			            operand_stack[++operand_top] = atof(nomor);
			        }
					bil = operand_stack[operand_top];
					operand_stack[operand_top]=perform_trig_operation(bil, trigono);
				}
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
	        	char log[4];
	        	int j=0;
	        	char temp[1], temp2[1];
	        	char number[100];
	        	int number_top = 0;
	        	temp[0] = input[i-1];
	        	while(input[i] != ')' && (input[i] != '+' || input[i] != '-' || input[i] != '*' || input[i] != '/') && input[i] != ' '){
	        		if(isdigit(input[i]) || input[i] == '.'){
	        			number[number_top++] = input[i++];
					}else {
				        log[j++] = input[i++];
				        log[4] = '\0';
				    }
				}
				number[number_top] = '\0';
				if(strcmp(log, "log(")){
					printf("invalid expression, maybe input = 'log()'?\n");
				}else{
					if(j!=4){
					printf("Invalid expression for logaritma, example 'log(10) or 2log(4) and input number should be greater than 0'\n");
					}else{
						operand_stack[++operand_top] = atof(number);
						bil2 = operand_stack[operand_top--];
						if(bil2 <= 0) {
				            printf("Invalid expression for logaritma, the input number should be greater than 0\n");
				        }
						else if(!isdigit(temp[0])){
							operand_stack[++operand_top]=logbase(bil2, 10);
						}else{
							bil1 = operand_stack[operand_top--];
							operand_stack[++operand_top]=logbase(bil2, bil1);
						}
					
					}	
				}
			} else {
				if(!isdigit(input[i]) && !isdigit(input[i+1]) && input[i+1] !='(' && input[i+1]!='[' && input[i+1]!='|' && input[i+1]!= 'l' && input[i+1]!='s' && input[i+1]!='c' && input[i+1]!='t'){
					printf("The operator is incorrect, the '%c' and '%c' operators should not be adjacent to each other\n", input[i], input[i+1]);
				}else{
					while (operator_top >= 0 && prioritas(operator_stack[operator_top]) >= prioritas(input[i])) {
	                bil2 = operand_stack[operand_top--];
	                bil1 = operand_stack[operand_top--];
	                operator = operator_stack[operator_top--];
	                operand_stack[++operand_top] = operasi(bil1, bil2, operator);
	            	}
	            	operator_stack[++operator_top] = input[i];
				}
	            
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
	}
}

int main(){

    CalArit();
    return 0;
}
