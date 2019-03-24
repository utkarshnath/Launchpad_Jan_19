#include<iostream>
using namespace std;
struct Time{
    int sec;
    int minutes;
    int hours;
};
void printTime(Time t){
    cout<<t.hours<<" : "<<t.minutes<<" : "<<t.sec<<endl;
    return;
}
void input(Time * t){
    cin>>t->hours>>t->minutes>>t->sec;
}
Time* input1(){
    Time * t = new Time();
    cin>>t->hours;
    cin>>t->minutes;
    cin>>(*t).sec;
    return t;
}
Time diff(Time t1,Time t2){
    Time t3;
    if(t2.sec>t1.sec){
        t1.minutes--;
        t1.sec+=60;
    }
    t3.sec = t1.sec - t2.sec;
    if(t2.minutes>t1.minutes){
        t1.hours--;
        t1.minutes+=60;
    }
    t3.minutes = t1.minutes - t2.minutes;
    t3.hours = t1.hours- t2.hours;
    printTime(t3);
    return t3;
}
int main(){
    Time t1;
    input(&t1);
    Time * t2 =  input1();
    Time t3 =diff(t1,*t2);
    printTime(t3);
    delete t2;
}







