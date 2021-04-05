

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void input(double* a, int n){
    for (int i = 0; i < n; ++i) {
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
    }
}

void print(double* a, int n){
    for (int i = 0; i < n; ++i) {
        printf("a[%d]=%lf", i, a[i]);
    }
}

double * vect(int n){
    return (double *)malloc(n*sizeof(double ));
}
void del(double* v ){
    free(v);
}

double* dif(double* v1,int n, double* v2){
    double* div = vect(n);
    for (int i = 0; i < n; ++i) {
        div[i] = v1[i] - v2[i];
    }
    print(div, n);
    del(div);

}

int main(){
    int n;
    printf("n=");
    scanf("%d", &n);
    double* a1 = vect(n);
    double* a2 = vect(n);
    input(a1, n);
    input(a2, n);
    dif(a1, n, a2);
    del(a1);
    del(a2);
}
