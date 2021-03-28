//4.0.6б

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int hour;
    int minute;
    int second;
} Time;

int input(Time* x){
    scanf("%d", &x->hour);
    scanf("%d", &x->minute);
    scanf("%d", &x->second);

    return 0;
}

void output(const Time x){
    printf("\nTime: %d.%d.%d", x.hour, x.minute+1, x.second);
}

void incorrect(){
    printf("Incorrect input\nInput hour, minute, second:\n");
}

bool correct(const Time x){
    if (x.hour<0 || x.hour>=24){incorrect();return true;}
    if (x.minute<0 || x.minute>=60){incorrect();return true;}
    if (x.second<0 || x.second>=60){incorrect();return true;}
    return false;
}

int main(){
    Time x;
    printf("Input hour, minute, second:\n");
    do {
        input(&x);
    } while (correct(x));
    output(x);
}