//3.3.8д

#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3


void free_memory(double **arr, int  n){
    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
}

void input(double **arr){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("mas[%d][%d]=", i, j);
            scanf("%lf", &arr[i][j]);
        }
    }
}

void output(double **arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%lf ",  arr[i][j]);
        }
        printf("\n");
    }
}

int create(double **arr, double **arr1){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            arr1[i+1][j]=arr[i][j];
        }

    }
    printf("Input new line\n");
    for (int i = 0; i < M; ++i) {
        printf("mas[0][%d]=", i);
        scanf("%lf", &arr1[0][i]);
    }
    free_memory(arr, N);

}

int main(){
    double **arr = (double **)malloc((N) * sizeof(double ));
    for (int i = 0; i < N; ++i) {
        arr[i] = (double *)calloc(M, sizeof(double ));
    }
    double **arr1 = (double **)malloc((N+1) * sizeof(double ));
    for (int i = 0; i < N+1; ++i) {
        arr1[i] = (double *)calloc(M, sizeof(double ));
    }
    input(arr);
    output(arr, N);
    create(arr, arr1);
    output(arr1, N+1);
    free_memory(arr1, N+1);
}