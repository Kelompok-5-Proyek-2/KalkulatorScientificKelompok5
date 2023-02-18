#ifndef daniar_h
#include <math.h>

void CalArit();
void mainMenu();

int prioritas(char operator) {
    switch (operator) {
        case '^':
        case 'V':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            printf("Invalid operator: %c", operator);
            exit(1);
    }
}


double exponent(double konst, double var){
	double result =1;
	int i;
	for (i=0;i<var;i++){
		result=result*konst;
	}
	return result;	
}

double sqroot(double konst, double var){
	
	return pow(var, 1.0/konst);
}

int logaritma(int konst){
	return log10(konst);
}

double sinus(double konst){
	return sin(konst);
}

double cosinus(double konst){
	return cos(konst);
}

double tangen(double konst){
	return tan(konst);
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
