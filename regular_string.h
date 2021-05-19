// Файл regular_string.h описує виконання завдання 12. Регулярні вирази
// тут передбачено виконання завданя за допомогою бібліотеки <string>


#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;


//Дана частина коду виконує завдання: даному текстовому файлі знайти всі гіперпосилання та вивести їх
//разом зі словом (слово відокремлюється пробілами та знаками
//пунктуації) що стоїть перед ним
//task1

//функція write_file_about_links записує результат роботи
// функції check_links_in_line, тобто всі поситання зстовам перед ним
void write_file_about_links(string &result, int count){
    std::ofstream f1;
    f1.open("result_task1_string.txt", std::ios::app);
    if (f1.bad()){
        std::cout<<"Input file can't be read";
    }
    f1<<"links "<<count<<" line:"<<result<<endl;
}

//головна програма яка забезпечує знаходження посилать та слів перед ними
//посилання вважається підрядок який починається "https://" за закінчується "/ "
//передбачено що слово може відділятися таким чином: " ", ".", ",", ";", ":", "!",
//"?", "(", ")", "[", "]", "{", "}", "*", "+", "&", '"'
void check_links_in_line(string &s, int count){
    bool control = false;
    bool control_word = false;
    string link;
    string all_link;
    string word;
    //цикл що проходить ввесь рядок
    for (int i = 0; i < s.size(); ++i) {
        //знаходимо посилання у рядку
        if (s[i] == 'h' && s[i + 1] == 't' && s[i + 2] == 't' && s[i + 3] == 'p' && s[i + 4] == 's'
            && s[i + 5] == ':' && s[i + 6] == '/' && s[i + 7] == '/') {
            control = true;
            for (int j = i - 1; j >= 0; --j) {
                if (s[j] == ' ' || s[j] == '.' || s[j] == ',' || s[j] == ';' || s[j] == ':' || s[j] == '!' ||
                    s[j] == '?' || s[j] == '(' || s[j] == ')' ||
                    s[j] == '[' || s[j] == ']' || s[j] == '{' || s[j] == '}' || s[j] == '*' || s[j] == '+' ||
                    s[j] == '&' || s[j] == '"') {
                    if (word.length() >= 1) {
                        control_word = false;
                        break;
                    } else {
                        //відокремлюємо слова
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
                    word += s[j];
                }
            }
        }
        //записуємо посилання
        if (control){
            link +=s[i];
        }
        //додаємо знайдене посилання з словом до рядка з всіма знайденими посиланнями
        if (control && s[i]=='/' && s[i+1]==' '){
            all_link += link;
            all_link += " word: ";
            reverse(word.begin(), word.end());
            all_link += word;
            all_link += '\n';
            link = "";
            word = "";
            control = false;
        }

    }
    //записуємо результат в файл
    write_file_about_links(all_link, count);
}

// програма read_file_for_links передбачає читання файлу в якому требе знайти посилання
void read_file_for_links(string &filename){
    string s;

    std::ifstream f2;
    f2.open(filename, std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    int count = 0;
    while (!f2.eof()) {
        getline(f2, s);
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
string check_date_in_line(string &s){
    string format="";
    string res = "";
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                        "November", "December"};
    //цикл що проходить весь рядок
    for (int i = 0; i < s.length(); ++i) {
        char r1[1], r2[1], r3[1], r4[1], r5[1], r6[1], r7[1], r8[1], r9[1], r10[1];
        r1[0] = s[i], r2[0] = s[i+1], r3[0] = s[i+2], r4[0] = s[i+3], r5[0]=s[i+4];
        r6[0] = s[i+5], r7[0] = s[i+6], r8[0] = s[i+7], r9[0] = s[i+8], r10[0] = s[i+9];
        //перевіряємо всі можливі варіанти дат хх.хх.хххх(хх/хх/хххх) або хх.хх.хх(хх/хх/хх)
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'){

            int m = stoi(&s[i+3]);
            //перетворюємо у порібний для нас формат
            format = format + s[i+6] + s[i+7] + s[i+8] + s[i+9]+ " " + month[m-1] + " " + s[i]+ s[i+1] + " ";
            res = res + format;
            format="";
            i += 10;
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + s[i+8] + s[i+9]+ " " + month[m-1] + " " + s[i]+ s[i+1] + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + s[i+8] + s[i+9]+ " " + month[m-1] + " " + s[i+1] + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + s[i+8] + s[i+9]+ " " + month[m-1] + " " + s[i]+ s[i+1] + " ";
            res = res + format;
            format="";
            i += 10;
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + s[i+8] + s[i+9]+ " " + month[m-1] + " " + s[i+1] + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + " " + month[m-1] + " " + s[i]+ s[i+1] + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + " " + month[m-1] + " " + s[i+1] + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + " " + month[m-1] + " " + s[i]+ s[i+1] + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] +  " " + month[m-1] + " " +  s[i+1] + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + s[i+8] + s[i+9]+ " " + month[m-1] + " " + s[i+1] + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + s[i+8] + s[i+9]+ " " + month[m-1] + " " + s[i]+ s[i+1] + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + s[i+8] + s[i+9]+ " " + month[m-1] + " " + s[i+1] + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + " " + month[m-1] + " " + s[i]+ s[i+1] + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + " " + month[m-1] + " " + s[i+1] + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + " " + month[m-1] + " " + s[i]+ s[i+1] + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            int m = stoi(&s[i+3]);
            format = format + s[i+6] + s[i+7] + " " + month[m-1] + " " + s[i+1] + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        //записуємо решту рядка що не є датою
        char t[1];
        t[0] = s[i];
        if (not atoi(t) || t[0]!='.' || t[0]!='/'){
            res = res + s[i];
        }
    }
    //повертамо змінений рядок
    return res;
}

// програма read_file_date передбачає читання файлу в якому треба змінити дати на потрібний нам формат
void read_file_date(string &filename){
    string s;

    std::ofstream f1;
    f1.open("copy_file.txt", std::ios::out);
    if (f1.bad()){
        std::cout<<"Input file can't be read";
    }
    std::ifstream f2;
    f2.open(filename, std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    while (!f2.eof()) {
        getline(f2, s);
        string res = check_date_in_line(s);
        f1<<res<<endl;
    }
    f1.close();
    f2.close();

    std::ifstream f3;
    f3.open("copy_file.txt", std::ios::in);
    if (f3.bad()){
        std::cout<<"Input file can't be read";
    }
    std::ofstream f4;
    f4.open(filename, std::ios::out);
    if (f4.bad()){
        std::cout<<"Input file can't be read";
    }
    while (!f3.eof()) {
        getline(f3, s);
        f4<<s<<endl;
    }
    f3.close();
    f4.close();
    remove("copy_file.txt");

}

//Знайти всі цілі та дійсні числа (в науковому та звичайному форматі з
//крапкою/комою) та привести їх до єдиного формату (дійсне число з
//фіксованою крапкою, точність 4 розряду) та оточити круглими дужками

//task3

// функція check_number_in_line знаходить всі числа в рядку і змінює їх за вимогою умови
string check_number_in_line(string &s){
    string  res = "";
    std::ofstream f1;
    f1.open("help_file.txt", std::ios::out);
    if (f1.bad()){
        std::cout<<"Input file can't be read";
    }
    bool control_number = false;
    bool control_number_end = false;
    bool control_int = false;
    bool control_double = false;
    string num;
    //прохожу циклом весь рядок
    for (int i = 0; i < s.length(); ++i) {
        char r[1];
        r[0] = s[i];
        //відслідковую початок кінець цифри
        if (atoi(r)){
            if (s[i+1]==' ' || s[i+1]=='\0'){
                control_number_end = true;
            }
        }
        if (atoi(r) || s[i]=='0'){
            control_number = true;
        }
        char r1[1];
        r1[0] = s[i+1];
        if (atoi(r) || s[i]=='0'){
            if (s[i+1] != 'e'){
                if (s[i+1] != '.' && s[i+1] !=','){
                    if(s[i+1] != '+' && s[i+1] !='-'){
                        if (not atoi(r1)){
                            control_number_end = true;
                        }
                    }
                }
            }
        }
        //записує знайдену цифру у рядкок, який потім конвертую у цифру
        if (control_number){
            num += s[i];
            if (atoi(r)){
                control_int = true;
            }
            if (s[i+1]=='.' || s[i+1]==','){
                num += ".";
                i++;
                control_int = false;
                control_double = true;
            }
        } else{
            f1<<s[i];                      //записує все що не є числом
        }

        if (control_number && control_number_end){
            if (control_double){
                //перевожу рядок у число
                double number = stod(num);
                double n = number;
                //запиую число з відповідною точністю
                f1<<"("<<setprecision(4)<<fixed<<n<<")";
                control_number_end = false;
                control_number = false;
                control_int = false;
                control_double = false;
                num = "";
            }
            if (control_int){
                int number = stoi(num);
                double n = number;

                f1<<"("<<setprecision(4)<<fixed<<n<<")";
                control_number_end = false;
                control_number = false;
                control_int = false;
                control_double = false;
                num = "";
            }
        }
    }
    f1.close();
    std::ifstream f2;
    f2.open("help_file.txt", std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    while (!f2.eof()) {
        getline(f2, res);
    }
    f2.close();
    remove("help_file.txt");
    //повертаю змінений рядок
    return res;
}

// функція read_file_number читає файл та перезаписує його у відповідності до змін що вимагаються в умові
void read_file_number(string &filename){
    string s;

    std::ofstream f1;
    f1.open("copy_file.txt", std::ios::out);
    if (f1.bad()){
        std::cout<<"Input file can't be read";
    }
    std::ifstream f2;
    f2.open(filename, std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    while (!f2.eof()) {
        getline(f2, s);
        string res = check_number_in_line(s);
        f1<<res<<endl;
    }
    f1.close();
    f2.close();

    std::ifstream f3;
    f3.open("copy_file.txt", std::ios::in);
    if (f3.bad()){
        std::cout<<"Input file can't be read";
    }
    std::ofstream f4;
    f4.open(filename, std::ios::out);
    if (f4.bad()){
        std::cout<<"Input file can't be read";
    }
    while (!f3.eof()) {
        getline(f3, s);
        f4<<s<<endl;
    }
    f3.close();
    f4.close();
    remove("copy_file.txt");

}

//Змінити всі дати та записи часу у файлі на поточні дату та час

//task4

// функція check_datetime_in_line знаходить всі дати та час у рядку та заміняє їх на поточну дату та час
string check_datetime_in_line(string &s){
    string format="";
    string res = "";
    char buffer[80];
    char buf_time[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char data_now[] = "%d %B %Y ";
    char time_now[] = "%H:%M";
    //отримує потчну дату та час
    strftime(buffer, 80, data_now, timeinfo);
    strftime(buf_time, 80, time_now, timeinfo);
    for (int i = 0; i < s.length(); ++i) {
        char r1[1], r2[1], r3[1], r4[1], r5[1], r6[1], r7[1], r8[1], r9[1], r10[1];
        r1[0] = s[i], r2[0] = s[i+1], r3[0] = s[i+2], r4[0] = s[i+3], r5[0]=s[i+4];
        r6[0] = s[i+5], r7[0] = s[i+6], r8[0] = s[i+7], r9[0] = s[i+8], r10[0] = s[i+9];
        //відстужую у рядку весь час записаний у форматі хх:хх або х:хх наприклад 2:12, 15:44.
        if (atoi(r1)|| s[i]=='0'){
            if (atoi(r2) || s[i+1]=='0'){
                if (s[i+2]==':'){
                    if (atoi(r4)|| s[i+3]=='0'){
                        if (atoi(r5)|| s[i+4]=='0'){
                            //зміню час на поточний
                            format = format + buf_time + " ";
                            res = res + format;
                            format="";
                            i += 5;
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
                        //зміню час на поточний
                        format = format + buf_time + " ";
                        res = res + format;
                        format="";
                        i += 3;
                        continue;
                    }
                }
            }
        }
        //відстежую всі дати
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'){
            //зміню дату на поточну
            format = format + buffer + " ";
            res = res + format;
            format="";
            i += 10;
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            format = format + buffer + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'){
            format = format + buffer + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'){
            format = format + buffer + " ";
            res = res + format;
            format="";
            i += 10;
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='.'&&r6[0]=='.'){
            format = format + buffer + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'){
            format = format + buffer + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'){
            format = format + buffer + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'){
            format = format + buffer + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='.'&&r6[0]=='.'){
            format = format + buffer + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            format = format + buffer + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            format = format + buffer + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r7)&&atoi(r8)&&atoi(r9)&&atoi(r10)&&r3[0]=='/'&&r6[0]=='/'){
            format = format + buffer + " ";
            res = res + format;
            i += 10;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            format = format + buffer + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r4)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            format = format + buffer + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r1)&&atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            format = format + buffer + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        if(atoi(r2)&&atoi(r5)&&atoi(r7)&&atoi(r8)&&r3[0]=='/'&&r6[0]=='/'){
            format = format + buffer + " ";
            res = res + format;
            i += 8;
            format="";
            continue;
        }
        //перезаписую решту рядка
        char t[1];
        t[0] = s[i];
        if (not atoi(t) || t[0]!='.' || t[0]!='/'){
            res = res + s[i];
        }
    }
    //повертаю змінений рядок
    return res;
}

// функція read_file_data_time читає файл та перезаписує файл з датами та часом як вимагається в умові
void read_file_data_time(string &filename){
    string s;

    std::ofstream f1;
    f1.open("copy_file_data.txt", std::ios::out);
    if (f1.bad()){
        std::cout<<"Input file can't be read";
    }
    std::ifstream f2;
    f2.open(filename, std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    while (!f2.eof()) {
        getline(f2, s);
        string res = check_datetime_in_line(s);
        f1<<res<<endl;
    }
    f1.close();
    f2.close();

    std::ifstream f3;
    f3.open("copy_file_data.txt", std::ios::in);
    if (f3.bad()){
        std::cout<<"Input file can't be read";
    }
    std::ofstream f4;
    f4.open(filename, std::ios::out);
    if (f4.bad()){
        std::cout<<"Input file can't be read";
    }
    while (!f3.eof()) {
        getline(f3, s);
        f4<<s<<endl;
    }
    f3.close();
    f4.close();
    remove("copy_file_data.txt");

}