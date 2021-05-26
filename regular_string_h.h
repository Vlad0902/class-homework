// Файл regular_string_h.h описує виконання завдання 12. Регулярні вирази
// тут передбачено виконання завданя за допомогою бібліотеки <string.h>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#define N 256

//Дана частина коду виконує завдання: даному текстовому файлі знайти всі гіперпосилання та вивести їх
//разом зі словом (слово відокремлюється пробілами та знаками
//пунктуації) що стоїть перед ним
//task1

//функція write_file_about_links записує результат роботи
// функції check_links_in_line, тобто всі поситання зстовам перед ним
//task1

void write_file_about_links(char* result, int count){
    FILE *f1;
    f1 = fopen("result_task1_string_h.txt", "a");
    if (f1 == NULL) {
        fprintf(stderr, "error read file %s", "result_1.txt");
    }
    fprintf(f1, "links ");
    fprintf(f1, "%d", count);
    fprintf(f1, " line:");
    fprintf(f1, "%s %s", result, "\n");
}

//головна програма яка забезпечує знаходження посилать та слів перед ними
//посилання вважається підрядок який починається "https://" за закінчується "/ "
//передбачено що слово може відділятися таким чином: " ", ".", ",", ";", ":", "!",
//"?", "(", ")", "[", "]", "{", "}", "*", "+", "&", '"'

void check_links_in_line(const char* s, int count){
    bool control = false;
    bool control_word = false;
    char link[N]="";
    char all_link[N]="";
    char word[N]="";
    char w[] = " word: " ;
    int len_word = 0;
    int len_link = 0;
    int len_all = 0;
    //цикл що проходить ввесь рядок
    for (int i = 0; i < N; ++i) {
        //знаходимо посилання у рядку
        if (s[i] == 'h' && s[i + 1] == 't' && s[i + 2] == 't' && s[i + 3] == 'p' && s[i + 4] == 's'
                && s[i + 5] == ':' && s[i + 6] == '/' && s[i + 7] == '/') {
            control = true;
            for (int j = i - 1; j >= 0; --j) {
                if (s[j] == ' ' || s[j] == '.' || s[j] == ',' || s[j] == ';' || s[j] == ':' || s[j] == '!' ||
                s[j] == '?' || s[j] == '(' || s[j] == ')' ||
                s[j] == '[' || s[j] == ']' || s[j] == '{' || s[j] == '}' || s[j] == '*' || s[j] == '+' ||
                s[j] == '&' || s[j] == '"') {
                    if ((word[0])) {
                        control_word = false;
                        break;
                    } else {
                        if (s[j - 1] != ' ' || s[j - 1] != '.' || s[j - 1] != ',' || s[j - 1] != ';' ||
                                s[j - 1] != ':' || s[j - 1] != '!' || s[j - 1] != '?' ||
                                s[j - 1] != '(' || s[j - 1] != ')' || s[j - 1] != '[' || s[j - 1] != ']' ||
                                s[j - 1] != '{' || s[j - 1] != '}' || s[j - 1] != '*' ||
                                s[j - 1] != '+' || s[j - 1] != '&' || s[j - 1] != '"') {
                            control_word = true;
                            continue;
                        } else { continue; }
                    }
                }
                //записуєм знайдене слово
                if (control_word) {
                    word[len_word] = s[j];
                    len_word ++;
                }
            }
        }
        //записуємо посилання
        if (control){
            link[len_link] = s[i];
            len_link ++;
        }
        //додаємо знайдене посилання з словом до рядка з всіма знайденими посиланнями
        if (control && s[i]=='/' && s[i+1]==' '){
            all_link[len_all++] = '\n';
            for (int j = 0; j < len_link; ++j) {
                all_link[len_all++] = link[j];
            }
            for (int j = 0; j < 7; ++j) {
                all_link[len_all++] = w[j];
            }
            for (int j = len_word-1; j >= 0 ; --j) {
                all_link[len_all++] = word[j];
            }
            strcpy(link, "");
            strcpy(word, "");
            len_word = 0;
            len_link = 0;
            control = false;
        }

    }
    //записуємо результат в файл
    write_file_about_links(all_link, count);
    strcpy(all_link, "");
}

