//task_stl1.10д

#include <iostream>
#include <queue>

using namespace std;

class Auto {
public:
    string name;
    string model;
    string number;
    string id_owner;

    void input(){
        cout<<"Input information:"<<endl;
        cout<<"Input name:";
        cin>>name;
        cout<<"Input model:";
        cin>>model;
        cout<<"Input number:";
        cin>>number;
        cout<<"Input id_owner:";
        cin>>id_owner;
    };

    void output(){
        cout<<"AUTO: name: "<<name<<", model: "<<model<<", number: "<<number<<", id_owner: "<<id_owner<<endl;
    }
};

void Quequ (queue<Auto> a){
    cout<<"Queue auto :"<<a.size()<<endl;
    int i = 1;
    while (true){
        cout<<i<<endl;
        Auto au = a.front();
        au.output();
        a.pop();
        i++;
        if (a.empty()){
            cout<<"\nthe queue is empty"<<endl;
            break;
        }

    }
}

int main(){
    queue<Auto> au;
    int n;
    cout<<"Input n:";
    cin>>n;
    for (int i = 0; i < n; ++i) {
        Auto a1;
        a1.input();
        au.push(a1);
    }
    Quequ(au);
}