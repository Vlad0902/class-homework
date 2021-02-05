
#include <stdio.h>

int main(){
    double x=9, y=45, z=6, s, a;
    int count=0, count_1=0, count_2=0, count_3=0 ;
    printf("x=%lf y=%lf z=%lf\n", x, y, z);
    printf("a)\n");
    if (x!=y){
        count++;
    }
    if (x!=z) {
        count++;
    }
    if (y!=z){
        count++;
    }
    printf("number of different: %d\n", count);

    printf("b)\n");

    if (x==y){
        count_1++;

    }
    if (x==z){
        count_1++;
    }
    if (y==z){
        count_1++;
    }
    printf("number of identical: %d\n", count_1);

    printf("c)\n");
    s = (x+y+z)/3;
    if (x>s){
        count_2++;
    }
    if (y>s){
        count_2++;
    }
    if (z>s){
        count_2++;
    }
    printf("number more than average: %d\n", count_2);

    printf("d)\n");
    printf("a=");
    scanf("%lf", &a);
    if (x>a){
        count_3++;
    }
    if (y>a){
        count_3++;
    }
    if (z>a){
        count_3++;
    }
    printf("number more than a: %d\n", count_3);
}