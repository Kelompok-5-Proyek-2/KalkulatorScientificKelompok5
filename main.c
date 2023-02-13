#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "daniar.h"
//#include "jek.h"
#include "syaiful.h"
#include "adhiya.h"
#include "barry.h"

double penjumlahan(double a, double b) {
    return a + b;
}

int main(int argc, char *argv[]) {
    char input[255];
    double result = 0;
    double result1 = 0;
    double bilangan;
    double bilangan2;
    int i = 0;
    int j = 0;
    scanf("%s", input);
    while (input[i]) {
        if (isdigit(input[i])==0) {
            result = penjumlahan(bilangan,bilangan2);
        }
        else {
            bilangan = atof(&input[i]);
            bilangan2 = atof(&input[i+2]);
        }
        i++;
    }
    printf("%lf\n", result);
    return 0;
}

