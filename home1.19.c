//1.19г)
// x_k=((-1)^k x^k)/k! "\ "(k≥0);
#include <stdio.h>


int main(){
    double x, y=1;
    int n;
    printf("x=");
    scanf("%lf", &x);
    printf("n=");
    scanf("%d", &n);
    if(x==0){
        y = 0;
    } else{
        for (int i=1; i<n+1;i++){
            y *= (-1)*x/i;
        }
    }


    printf("y=%lf", y);
}
