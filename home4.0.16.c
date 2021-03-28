//4.0.3

#include <stdio.h>

typedef struct {
    char *name;
    int group;
    int mark_one;
    int mark_two;
    int mark_three;
}Student;

void input(Student * x){
    char buf[40];
    printf("Name:");
    scanf("%s", buf);
    x->name=buf;
    printf("Group:");
    scanf("%d", &x->group);
    printf("First mark:");
    scanf("%d", &x->mark_one);
    printf("Second mark:");
    scanf("%d", &x->mark_two);
    printf("Third mark:");
    scanf("%d", &x->mark_three);
}

int max_mark(int one, int two, int three){
    int mas[]={one, two, three};
    int max=mas[0];
    for (int i = 0; i < 3; ++i) {
        if (mas[i]>max){
            max=mas[i];
        }
    }
    return max;
}

void print_result(const Student st){
    //a);
    if (st.mark_one < 60 || st.mark_two < 60 || st.mark_three<60) {
        printf("%s has debt\n", st.name);
    }
    else {
        printf("%s has no debts\n", st.name);
    }
    //b);
    if (st.mark_one > 100 || st.mark_two > 100 || st.mark_three > 100) {
        printf("Error date\n");
    }
    else {
        printf("%s have max mark %d\n", st.name, max_mark(st.mark_one, st.mark_two, st.mark_three));
    }
}

int main(){
    int n;
    printf("Input n=");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        Student person;
        input(&person);
        print_result(person);
    }
}
