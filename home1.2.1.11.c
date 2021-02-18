//1.2.1.11д

#include <stdio.h>

double calculate(int n){
    double a0=1, ak, b=1;
    double suma=0;
    for (int i=1; i<n+1; i++){
        ak = i*a0+1.0/i;
        b *= 2.0/i;
        a0 = ak;
        suma += a0*b;
    }
    return suma;

}

int main(){
    int n;
    double y;
    printf("n=");
    scanf("%d", &n);
    y = calculate(n);
    printf("Summa= %lf", y);

}