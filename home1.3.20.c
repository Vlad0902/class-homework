//1.3.20

#include <stdio.h>
#include <stdbool.h>

bool sys(int n){

    if(*(char *)&n == n) {
        return true;
    } else{return false;}
}

int main(){
    int n;
    printf("n=");
    scanf("%d", &n);
    if (sys(n)){
        printf("little endian");
    } else{printf("big");}
}