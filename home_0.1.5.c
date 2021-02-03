/*
  5) Три дійсні числа вводяться як рядок вигляду
А=ххх.ххх, B=xxExxx C=xxx.xxxx (тут “A=”,”B=”, “C=” символи, що
повинні бути присутніми та ігноруються при введенні)
Обчисліть їх середнє арифметичне та середнє гармонічне та виведіть у
науковому та звичайному форматі.

 */

#include <stdio.h>

int main(){
    double a, b, c;

    printf("A=");
    scanf("%lf",&a);
    printf("B=");
    scanf("%le",&b);
    printf("C=");
    scanf("%lf",&c);
    double z = (a + b + c)/3;
    double w= 3/((1/a)+(1/b)+(1/c));
    printf("arithmetic %lf %le \n", z, z);
    printf("harmonious %lf %le  \n", w, w);

}