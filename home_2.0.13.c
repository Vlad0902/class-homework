//2.0.13a

#include <stdio.h>
#include <math.h>

int fact(int n){
    int f=1;
    for (int i=2; i<=n; i++){
        f *=i;
    }
    return f;
}
double coefficient(int n, int k){
    if (n==0 || n==1){return 1;}
    else{
        int st = n-2*k-1;
        double f1=fact(n-k);
        double a=powf(-1, k)*n/(n-k)*f1/fact(k)/fact(n-2*k)*powf(2, st);
        return a;
    }

}

int main(){
    unsigned n;
    printf("n=");
    scanf("%u", &n);

    double mas[n+1];
    for (int i = 0; i <n/2+1 ; i++) {
        int k = 2*i;
        mas[k] = coefficient(n, i);
        mas[k+1] = 0;
    }
    for (int i=0; i<=n; i++){
        int k = n-i;
        printf("x^%d: %lf\n", k, mas[i]);
    }
}