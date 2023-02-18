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
    printf("\n\t1. Operasi Aritmatika\n\t2. Statiska (Median, Modus, Mean)\n\t3. Konversi Satuan Suhu\n\t4. Konversi Satuan Jarak");
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
    		input_suhu();
    		mainMenu();
    		break;
    	case 4 :
    		input_jarak();
    		mainMenu();
    		break;
    	default :
    		exit(1);
	}
}

double operasi(double num1, double num2, char operator) {
    switch (operator) {
        case '^':
            return exponent(num1, num2);
        case '*':
            return num1 * num2;
        case '/':
            return Hitungdesimal(num1, num2);
        case '+':
            return penjumlahan(num1, num2);
        case '-':
            return num1 - num2;
        case 'V':
        	return sqroot(num1, num2);
        default:
            printf("Invalid operator: %c", operator);
            return 0;
    }
}

void CalArit(){
	for(;;){
    	char expression[100];
		double num2, num1;
	    double stack_num[100];
	    int stack_num_top = -1;
	    char stack_op[100], operator;
	    int stack_op_top = -1;
	    int i;
    	system("cls");
    	printf("Enter expression: ");
	    scanf("%s", expression);
	    for (i = 0; expression[i]; i++) {
	        if (isdigit(expression[i])) {
	            char number[100];
	            int number_top = 0;
	            while (isdigit(expression[i]) || expression[i] == '.') {
	                number[number_top++] = expression[i++];
	            }
	            number[number_top] = '\0';
	            stack_num[++stack_num_top] = atof(number);
	            i--;
	        } else if (expression[i] == '(') {
	            stack_op[++stack_op_top] = expression[i];
	        } else if (expression[i] == ')') {
	            while (stack_op[stack_op_top] != '(') {
	                num2 = stack_num[stack_num_top--];
	                num1 = stack_num[stack_num_top--];
	                operator = stack_op[stack_op_top--];
	                stack_num[++stack_num_top] = operasi(num1, num2, operator);
	            }
	            stack_op_top--;
	        } else {
	            while (stack_op_top >= 0 && prioritas(stack_op[stack_op_top]) >= prioritas(expression[i])) {
	                num2 = stack_num[stack_num_top--];
	                num1 = stack_num[stack_num_top--];
	                operator = stack_op[stack_op_top--];
	                stack_num[++stack_num_top] = operasi(num1, num2, operator);
	            }
	            stack_op[++stack_op_top] = expression[i];
			}
		}
		while (stack_op_top >= 0) {
		    num2 = stack_num[stack_num_top--];
		    num1 = stack_num[stack_num_top--];
		    operator = stack_op[stack_op_top--];
		    stack_num[++stack_num_top] = operasi(num1, num2, operator);
		}
		
		printf("Result: %g\n", stack_num[0]);
		system("pause");
		
    	if(stack_num[0]==0){
    		break;
		}
	}
}

int main(int argc, char *argv[]) {
	
    mainMenu();
    return 0;
	
}

