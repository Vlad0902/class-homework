//1.1.13


#include <stdio.h>

void printMaxRectangle(double x1_1, double y1_1, double x2_1, double y2_1, double x1_2, double y1_2, double x2_2, double y2_2){
    double mx1, my1, mx2, my2;
    if((x1_1>x2_1) ){printf("impossible situation");}
    else{
        if (y1_1>y2_1){printf("impossible situation");}
        else{
            if ((x1_2>x2_2) ){printf("impossible situation");}
            else{
                if (y1_2>y2_2){printf("impossible situation");}
                else{
                    if (x1_1<x1_2){mx1 = x1_1;}
                    else{mx1=x1_2;}
                    if (y1_1<y1_2){my1 = y1_1;}
                    else{my1=y1_2;}
                    if (x2_1>x2_2){mx2 = x2_1;}
                    else{mx2=x2_2;}
                    if (y2_1>y2_2){my2 = y2_1;}
                    else{my2=y2_2;}
                    printf("lower left:(%lf,%lf); upper right:(%lf,%lf)", mx1,my1,mx2,my2);
                }
            }
        }
    }
}

int main(){
    double x1_1, y1_1, x2_1, y2_1, x1_2, y1_2, x2_2, y2_2;
    printf("first rectangle:\n");
    printf("lower left\n");
    printf("x1_1=");
    scanf("%lf", &x1_1);
    printf("y1_1=");
    scanf("%lf", &y1_1);
    printf("upper right\n");
    printf("x2_1=");
    scanf("%lf", &x2_1);
    printf("y2_1=");
    scanf("%lf", &y2_1);
    printf("second rectangle:\n");
    printf("lower left\n");
    printf("x1_2=");
    scanf("%lf", &x1_2);
    printf("y1_2=");
    scanf("%lf", &y1_2);
    printf("upper right\n");
    printf("x2_2=");
    scanf("%lf", &x2_2);
    printf("y2_2=");
    scanf("%lf", &y2_2);
   printMaxRectangle(x1_1, y1_1, x2_1, y2_1, x1_2, y1_2, x2_2, y2_2);

}