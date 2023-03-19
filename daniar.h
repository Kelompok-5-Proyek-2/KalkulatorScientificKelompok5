#ifndef daniar_h
#include <math.h>

void CalArit();
void mainMenu();

int prioritas(char operator) {
    
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^' || operator =='V')
        return 3;
    else if (operator == '(' || operator == ')')
        return 0; 
    else if (operator =='=' || operator=='>' || operator =='<')
    	return 0;
    else
        return -1;
        exit(1);
    
}

void input_exponent(){
	double x=0;
	double z;
	printf("Masukkan angka : ");
	scanf("%lf", &x);
	z=sin(x);
	printf("\nHasil : %lf\n", z);	
}

#endif
