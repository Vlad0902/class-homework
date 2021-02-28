//1.2.1.17ж

#include <stdio.h>
#include <math.h>

int main(){
    double x, eps;
    double a, y;

    do {
        printf("|x|<1, x=");
        scanf("%lf", &x);
    } while (fabs(x)< 0.00001);
    do {
        printf("eps>0, eps=");
        scanf("%lf", &eps);
    } while (eps < 0.00000001);

    a = 1.0;
    y = a;
    while (fabs(a)>eps){
        a *= -x;
        y += a;

    }
    printf("y=%lf", y);
}