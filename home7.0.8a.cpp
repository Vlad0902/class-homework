//7.0.8a)

#include <iostream>
using namespace std;

class Time{
public:
    int hour;
    int minute;
    int second;

    void input(){
        cout<<"Input hour:";
        cin>>hour;
        cout<<"Input minute:";
        cin>>minute;
        cout<<"Input second:";
        cin>>second;

    }

    Time difference(const Time & other);
};

Time Time::difference(const Time &other) {
    Time res;
    if (hour>=other.hour){
        if (minute>=other.minute){
            if (second>=other.second){
                res.hour = hour-other.hour;
                res.minute = minute-other.minute;
                res.second = second-other.second;
            } else{
                res.hour = hour-other.hour;
                res.minute = minute-other.minute-1;
                res.second = second+60-other.second;
            }
        } else{
            res.hour = hour-1-other.hour;
            if (second>=other.second){
                res.minute = minute+60-other.minute;
                res.second = second-other.second;
            } else{
                res.minute = minute+60-1-other.minute;
                res.second = second+60-other.second;
            }
        }
    } else{
        if (other.minute>=minute){
            if (other.second>=second){
                res.hour = other.hour-hour;
                res.minute = other.minute-minute;
                res.second = other.second-second;
            } else{
                res.hour = other.hour-hour;
                res.minute = other.minute-1-minute;
                res.second = other.second+60-second;
            }
        } else{
            res.hour = other.hour-1-hour;
            if (other.second>=second){
                res.minute = other.minute+60-minute;
                res.second = other.second-second;
            } else{
                res.minute = other.minute+60-1-minute;
                res.second = other.second+60-second;
            }
        }

    }
    return res;
}

bool check(const Time &t){
    bool check= true;
    if (t.hour>24 || t.hour<0){
        check = false;
    }
    if (t.second>60 || t.second<0){
        check = false;
    }
    if (t.second>60 || t.second<0){
        check = false;
    }
    return check;
}

int main(){
    Time t1;
    cout<<"first time:"<<endl;
    t1.input();
    bool c1 = check(t1);
    Time t2;
    cout<<"second time:"<<endl;
    t2.input();
    bool c2 = check(t2);
    if (c1 && c2){
        Time res = t1.difference(t2);
        cout<<"difference:"<<endl;
        cout<<"hour:"<<res.hour<<endl;
        cout<<"minute:"<<res.minute<<endl;
        cout<<"second:"<<res.second<<endl;
    } else{
        cout<<"incorrect data"<<endl;
    }

}