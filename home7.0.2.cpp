//7.0.2

#include <iostream>
#include <cmath>
using namespace std;

class Point{
   public:
    double x;
    double y;
    static int count;

    void input(){
        cout<<"x y";
        cin>>x>>y;
        count++;
    }
};

double dist(Point p1, Point p2){
    double dis = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    return dis;
}

int Point :: count = 0;

int main(){
    string answer;
    double Perimeter=0;
    Point p0, p1;
    while (true){
        cout<<"y/n?";
        cin>>answer;
        if (answer.length()>=1 && tolower(answer[0])=='y'){
            Point  p2;
            p2.input();

            if (p2.count==1){
                p0 = p2;
            }

            if (p2.count>1){
                Perimeter += dist(p1, p2);
            }
            p1 = p2;
        }
        if (answer.length()>=1 && tolower(answer[0])=='n'){
            Perimeter += dist(p1, p0);
            break;
        }
    }
    Point z;
    cout<<"counter:"<<z.count<<endl;
    cout<<"perimeter:"<<Perimeter<<endl;
}