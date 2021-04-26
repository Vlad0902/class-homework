//5.1.27

#include <iostream>
#include <fstream>
using namespace std;


int main(){
    char buff[50];

    std::ifstream f2;
    f2.open("task5.27.txt", std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    f2>>buff;
    int max=stoi(buff);

    while (!f2.eof()){
        f2>>buff;
        int k=stoi(buff);
        if (k>max){
            max = k;
        }
    }
    cout<<max<< "-maximum number in the file";

    f2.close();
}

