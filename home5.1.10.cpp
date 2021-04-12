//5.1.10

#include <iostream>
#include <fstream>
using namespace std;


int main(){
    string s;
    std::ifstream f2;
    f2.open("task5.10.txt", std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    ofstream f1;
    f1.open("task5.10_copy.txt", ios_base::out);
    if (f1.bad()){
        std::cout<<"Create file can't now";
    }
    f2>>s;
    f1<<s<<endl;
    int max_len=s.length();
    int min_len=s.length();

    while (!f2.eof()){
        f2>>s;
        f1<<s<<endl;
        int l = s.length();
        if (l>max_len){
            max_len = l;
        }
        if (l<min_len){
            min_len = l;
        }
    }
    cout<<max_len<< "-maximum string in the file"<<endl;
    cout<<min_len<<"-minimum string in the file"<<endl;

    f2.close();
    f1.close();
}

