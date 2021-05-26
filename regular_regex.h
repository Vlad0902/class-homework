// Файл regular_regex.h описує виконання завдання 12. Регулярні вирази
// тут передбачено виконання завданя за допомогою бібліотеки <regex>

#include <iostream>
#include <regex>
#include <ctime>
using namespace std;

//Дана частина коду виконує завдання: даному текстовому файлі знайти всі гіперпосилання та вивести їх
//разом зі словом (слово відокремлюється пробілами та знаками
//пунктуації) що стоїть перед ним

//task1

// функція task1_links повертає всі посилання з словами, що виявлині в тексті

string task1_links(string &s){
    //регурярний вираз співпадіння якому ми маємо виявити в тексті
    regex rx_links("(\\w+)(\\.? ?:?,?;?'?\\\"?\\??\\(?\\)?\\[?\\]?\\{?\\}?\\*?\\+?\\&?\\!?)(https://.+?/) ");
    smatch m;
    string res;
    int j = 0;
    string st;
    for (int k = j ; k < s.length(); ++k) {
        st +=s[k];
        //перевіряє чи є такий підрядок в тексті в разі позитивної відповіді до res додає посилання з словом
        if(regex_search(st, m , rx_links)){
            res += " link: ";
            res += m[3];
            res += " word: ";
            res += m[1];
            res += "\n";
            st = "";
            j += m.length();
            continue;
        } else{
            j++;
        }
    }
    //повертає всі посилання з словами
    return res;
}


// програма read_file_for_links_regex передбачає читання файлу в якому требе знайти посилання
void read_file_for_links_regex(string &filename){
    string s;

    std::ifstream f2;
    f2.open(filename, std::ios::in); //"regular_1.txt"
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    std::ofstream f1;
    f1.open("result_task1_regex.txt", std::ios::app);
    if (f1.bad()){
        std::cout<<"Input file can't be read";
    }
    while (!f2.eof()) {
        getline(f2, s);
        f1<<task1_links(s);
    }
    f1.close();
    f2.close();
}

//Знайти в даному текстовому файлі всі дати в форматах __.__.__ та
//__/__/__ (в кінці можуть бути 2 або 4 цифри, а також ____(рік).__.__) та
//перевести їх всі до єдиного формату __(рік) назва місяцю __(число).

//task2

// програма task2_data знаходить всі дати та замінює їх на потрібний формат

string task2_data(string &s){
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                        "November", "December"};
    //регулярні вирази що підстежують дати які нам треба знайти
    regex rx_data1("(\\d{1,2})(\\.)(\\d{1,2})(\\.)(\\d{2,4})");
    regex rx_data2("(\\d{1,2})(\\/)(\\d{1,2})(\\/)(\\d{2,4})");
    smatch m;
    string res;
    int j = 0;
    string st;
    string format;

    for (int k = j ; k < s.length(); ++k) {
        st +=s[k];
        //перевіряє чи є такий підрядок в тексті в разі позитивної відповіді змінює дату на потрібний формат
        if(regex_search(st, m , rx_data1)&&s[k+1]==' ' || regex_search(st, m , rx_data2)&&s[k+1]==' '){
            format += m[5];
            format += " ";
            int mon = stoi(m[3]);
            format += month[mon-1];
            format += " ";
            format += m[1];
            //regex_replace-змінює підрядок який відповідає регулярному виразові
            st = regex_replace(st, rx_data1, format);
            st = regex_replace(st, rx_data2, format);
            res += st;
            format = "";
            st = "";
            j += m.length();
            continue;
        } else{
            j++;
        }
    }
    res += st;
    //повертає змінений рядок
    return res;
}

// програма read_file_date_regex передбачає читання файлу в якому треба змінити
// дати на потрібний нам формат та перезапис його у правильному форматі
void read_file_date_regex(string &filename){
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
        string res = task2_data(s);
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

// функція task3_number знаходить всі числа в рядку і змінює їх за вимогою умови
string task3_number(string &s){
    //вираз що відповідає цифрі у різних форматах
    regex rx_number("(\\d+)(.?,?)(\\d*e?\\+?-?\\d*)");
    smatch m;
    string res;
    std::ofstream f1;
    f1.open("help_file.txt", std::ios::out);
    if (f1.bad()){
        std::cout<<"Input file can't be read";
    }
    int j = 0;
    string st;
    string number;
    bool control = false;

    for (int k = j ; k < s.length(); ++k) {
        st +=s[k];
        char r[1];
        r[0] = s[k];
        if (atoi(r) || s[k]=='0'){
            control = true;
        }
        //знаходимо у рядку підрядок що задовольняє ркгулярний вираз і змнінюємо його на потрібний формат з умови
        if(control && regex_search(st, m , rx_number)&&s[k+1]==' ' || control &&
                regex_search(st, m , rx_number)&&s[k+1]=='\0'){
            number += m[1];
            number += ".";
            number += m[3];
            double num = stod(number);
            f1<<"("<<setprecision(4)<<fixed<<num<<")";
            control = false;
            number = "";
            st = "";
            j += m.length();
            continue;
        } else{
            j++;
        }
        if (not control){
            f1<<s[k];
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
    //повертаємо змінений підрядок
    return res;
}

// функція read_file_number_regex читає файл та перезаписує його у відповідності до змін що вимагаються в умові

void read_file_number_regex(string &filename){
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
        string res = task3_number(s);
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

// функція task4_data_time знаходить всі дати та час у рядку та заміняє їх на поточну дату та час

string task4_data_time(string &s){
    //регулярні вирази що знаходить всі дати у рядку
    regex rx_data1("(\\d{1,2}\\.\\d{1,2}\\.\\d{2,4})");
    regex rx_data2("(\\d{1,2}\\/\\d{1,2}\\/\\d{2,4})");
    //регулярні вирази що знаходить весь час у рядку
    regex rx_time("(\\d{1,2}\\:\\d{1,2})");
    smatch m;
    char buffer_data[80];
    char buf_time[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char data_now[] = "%d %B %Y";
    char time_now[] = "%H:%M";
    //отримує поточну дату та час
    strftime(buffer_data, 80, data_now, timeinfo);
    strftime(buf_time, 80, time_now, timeinfo);
    //змінюю дату та час у рядку на поточну дату та час
    s = regex_replace(s, rx_data1, buffer_data);
    s = regex_replace(s, rx_data2, buffer_data);
    s = regex_replace(s, rx_time, buf_time);
    //повертає змінений рядок
    return s;
}

// функція read_file_data_time_regex читає файл та перезаписує файл з датами та часом як вимагається в умові

void read_file_data_time_regex(string &filename){
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
        string res = task4_data_time(s);
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