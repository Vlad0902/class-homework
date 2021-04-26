//6.0.16

#include <iostream>
#include <cctype>

using namespace std;

int check(string& str){
    int count=0;
    string el;
    cout<<"Input element:";
    cin>>el;
    bool control = false;
    if (not isspace(str[0])){
        control = true;
    }
    for (size_t i=0; i<str.size(); i++){

        if (not isspace(str[i]) && isspace(str[i-1])){
            control = true;
        }
        if (control && str[i]==el[0]){
            count++;
            control = false;
        }
        if (not isspace(str[i]) && isspace(str[i+1])) {
            control = false;
        }
    }
    return count;
}

int main() {
    string s;
    cout<<"Input string:";
    getline(cin, s);
    int res= check(s);
    cout<<"Result="<<res<<endl;
}