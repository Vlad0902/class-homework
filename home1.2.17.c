//1.2.17
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>


bool isNearlyZero(double x){
    return (fabs(x)<2*DBL_EPSILON);
}

int main(){
    double value=99999999999;
    double x, max=-value, min=value;
    int i=0;
    printf("input number %lf<a<%lf\n", -value, value);
    while (i>=0){
        printf("a%d=",i);
        scanf("%lf", &x);
        if (x<0){
            if (x>=max){
                max=x;
            }
        }
        else{
            if (x>0){
                if (x<min){
                    min = x;
                }
            }
        }
        i++;
        if(isNearlyZero(x)){
            if (max==-value){
                printf("%lf", min);
                break;
            } else{
                printf("%lf", max);
                break;
            }
        }
    }
}