

#include <stdio.h>

int main(){
    char a[5]={1, 2, 8, 9, 7};
    double n;
    printf("n=");
    scanf("%lf", &n);
    int k=0;
    for (int i=0; i<5; i++){
        if(a[i]<n){k++;}
    }
    printf("k=%d", k);
}