#include <stdio.h>
#include <math.h>

double task_03_1d(double x){
    double y = x*x*x*x*x+x*x*x+x;
    return y;
}

int main(){
    double x, y;
    scanf("%lf", &x);
    y = task_03_1d(x);
    printf("y=%lf", y);

}