//4.0.10

#include <stdio.h>
#define N 10


typedef struct{
    float number[N];
}City;

typedef struct {
    char city[N];
}Name_City;

void calculate(City x, City y, Name_City z){
    float pol[N];
    for (int i = 0; i < N; ++i) {
        pol[i] = x.number[i]/y.number[i];
    }
    float min=pol[0];
    int count=0;
    for (int i = 0; i < N; ++i) {
        if (pol[i]<min){
            min = pol[i];
            count = i;
        }
    }
    printf("The %c has a minimum population density\n", z.city[count]);
    printf("Population density: %lf million / thousand km^2", min);
}

int main(){
    City population={120, 56, 54, 98, 74, 23, 99, 45, 25, 61};
    City square={1204, 456, 845, 653, 456, 321, 987, 1523, 897, 651};
    Name_City name={'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    calculate(population, square, name);

}