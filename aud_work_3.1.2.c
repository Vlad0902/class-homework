//3.1.2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 255

int first_comma(char* str){
    int  i=0, position=0;
    while (str[i]!='\0'){
        if (str[i]==','){position=i+1;break;}
        i++;
    }
    if (i==strlen(str)){
        position=-1;
    }
    return position;
}
int last_comma(char* str){
    int i = strlen(str), lpos=0;
    while (i>=0){
        if (str[i]==','){lpos=i+1;break;}
        i--;
    }
    if (i==-1){
        lpos = -1;
    }
    return lpos;
}

int count_comma(char* str ){
    int count=0, i=0;
    while (str[i]!='\0'){
        if (str[i]==','){count++;}
        i++;
    }
    return count;
}

int main(){
    char str[N];
    printf("Input string:");
    fgets(str, N, stdin);
    printf("a)\n");
    int position = first_comma(str);
    if (position>=0){
        printf("First comma on the %d position\n", position);
    } else{printf("No comma\n");}
    printf("b)\n");
    int last = last_comma(str);
    if (last>=0){
        printf("Last comma on the %d position\n", last);
    } else{printf("No comma\n");}
    printf("c)\n");
    int count = count_comma(str);
    if (count>0){
        printf("We have %d commas\n", count);
    } else{printf("No comma\n");}

}
