//1.2.10
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>


bool isNearlyZero(double x){
    return (fabs(x)<2*DBL_EPSILON);
}

int main(){
    double x, s;
    int i=0;
    while (i>=0){
        printf("a[%d]=",i);
        scanf("%lf", &x);
        s +=x;
        i++;
        if(isNearlyZero(x)){
            printf("%lf", s);
            break;
        }
    }
}