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
    else
        return -1;
        exit(1);
    
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