// програма read_file_for_links передбачає читання файлу в якому требе знайти посилання

void read_file_for_links(const char *filename){
    char s[N];
    FILE *f2;
    f2 = fopen(filename, "r");
    if (f2 == NULL) {
        fprintf(stderr, "error read file %s", "result_1.txt");
    }

    int count = 0;
    while (!feof(f2)) {
        fgets(s, N, f2);
        count++;
        check_links_in_line(s, count);
    }
}

//Знайти в даному текстовому файлі всі дати в форматах __.__.__ та
//__/__/__ (в кінці можуть бути 2 або 4 цифри, а також ____(рік).__.__) та
//перевести їх всі до єдиного формату __(рік) назва місяцю __(число).
//передбачається що дати вводяться так: хх.хх.хххх(хх/хх/хххх) або хх.хх.хх(хх/хх/хх), наприклад 02.01.2021, 12.11.1985.

//task2

// програма check_date_in_line знаходить всі дати та замінює їх на потрібний формат
void check_date_in_line(const char* s, char* result ){
    char format[N] = "";
    char res[N] = "";
    int r = 0, f=0;
    char* month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                        "November", "December"};
    int mon[12] = {7, 8, 5, 5, 3, 4, 4, 6, 9, 7, 8, 8};
    //перевіряємо всі можливі варіанти дат хх.хх.хххх(хх/хх/хххх) або хх.хх.хх(хх/хх/хх)
    for (int i = 0; i < N; ++i) {
        char r1[1], r2[1], r3[1], r4[1], r5[1], r6[1], r7[1], r8[1], r9[1], r10[1];
        r1[0] = s[i], r2[0] = s[i+1], r3[0] = s[i+2], r4[0] = s[i+3], r5[0]=s[i+4];
        r6[0] = s[i+5], r7[0] = s[i+6], r8[0] = s[i+7], r9[0] = s[i+8], r10[0] = s[i+9];
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'||
                atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            char k[1];
            k[0] = r5[0];
            int m = atoi(r4)*10+atoi(k);
            //перетворюємо у порібний для нас формат
            format[f++] =  s[i+6]; format[f++] = s[i+7]; format[f++] = s[i+8] ; format[f++] = s[i+9];
            format[f++] = ' ' ;
            for (int j = 0; j < mon[m-1]; ++j) {
                format[f++] = month[m-1][j];
            }
            format[f++] = ' '; format[f++] = s[i]; format[f++] = s[i+1] ; format[f++] = ' ';
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 10;
            continue;
        }
        if(s[i]=='0'&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'||
           s[i]=='0'&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            char k[1];
            k[0] = r5[0];
            int m = atoi(r4)*10+atoi(k);
            printf("m=%c\n",k[0] );
            format[f++] =  s[i+6]; format[f++] = s[i+7]; format[f++] = s[i+8] ; format[f++] = s[i+9];
            format[f++] = ' ' ;
            for (int j = 0; j < mon[m-1]; ++j) {
                format[f++] = month[m-1][j];
            }
            format[f++] = ' '; format[f++] = s[i+1] ; format[f++] = ' ';
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 10;
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            char k[1];
            k[0] = r5[0];
            int m = atoi(r4)*10+atoi(k);
            format[f++] =  s[i+6]; format[f++] = s[i+7]; format[f++] = s[i+8] ; format[f++] = s[i+9];
            format[f++] = ' ' ;
            for (int j = 0; j < mon[m-1]; ++j) {
                format[f++] = month[m-1][j];
            }
            format[f++] = ' '; format[f++] = s[i]; format[f++] = s[i+1] ; format[f++] = ' ';
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 10;
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            char k[1];
            k[0] = r5[0];
            int m = atoi(r4)*10+atoi(k);
            format[f++] =  s[i+6]; format[f++] = s[i+7]; format[f++] = s[i+8] ; format[f++] = s[i+9];
            format[f++] = ' ' ;
            for (int j = 0; j < mon[m-1]; ++j) {
                format[f++] = month[m-1][j];
            }
            format[f++] = ' '; format[f++] = s[i+1] ; format[f++] = ' ';
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 10;
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            char k[1];
            k[0] = r5[0];
            int m = atoi(r4)*10+atoi(k);
            format[f++] =  s[i+6]; format[f++] = s[i+7];
            format[f++] = ' ' ;
            for (int j = 0; j < mon[m-1]; ++j) {
                format[f++] = month[m-1][j];
            }
            format[f++] = ' '; format[f++] = s[i]; format[f++] = s[i+1] ; format[f++] = ' ';
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 8;
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            char k[1];
            k[0] = r5[0];
            int m = atoi(r4)*10+atoi(k);
            format[f++] =  s[i+6]; format[f++] = s[i+7];
            format[f++] = ' ' ;
            for (int j = 0; j < mon[m-1]; ++j) {
                format[f++] = month[m-1][j];
            }
            format[f++] = ' '; format[f++] = s[i+1] ; format[f++] = ' ';
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 8;
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            char k[1];
            k[0] = r5[0];
            int m = atoi(r4)*10+atoi(k);
            format[f++] =  s[i+6]; format[f++] = s[i+7];
            format[f++] = ' ' ;
            for (int j = 0; j < mon[m-1]; ++j) {
                format[f++] = month[m-1][j];
            }
            format[f++] = ' '; format[f++] = s[i]; format[f++] = s[i+1] ; format[f++] = ' ';
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 8;
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            char k[1];
            k[0] = r5[0];
            int m = atoi(r4)*10+atoi(k);
            format[f++] =  s[i+6]; format[f++] = s[i+7];
            format[f++] = ' ' ;
            for (int j = 0; j < mon[m-1]; ++j) {
                format[f++] = month[m-1][j];
            }
            format[f++] = ' '; format[f++] = s[i+1] ; format[f++] = ' ';
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 8;
            continue;
        }
        //записуємо решту рядка що не є датою
        char t[1];
        res[r++] = s[i];
        }
    res[r++] = '\n';
    //записуємо змінений рядок
    for (int i = 0; i < N; ++i) {
        result[i]=res[i];
    }
    strcpy(res, "");
}

