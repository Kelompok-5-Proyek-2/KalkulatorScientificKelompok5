#ifndef daniar_h
#include <math.h>

double exponent(double konst, double var){
	double result =1;
	int i;
	for (i=0;i<var;i++){
		result=result*konst;
	}
	return result;	
}

int sqroot(int konst){
	
	return sqrt(konst);
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
