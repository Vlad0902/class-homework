//1.3.27

#include <stdio.h>
#include <string.h>
#define N 255

int generate_str(char* str){
    char buf[N];
    int j=0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i]==str[i+1]){

        } else{
            buf[j] = str[i];
            j++;
        }

    }
    puts(buf);
}

int main(){
    char str[N];
    printf("Input string:");
    fgets(str, N, stdin);
    generate_str(str);
}