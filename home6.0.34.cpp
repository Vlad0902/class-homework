//6.0.34

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string number[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string s;
    std::ifstream f2;
    f2.open("task6.34.txt", std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    ofstream f1;
    f1.open("task6.34_copy.txt", ios_base::out);
    if (f1.bad()){
        std::cout<<"Create file can't now";
    }

    while (!f2.eof()){
        f2>>s;
        for (int i = 0; i < s.length(); ++i) {
            char control[1] ;
            control[0] = s[i];
            int num = atoi(control);
            if (num!=0 && atoi(control)==num){
                f1<<number[num];
            }else{f1<<s[i];}
            if (i+1==s.length()) {
                f1<<""<<endl;
            }

        }
    }
    f2.close();
    f1.close();
}