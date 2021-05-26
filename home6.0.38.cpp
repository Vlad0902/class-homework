//6.0.38

#include <iostream>
#include <fstream>

using namespace std;

int count_line(){
    string s;
    string s1;
    int count_line=0;
    std::ifstream f2;
    f2.open("task6.38.txt", std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    ifstream f3;
    f3.open("task6.38_copy.txt", std::ios::in);
    if (f3.bad()){
        std::cout<<"Input file can't be read";
    }
    while (!f2.eof()) {
        f2 >> s;
        while (!f3.eof()){
            f3 >> s1;
            if (s.length()==s1.length()){
                bool control = true;
                for (int i = 0; i < s1.length(); ++i) {
                    if (s[i]!=s1[i]){
                        control = false;
                    }
                }
                if (control){
                    count_line++;
                }
            }
        }
    }
    cout<<"number of lines:"<<count_line-1<<endl;
    f2.close();
    f3.close();
    return 0;
}

int count(){
    string s;
    string s1;
    string str;
    string first_el="r";
    string last_el="a";
    std::ifstream f2;
    f2.open("task6.38.txt", std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    ofstream f1;
    f1.open("task6.38_copy.txt", ios_base::out);
    if (f1.bad()){
        std::cout<<"Create file can't now";
    }

    int count_f=0;
    int count_l=0;
    int count=0;

    while (!f2.eof()) {
        f2 >> s;
        f1<<s<<endl;

        if (s[0]==first_el[0]){
            count_f++;
        }
        if (s[s.length()-1]==last_el[0]){
            count_l++;
        }
        if (s[0]==first_el[0] && s[s.length()-1]==last_el[0]){
            count++;
        }
    }
    f1.close();

    cout<<"number of lines starting with "<<first_el<<":"<<count_f<<endl;
    cout<<"number of lines ending in "<<last_el<<":"<<count_l<<endl;
    cout<<"number of lines starting with "<<first_el<<"and lines ending in "<<last_el<<": "<<count<<endl;
    f2.close();
    return 0;
}
int main(){
    count();
    count_line();
}