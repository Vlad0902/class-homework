//1.2.4г
//Дано натуральне число n"\."  Написати програми обчислення значень виразів при заданому значенні x:

#include <stdio.h>
#include <math.h>

double func124(double x, int n){
    double y=1, power=1;
    for (int i=1; i<n+1; i++){
        power *=sinf(x);
        y += power;

    }
    return y;
}
int main(){
    double x, y;
    int n;
    printf("x=");
    scanf("%lf", &x);
    printf("n=");
    scanf("%d", &n);

    y = func124(x,n);
    printf("y=%lf", y);
}