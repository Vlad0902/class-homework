#include <stdio.h>
#include <math.h>

double dis(double x_0, double x_1, double y_0, double y_1){
    double d = sqrt(((x_1-x_0)*(x_1-x_0))+((y_1-y_0)*(y_1-y_0)));
    return d;
}

double s(double a, double b, double c){
    double p = (a+b+c)/2;
    double sq = sqrt(p*(p-a)*(p-b)*(p-c));
    return sq;
}

int main(){
    double x_0, y_0, x_1, y_1, x_2, y_2, a, b, c, s_1;
    printf("A(x,y)");
    scanf("%lf %lf", &x_0, &y_0);
    printf("B(x,y)");
    scanf("%lf %lf", &x_1, &y_1);
    printf("C(x,y)");
    scanf("%lf %lf", &x_2, &y_2);
    a = dis(x_0, y_0, x_1, y_1);
    b = dis(x_0, y_0, x_2, y_2);
    c = dis(x_1, y_1, x_2, y_2);
    s_1 = s(a, b, c);

    printf("square=%lf", s_1);

}