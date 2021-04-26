//6.0.1

#include <iostream>
#include <cctype>

using namespace std;

int check(string& str){
    int count=0;
    string s;
    if (not isspace(str[0])){
        s = str[0];
    }
    for (size_t i=1; i<str.size(); i++){

        if (not isspace(str[i]) && isspace(str[i-1])){
            s = str[i];
        }
        if ((isspace(str[i+1])|| i==str.size()-1) && str[i]==s[0]){
            count++;
            s="";
        }
    }
    return count;
}

int main() {
    string s;
    cout<<"Input string:";
    getline(cin, s);
    cout<<"Result="<<check(s)<<endl;
}