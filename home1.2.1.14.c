//1.2.1.14

#include <stdio.h>
#include <stdbool.h>

bool check(int a, int n){
    int num1, num2, d=10;
    int i=1;
    bool ch= false;
    while (i>0){
        num1 = n%d;
        if(num1==a){ch=true;}
        num2 = (n-num1)/d;
        n = num2;
        if (n==0){break;}
    }
    if (ch){return 1>0;}
    else{return 1<0;}
}

int main(){
    int a, n;
    printf("a with {1,2,3,4,5,6,7,8,9,0}\na=");
    scanf("%d", &a);
    printf("n is a natural number\nn=");
    scanf("%d",&n);
    if (check(a, n)){
        printf("YES, %d belongs to the number %d", a, n);
    }
    else{
        printf("NO, %d does not belongs to the number %d", a, n);
    }
}