// програма read_file_date передбачає читання файлу в якому треба змінити дати на потрібний нам формат
void read_file_date(const char *filename){
    char s[N]="";
    char res[N]="";
    FILE *f2;
    f2 = fopen(filename, "r");
    if (f2 == NULL) {
    fprintf(stderr, "error read file %s", filename);
    }
    FILE *f1;
    f1 = fopen("copy_file.txt", "w");
    if (f1 == NULL) {
        fprintf(stderr, "error read file %s", "copy_file.txt");
    }
    while (!feof(f2)) {
        fgets(s, N, f2);
        check_date_in_line(s, res);
        fprintf(f1, "%s", res);
        strcpy(s, "");
        strcpy(res, "");
    }
    fclose(f1);
    fclose(f2);
    FILE *f3;
    f3 = fopen("copy_file.txt", "r");
    if (f1 == NULL) {
        fprintf(stderr, "error read file %s", "result_1.txt");
    }
    FILE *f4;
    f4 = fopen(filename, "w");
    if (f4 == NULL) {
        fprintf(stderr, "error read file %s", filename);
    }
    while (!feof(f3)) {
        fgets(s, N, f3);
        fprintf(f4, "%s", s);
    }
    fclose(f3);
    fclose(f4);
    remove("copy_file.txt");
}

//Знайти всі цілі та дійсні числа (в науковому та звичайному форматі з
//крапкою/комою) та привести їх до єдиного формату (дійсне число з
//фіксованою крапкою, точність 4 розряду) та оточити круглими дужками

//task3

