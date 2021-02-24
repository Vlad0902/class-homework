//1.2.24a

#include <stdio.h>


int main(){
    int n;
    printf("n=");
    scanf("%d", &n);

    double y, z, max=0;
    for (int i=1; i<n+1; i++){
        printf("y%d=",i);
        scanf("%lf", &y);
        if (y <= 2){
            z = y;
        }
        else{z = 0.5;}
        if (z > max){
            max = z;
        }
    }
    printf("max=%lf", max);
}
