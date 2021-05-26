//task_stl2.9

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    string file1 = "file1.txt";
    string file2 = "file2.txt";
    string str1;
    set<string> s1;
    set<string> s2;

    char punct[] = {'.', ',', '?', '!', ':', ':', '(', ')'};
    set <char> punctuation(punct, punct+8);

    ifstream f1;
    f1.open(file1, std::ios::in);
    if (f1.bad()){
        std::cout<<"Input file can't be read";
    }
    ifstream f2;
    f2.open(file2, std::ios::in);
    if (f2.bad()){
        std::cout<<"Input file can't be read";
    }
    while (f1>>str1){
        int n = str1.size();
        if (punctuation.count(str1[n-1])){
            str1.erase(n-1, n);
        }
        if (punctuation.count(str1[0])){
            str1.erase(0, 1);
        }
        s1.insert(str1);
    }

    while (f2>>str1){
        int n = str1.size();
        if (punctuation.count(str1[n-1])){
            str1.erase(n-1, n);
        }
        if (punctuation.count(str1[0])){
            str1.erase(0, 1);
        }
        s2.insert(str1);
    }

    vector<string> s3;
    vector<string> s4;
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), std::back_inserter(s3));
    set_symmetric_difference(s1.begin(),s1.end(),s2.begin(),s2.end(), std::back_inserter(s4));
    cout<<"Common words:"<<endl;
    for (int i = 0; i < s3.size(); ++i) {
        cout<<s3[i]<<endl;
    }
    cout<<"Not common words"<<endl;
    for (int i = 0; i < s4.size(); ++i) {
        cout<<s4[i]<<endl;
    }
}