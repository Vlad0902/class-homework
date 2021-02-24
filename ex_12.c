//Домашня робота №1

#include <stdio.h>
#include <math.h>

int main()
{
    int x_1, x_2, x_3, x_4, x_5;
    printf("x_1=");
    scanf("%d",&x_1);
    printf("x_2=");
    scanf("%d",&x_2);
    printf("x_3=");
    scanf("%d",&x_3);
    printf("x_4=");
    scanf("%d",&x_4);
    printf("x_5=");
    scanf("%d",&x_5);

    float f_1 = sqrt(x_1);
    float f_2 = sqrt(x_2);
    float f_3 = sqrt(x_3);
    float f_4 = sqrt(x_4);
    float f_5 = sqrt(x_5);

    printf( "x   | %d | %d | %d | %d | %d\n", x_1, x_2, x_3, x_4, x_5);
    printf("----+---+---+---+---+---\n");
    printf( "F(x)|%.2f|%.2f|%.2f|%.2f|%.2f", f_1, f_2, f_3, f_4, f_5);

    return 0;
}
