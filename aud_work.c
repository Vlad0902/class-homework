//2.1.1

#include <stdio.h>
#define N 3

void print(double mas[N][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%lf ", mas[i][j]);
        }
        printf("\n");
    }
}
void change(double mas[N][N], int I, int J, double A){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (i==I && j==J){
               mas[i][j]=A;
            }
        }
    }
}
int trans(double mas[N][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<i; j++){
            double tmp = mas[i][j];
            mas[i][j] = mas[j][i];
            mas[j][i] = tmp;
        }

    }
}
int main(){
    double mas[N][N]={
            {1.0,2,3},
            {4,5,6},
            {7,8,9}
    };
    int J=0, I=0;
    double A=0;
    printf("I=");
    scanf("%d", &I);
    printf("J=");
    scanf("%d", &J);
    printf("A=");
    scanf("%lf", &A);
    change(mas, I, J, A);
    print(mas);
    trans(mas);
    print(mas);
}