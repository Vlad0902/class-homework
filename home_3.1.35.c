//3.1.35b

#include <stdio.h>
#include <string.h>
#define N 255

int change_line(char* str){
    int k = strlen(str);
    if (k%4==0){

    } else{
        for (int i = k; i < k + k%4; ++i) {
            str[i-1]='0';
        }
        k = k + k%4;
    }
    int res=0, sum;
    int first, second, third, fourth;
    for (int i = 0; i < k; i=i+4) {
        first = str[i]+i;
        second = str[i+1]+i+1;
        third = str[i+2]+i+2;
        fourth = str[i+3]+i+3;
        sum = first+second+third+fourth;
        res ^= sum;
    }
    return res;
}

int main(){
    char str[N];
    printf("Input string:");
    fgets(str, N, stdin);
    puts(str);
    int res = change_line(str);
    printf("res=%d", res);
}
