/*
 4) Ввести два дійсних числа записаних через пробіли в одному рядку та
обчислити значення їх середнього арифметичного та середньогогармонічного. Результат вивести в науковому та десятковому
представленні.
*/
#include <stdio.h>
int main(){
    double x, y;
    printf("x=");
    scanf("%lf",&x);
    printf("y=");
    scanf("%lf",&y);
    double z = (x + y)/2;
    double w= 2/((1/x)+(1/y));
    printf("%lf %le \n", z, z);
    printf("%lf %le  \n", w, w);
}