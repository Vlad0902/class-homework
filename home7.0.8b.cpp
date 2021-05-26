//7.0.8b)

#include <iostream>
using namespace std;

class Date{
public:
    int year;
    int month;
    int day;

    void input(){
        cout<<"Input year:";
        cin>>year;
        cout<<"Input month:";
        cin>>month;
        cout<<"Input day:";
        cin>>day;

    }

    Date difference(const Date & other);
};

Date Date::difference(const Date &other) {
    Date res;
    long long int first=0;
    long long int second=0;
    long int result=0;
    for (int i = 1; i <= year; ++i) {
        if (i%4==0){
            first += 366;
        } else{
            first += 365;
        }
    }
    for (int i = 1; i <= month; ++i) {
        if (i==1||i==3||i==5||i==7||i==8||i==10||i==12){
            first += 31;
        }
        if (i==4||i==6||i==9||i==11){
            first += 30;
        }
        if (i==2){
            if (year%4==0){
                first += 29;
            } else{
                first +=28;
            }
        }
    }
    first += day;
    for (int i = 1; i <= other.year; ++i) {
        if (i%4==0){
            second += 366;
        } else{
            second += 365;
        }
    }
    for (int i = 1; i <= other.month; ++i) {
        if (i==1||i==3||i==5||i==7||i==8||i==10||i==12){
            second += 31;
        }
        if (i==4||i==6||i==9||i==11){
            second += 30;
        }
        if (i==2){
            if (other.year%4==0){
                second += 29;
            } else{
                second +=28;
            }
        }
    }
    second += other.day;
    result = abs(first-second);
    res.year = 0;
    res.month = 0;
    res.day = 0;
    while (result>=365){
        res.year += 1;
        if(res.year%4==0){
            result -=366;
        } else{
            result -=365;
        }
    }
    int mas[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (result>mas[res.month]){
        res.month +=1;
        if (res.month==1||res.month==3||res.month==5||res.month==7||res.month==8||res.month==10||res.month==12){
            if (result>=31){
                result -= 31;
            }
        }
        if (res.month==4||res.month==6||res.month==9||res.month==11){
            if (result>=30){
                result -= 30;
            }
        }
        if (res.month==2){
            if (res.year%4==0){
                if (result>=29){
                    second -= 29;
                }
            } else{
                first -=28;
            }
        }
    }
    res.day = result;
    return res;
}

bool check(const Date &d){
    bool check= true;
    if ( d.year<0){
        check = false;
    }
    if (d.month>12 || d.month<0){
        check = false;
    }
    if (d.day>31 || d.day<0){
        check = false;
    }
    return check;
}

int main(){
    Date  d1;
    cout<<"first date:"<<endl;
    d1.input();
    bool c1 = check(d1);
    Date  d2;
    cout<<"second date:"<<endl;
    d2.input();
    bool c2 = check(d2);
    if (c1 && c2){
        Date  res = d1.difference(d2);
        cout<<"difference:"<<endl;
        cout<<"year:"<<res.year<<endl;
        cout<<"month:"<<res.month<<endl;
        cout<<"day:"<<res.day<<endl;
    } else{
        cout<<"incorrect data"<<endl;
    }
}