
#include <stdio.h>
#include <math.h>

double arctg(double x){
    double f = atan(x);
    return f;
}

double arctg_derevative(double x){
    double g = 1/(1+x*x);
    return g;
}

int main(){
    double x, at, at_der;
    scanf("%lf", &x);
    at = arctg(x);
    at_der = arctg_derevative(x);
    printf("f(x)=%lf\n", at);
    printf("g(x)=%lf", at_der);
}