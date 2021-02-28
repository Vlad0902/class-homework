//2.0.9i

#include <stdio.h>
#include <stdbool.h>
#define N 5

bool check(int n){
    int res=0;
    while(n) {
        if (n & 1) {res++;};
        n >>= 1;
    }
    return res==5;
}
int input (int mas[], int size){
    for (int i=0; i<size; i++){
        printf("a[%d]=", i);
        scanf("%d", &mas[i]);
    }
    return 0;
}

int main(){

    int mas[N];
    input(mas, N);
    int count=0;
    for (int i=0; i<N; i++){
        if (check(mas[i])){count++;}
    }
    printf("quantity=%d", count);
}