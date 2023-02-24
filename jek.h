#ifndef jek_h
#include <math.h>
#include <complex.h>


double penjumlahan(double angkapertama, double angkakedua){
	return angkapertama + angkakedua;
}

double pengurangan(double angkapertama, double angkakedua){
	return angkapertama - angkakedua;
}

double pembagian(double angkapertama, double angkakedua){
	return angkapertama / angkakedua;
}

double perkalian(double angkapertama, double angkakedua){
	return angkapertama * angkakedua;
}

int mod(int a, int b) {
    int r = a / b;
    return r < 0 ? r + b : r;
}

#endif

