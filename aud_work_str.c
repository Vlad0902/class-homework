

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 255

int func1(char* str){
    char buf[N];
    int j=0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i]=='+' ){
            if (isdigit(str[i+1])){

            } else{ buf[j]=str[i];
                j++;}
        } else{
            buf[j]=str[i];
            j++;
        }
    }
    puts(buf);
}

int main(){
    char str[N];
    printf("Input string:");
    fgets(str, N, stdin);
    func1(str);
}