// функція check_number_in_line знаходить всі числа в рядку і змінює їх за вимогою умови,
// але цифра має відділятися пробілом або згаком переходу на наступний рядок
void check_number_in_line(const char* s, char* result ){
    char  res[N] = "";
    FILE *f1;
    f1 = fopen("help_file.txt", "w");
    if (f1 == NULL) {
        fprintf(stderr, "error read file %s", "help_file.txt");
    }
    bool control_number = false;
    bool control_number_end = false;
    bool control_int = false;
    bool control_double = false;
    char num[N]="";
    int n = 0;
    //прохожу циклом весь рядок
    for (int i = 0; i < N; ++i) {
        char r[1];
        r[0] = s[i];
        //відслідковую початок кінець цифри
        if (atoi(r)){
            if (s[i+1]==' ' || s[i+1]=='\0' || s[i+1]=='\n'){
                control_number_end = true;
            }
        }
        if (atoi(r) || s[i]=='0'){
            control_number = true;
        }
        char r1[1];
        r1[0] = s[i+1];

        //записує знайдену цифру у рядкок, який потім конвертую у цифру
        if (control_number){
            num[n++] = s[i];
            if (atoi(r)){
                control_int = true;
            }
            if (s[i+1]=='.' || s[i+1]==','){
                num[n++] = '.';
                i++;
                control_int = false;
                control_double = true;
            }
        } else{
            fprintf(f1, "%c", s[i]);                //записує все що не є числом
        }

        if (control_number && control_number_end){
            if (control_double){
                //перевожу рядок у число
                double number = atof(num);
                //запиую число з відповідною точністю
                fprintf(f1, "(%0.4f)", number);
                control_number_end = false;
                control_number = false;
                control_int = false;
                control_double = false;
                strcpy(num, "");
                n=0;
            }
            if (control_int){
                int number = atoi(num);
                double n1 = number;
                fprintf(f1, "(%.4f)", n1);
                control_number_end = false;
                control_number = false;
                control_int = false;
                control_double = false;
                strcpy(num, "");
                n=0;
            }
        }
    }
    fclose(f1);
    FILE *f2;
    f2 = fopen("help_file.txt", "r");
    if (f1 == NULL) {
        fprintf(stderr, "error read file %s", "help_file.txt");
    }

    fgets(res, N, f2);
    //записуємо змінений рядок
    for (int i = 0; i < N; ++i) {
        result[i]=res[i];
    }
    fclose(f2);
    remove("help_file.txt");
    strcpy(res, "");
}

// функція read_file_number читає файл та перезаписує його у відповідності до змін що вимагаються в умові
void read_file_number(char *filename){
    char s[N]="";
    char res[N]="";
    FILE *f2;
    f2 = fopen(filename, "r");
    if (f2 == NULL) {
        fprintf(stderr, "error read file %s", filename);
    }
    FILE *f1;
    f1 = fopen("copy_file.txt", "w");
    if (f1 == NULL) {
        fprintf(stderr, "error read file %s", "copy_file.txt");
    }
    while (!feof(f2)) {
        fgets(s, N, f2);
        check_number_in_line(s, res);
        fprintf(f1, "%s", res);
        strcpy(s, "");
        strcpy(res, "");
    }
    fclose(f1);
    fclose(f2);
    FILE *f3;
    f3 = fopen("copy_file.txt", "r");
    if (f1 == NULL) {
        fprintf(stderr, "error read file %s", "result_1.txt");
    }
    FILE *f4;
    f4 = fopen(filename, "w");
    if (f4 == NULL) {
        fprintf(stderr, "error read file %s", filename);
    }
    while (!feof(f3)) {
        fgets(s, N, f3);
        fprintf(f4, "%s", s);
    }
    fclose(f3);
    fclose(f4);
    remove("copy_file.txt");
}

//Змінити всі дати та записи часу у файлі на поточні дату та час

//task4

