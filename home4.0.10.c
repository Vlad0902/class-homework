//4.0.10

#include <stdio.h>
#define N 10


typedef struct{
    float population[N];
    float square[N];
    char city[N];
}City;

void calculate(City x){
    float pol[N];
    for (int i = 0; i < N; ++i) {
        pol[i] = x.population[i]/x.square[i];
    }
    float min=pol[0];
    int count=0;
    for (int i = 0; i < N; ++i) {
        if (pol[i]<min){
            min = pol[i];
            count = i;
        }
    }
    printf("The %c has a minimum population density\n", x.city[count]);
    printf("Population density: %lf million / thousand km^2", min);
}

int main(){
    City info={120, 56, 54, 98, 74, 23, 99, 45, 25, 61,
                     1204, 456, 845, 653, 456, 321, 987, 1523, 897, 651,
                     'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    calculate(info);

}