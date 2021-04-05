//3.3.8÷

#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3

void free_memory(double **arr){
    for (int i = 0; i < N; ++i) {
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

void output(double **arr, int m) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%lf ",  arr[i][j]);
        }
        printf("\n");
    }
}

int max_column(double **arr){
    double max_col=arr[0][0];
    int max_id = 0;
    for (int i = 0; i < M; ++i) {
        double sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += arr[j][i];
        }
        if (sum>max_col){
            max_col=sum;
            max_id=i;
        }
    }
    return max_id;
}

void create(double **arr, double **arr1){
    int id=max_column(arr);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i>id){
                arr1[j][i+1]=arr[j][i];
            } else{
                arr1[j][i]=arr[j][i];
            }
        }

    }
    printf("Input new column\n");
    for (int i = 0; i < N; ++i) {
        printf("mas[%d][%d]=", i, id+1);
        scanf("%lf", &arr1[i][id+1]);
    }

    free_memory(arr);
}

int main(){
    double **arr = (double **)malloc((N) * sizeof(double ));
    for (int i = 0; i < N; ++i) {
        arr[i] = (double *)calloc(M, sizeof(double ));
    }
    int m = M+1;
    double **arr1 = (double **)malloc((N) * sizeof(double ));
    for (int i = 0; i < N; ++i) {
        arr1[i] = (double *)calloc(m, sizeof(double ));
    }
    input(arr);
    output(arr, M);
    create(arr, arr1);
    output(arr1, M+1);
    free_memory(arr1);
}