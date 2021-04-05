//2.1.30

#include <stdio.h>

#define M 4
#define K 5

void print(int mas[M][K]){
    for (int i=0; i<M; i++){
        for (int j=0; j<K; j++){
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
}

void input(int mas[M][K]){
    for (int i=0; i<M; i++){
        for (int j=0; j<K; j++){
            printf("mas[%d][%d]=", i, j);
            scanf("%d", &mas[i][j]);
        }
    }
}

void transposition(int mas[M][K], int n){

    for (int k = 0; k < n; ++k) {
        for (int i = M-2; i>=0; i--){
            for (int j=0; j<K; j++){
                int l=mas[i+1][j];
                mas[i+1][j]=mas[i][j];
                mas[i][j]=l;

            }
        }
    }
}

int main(){
    int n;
    printf("Input n:");
    scanf("%d", &n);
    int mas[M][K];
    input(mas);
    print(mas);
    transposition(mas, n);
    printf("result after the shift:\n");
    print(mas);

}