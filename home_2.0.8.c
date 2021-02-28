//2.0.8

#include <stdio.h>
#define N 20
int input(double mas[]){
    int i=0;
    while (i<20){
        printf("a[%d]=", i);
        scanf("%lf", &mas[i]);
        if (mas[i]==0){break;}
        i++;
    }
    return 0;
}

int main(){
    double mas[N];
    input(mas);
    int count;
    double dob=1, sum, gar;
    for (int i; i<20; i++){
        if (mas[i]==0){count=i;break;}
        dob *= mas[i];
        sum +=1.0/mas[i];
    }
    gar = count/sum;
    printf("dobutok=%lf\n", dob);
    printf("garmonichne=%lf\n", gar),
    printf("quantity=%d", count);

}