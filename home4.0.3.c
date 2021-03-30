//4.0.3

#include <stdio.h>

typedef struct {
    int numerator;
    unsigned int denominator;
}Rational;

int input(Rational* x){
    scanf("%d", &x->numerator);
    scanf("%u", &x->denominator);
    return 0;
}

void output(const Rational x){
    printf("Rational=%d / %u\n", x.numerator, x.denominator);
}

Rational add(const Rational x, const Rational y){
    Rational res_add;
    if (x.denominator==y.denominator){
        res_add.numerator = (int)(x.numerator) + (int)(y.numerator);
        res_add.denominator = x.denominator;
    }
    else{
        res_add.numerator = (int)(x.numerator*y.denominator) + (int)(y.numerator*x.denominator);
        res_add.denominator = x.denominator*y.denominator;}

    return res_add;
}

Rational mul(const Rational x, const Rational y){
    Rational res_mul;
    res_mul.numerator = x.numerator*y.numerator;
    res_mul.denominator = x.denominator*y.denominator;
    return res_mul;
}

void check(const Rational x, const Rational y){
    unsigned first = x.numerator*y.denominator;
    unsigned second = y.numerator*x.denominator;
    if (first>second){
        printf("first fraction > second fraction\n");
    }
    if (second>first){
        printf("second fraction > first fraction\n");
    }
    if (first==second){
        printf("first fraction = second fraction\n");
    }
}

Rational red(const Rational x){
    Rational z;
    int i=1;
    while (i>0){
        if (x.numerator%i==0 || x.denominator%i==0){
            z.numerator = x.numerator/i;
            z.denominator = x.denominator/i;
            i++;
        } else{break;}
    }
    return z;
}

int main(){
    Rational x, y, a, m, r;
    input(&x);
    input(&y);
    printf("First:");
    output(x);
    printf("Second:");
    output(y);
    check(x, y);
    a = add(x, y);
    output(a);
    m = mul(x, y);
    output(m);
    r = red(x);
    output(r);

}
