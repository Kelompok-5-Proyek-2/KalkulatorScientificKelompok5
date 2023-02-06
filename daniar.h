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


void input_exponent(){
	double x,y;
	double z;
	printf("Masukkan angka : ");
	scanf("%lf", &x);
	printf("Masukkan angka : ");
	scanf("%lf", &y);
	z=exponent(x,y);
	printf("\nHasil : %.2lf\n", z);	
}

#endif
