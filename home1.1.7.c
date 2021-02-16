//1.1.7б
//ax^4+bx^2+c=0
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>


bool isNearlyZero(double x){
    return (fabs(x)<2*DBL_EPSILON);
}


void printSquareEquation(double a, double b, double c){
    if(isNearlyZero(a)){
        if(isNearlyZero(b)){
            if(isNearlyZero(c)){ printf("Infinity of solutions\n"); }
            else{printf("No solutions\n");}
        }
        else{
            double t = -c/b;
            if(t<0){printf("No solutions\n");}
            else{
                double x1 = sqrt(t);
                double x2 = -sqrt(t);
                printf("x1=%lf, x2 =%lf\n",x1,x2);
            }
            //printf("x=%lf\n",x);
        }
    }
    else{
        double d = b*b - 4*a*c;
        if(isNearlyZero(d)){
            double t1 = -b/(2*a);
            if(t1<0){printf("No solutions\n");}
            else{
                double x_1 = sqrt(t1);
                double x_2 = -sqrt(t1);
                printf("x1=x3=%lf, x2=x4=%lf\n",x_1,x_2);
            }

        }
        else if(d>0){
            double t_1 = (-b - sqrt(d))/2/a;
            double t_2 = (-b + sqrt(d))/2/a;
            if(t_1<0){printf("No solutions\n");}
            else{
                double q_1 = sqrt(t_1);
                double q_2 = -sqrt(t_1);
                printf("x1=%lf, x2=%lf\n",q_1,q_2);
            }
            if(t_2<0){printf("No solutions\n");}
            else{
                double q_3 = sqrt(t_2);
                double q_4 = -sqrt(t_2);
                printf("x3=%lf, x4=%lf\n",q_3,q_4);
            }
        } else{
        printf("no real solutions\n");}
    }
}

int main() {
    double a, b, c;
    printf("a=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    printf("c=");
    scanf("%lf", &c);

    printSquareEquation(a, b, c);
}