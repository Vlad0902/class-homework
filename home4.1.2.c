//4.1.2д

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int create_F_File(const char* fname, int *mas, int n){
    FILE * fp;
    fp = fopen(fname, "wb");
    if (fp == NULL) {
        fprintf(stderr, "error read file %s", fname);
        return -1;
    }
    int res = fwrite(mas, n, sizeof(int), fp);
    fclose(fp);
    return res;
}

int read_File(const char* fname){
    FILE * fp;
    fp = fopen(fname, "rb");
    if (fp == NULL) {
        fprintf(stderr, "error read file %s", fname);
        return -1;
    }
    int x=0;
    int k = 0;
    while (!feof(fp)) {
        int r = fread(&x, sizeof(int), 1, fp);
        if (r == 0)
            break;
        printf("x[%d]=%d\n", k++, x);
    }
    fclose(fp);
}

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    int div = 1;
    while (x / div >= 10) {
        div *= 10;
    }
    while (x != 0) {
        int l = x / div;
        int r = x % 10;
        if (l != r)
            return false;
        x = (x % div) / 10;
        div /= 100;
    }
    return true;
}

int create_G_File(const char* fname, const char* gname, int n){
    FILE * fp;
    fp = fopen(fname, "rb");
    if (fp == NULL) {
        fprintf(stderr, "error read file %s", fname);
        return -1;
    }
    int x=0;
    int i = 0;
    int palindrome[n];
    while (!feof(fp)) {
        int r = fread(&x, sizeof(int), 1, fp);
        if (r == 0)
            break;
        if (isPalindrome(x)){
            palindrome[i]=x;
            i++;
        }
    }
    fclose(fp);
    FILE * gp;
    gp = fopen(gname, "wb");
    if (gp == NULL) {
        fprintf(stderr, "error read file %s", fname);
        return -1;
    }
    fwrite(palindrome, i, sizeof(int), fp);
    fclose(gp);

}

int main(){
    int n;
    printf("Input n:");
    scanf("%d", &n);

    int mas[n];
    for (int i = 0; i < n; ++i) {
        printf("element %d=", i);
        scanf("%d", &mas[i]);
    }
    create_F_File("input.txt", mas, n);
    create_G_File("input.txt", "output.txt", n);
    printf("Result in G file:\n");
    read_File("output.txt");
}