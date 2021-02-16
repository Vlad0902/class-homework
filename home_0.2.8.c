//Домашня робота №2

#include <stdio.h>
#include <math.h>

int main()
{
    int x_0=2, x_1, y_0=3, y_1;
    printf("a) koordunata x, y:");
    scanf("%d %d", &x_1, &y_1);
    double d = sqrt(((x_1-x_0)*(x_1-x_0))+((y_1-y_0)*(y_1-y_0)));  // відстань між двома точками
    printf("vidstan = %lf\n", d);

    int  A, B, C;
    printf("b) A, B, C:");
    scanf("%d %d %d", &A, &B, &C);
    double dis = abs(A*x_0+B*y_0+C)/sqrt(A*A + B*B); //використовуємо формулу для пошку відстані від точки до прямої для якої A, B, C вводимо самостійно
    printf("vidstan_1 = %lf\n", dis);

    int  A1, B1, C1, A2, B2, C2;
    printf("c) A1, B1, C1, A2, B2, C2:");
    scanf("%d %d %d %d %d %d", &A1, &B1, &C1, &A2, &B2, &C2);
    double q = B1*A2 - A1*B2;              // знаходимо току перетину двох прямих,
    double x_3 = (B1*(-C2)-B2*(-C1))/q;    // для яких A1, B1, C1, A2, B2, C2 вводимо
    double y_3 = (A2*(-C1)-A1*(-C2))/q;    // самостійно в консолі

    double dis_1 = sqrt(((x_3-x_0)*(x_3-x_0))+((y_3-y_0)*(y_3-y_0))); // відстань між двома точками
    printf("vidstan_2 = %lf", dis_1);
}