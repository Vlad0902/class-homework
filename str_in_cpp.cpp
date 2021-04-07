// aud task 6.0.2
#include <iostream>
#include <cctype>

using namespace std;


string func(string& str){
    string s = "";
    for (size_t i=0; i<str.size(); i++){
        cout<<i<<endl;
        if ((isspace(str[i+1]) && not isspace(str[i])) || i==str.size()-1){
        } else s += str[i];
    }
    return s;

}

int main() {
    string s;
    getline(cin, s);
    cout << func(s);
}