// функція check_datetime_in_line знаходить всі дати та час у рядку та заміняє їх на поточну дату та час
void check_date_time_in_line(const char* s, char* result ){
    char format[N] = "";
    char res[N] = "";
    int r = 0, f=0;
    char* month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                       "November", "December"};
    int mon[12] = {7, 8, 5, 5, 3, 4, 4, 6, 9, 7, 8, 8};
    char buffer[80];
    char buf_time[80];
    time_t seconds = time(NULL);
    struct tm* timeinfo = localtime(&seconds);
    char data_now[] = "%d.%m.%Y ";
    char time_now[] = "%H:%M ";
    //отримує потчну дату та час
    strftime(buffer, 80, data_now, timeinfo);
    strftime(buf_time, 80, time_now, timeinfo);
    for (int i = 0; i < N; ++i) {
        char r1[1], r2[1], r3[1], r4[1], r5[1], r6[1], r7[1], r8[1], r9[1], r10[1];
        r1[0] = s[i], r2[0] = s[i+1], r3[0] = s[i+2], r4[0] = s[i+3], r5[0]=s[i+4];
        r6[0] = s[i+5], r7[0] = s[i+6], r8[0] = s[i+7], r9[0] = s[i+8], r10[0] = s[i+9];
        //відстужую у рядку весь час записаний у форматі хх:хх або х:хх наприклад 2:12, 15:44.
        if (atoi(r1)|| s[i]=='0'){
            if (atoi(r2) || s[i+1]=='0'){
                if (s[i+2]==':'){
                    if (atoi(r4)|| s[i+3]=='0'){
                        if (atoi(r5)|| s[i+4]=='0'){
                            for (int j = 0; j < 5; ++j) {
                                format[f++] = buf_time[j];
                            }
                            for (int j = 0; j < f; ++j) {
                                res[r++]=format[j];
                            }
                            strcpy(format, "");
                            f = 0;
                            i += 4;
                            continue;
                        }
                    }
                }
            }
        }
        if (atoi(r1) || s[i]=='0'){
            if (s[i+1]==':'){
                if (atoi(r3)|| s[i+2]=='0'){
                    if (atoi(r4)|| s[i+3]=='0'){
                        for (int j = 0; j < 5; ++j) {
                            format[f++] = buf_time[j];
                        }
                        for (int j = 0; j < f; ++j) {
                            res[r++]=format[j];
                        }
                        strcpy(format, "");
                        f = 0;
                        i += 3;
                        continue;
                    }
                }
            }
        }
        //відстежую всі дати
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            //зміню дату на поточну
            for (int j = 0; j < 11; ++j) {
                format[f++] = buffer[j];
            }
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 10;
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            for (int j = 0; j < 11; ++j) {
                format[f++] = buffer[j];
            }
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 10;
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            for (int j = 0; j < 11; ++j) {
                format[f++] = buffer[j];
            }
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 10;
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            for (int j = 0; j < 11; ++j) {
                format[f++] = buffer[j];
            }
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 10;
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            for (int j = 0; j < 11; ++j) {
                format[f++] = buffer[j];
            }
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 8;
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            for (int j = 0; j < 11; ++j) {
                format[f++] = buffer[j];
            }
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 8;
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            for (int j = 0; j < 11; ++j) {
                format[f++] = buffer[j];
            }
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 8;
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'||
           atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            for (int j = 0; j < 11; ++j) {
                format[f++] = buffer[j];
            }
            for (int j = 0; j < f; ++j) {
                res[r++]=format[j];
            }
            strcpy(format, "");
            f = 0;
            i += 8;
            continue;
        }
        //перезаписую решту рядка
        char t[1];
        res[r++] = s[i];
    }
    res[r++] = '\n';
    //записуємо змінений рядок
    for (int i = 0; i < N; ++i) {
        result[i]=res[i];
    }
    strcpy(res, "");
}

// функція read_file_data_time читає файл та перезаписує файл з датами та часом як вимагається в умові
void read_file_date_time(const char *filename){
    char s[N]="";
    char res[N]="";
    FILE *f2;
    f2 = fopen(filename, "r");
    if (f2 == NULL) {
        fprintf(stderr, "error read file %s", filename);
    }
    FILE *f1;
    f1 = fopen("copy_file.txt", "w");
    if (f1 == NULL) {
        fprintf(stderr, "error read file %s", "copy_file.txt");
    }
    while (!feof(f2)) {
        fgets(s, N, f2);
        check_date_time_in_line(s, res);
        fprintf(f1, "%s", res);
        strcpy(s, "");
        strcpy(res, "");
    }
    fclose(f1);
    fclose(f2);
    FILE *f3;
    f3 = fopen("copy_file.txt", "r");
    if (f1 == NULL) {
        fprintf(stderr, "error read file %s", "result_1.txt");
    }
    FILE *f4;
    f4 = fopen(filename, "w");
    if (f4 == NULL) {
        fprintf(stderr, "error read file %s", filename);
    }
    while (!feof(f3)) {
        fgets(s, N, f3);
        fprintf(f4, "%s", s);
    }
    fclose(f3);
    fclose(f4);
    remove("copy_file.txt");
}