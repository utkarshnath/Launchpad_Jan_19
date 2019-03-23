#include<iostream>
using namespace std;
void f(int n){
    cout<<"N is "<<n<<endl;
    static int i = n;
    if(i==0){
        return;
    }
    cout<<"I is "<<i<<endl;
    f(i--);
    return;
}
int f1(){
    static int x = 10;
    x++;
    return x;
}

int main(){
    cout<<f1()<<endl;
    cout<<f1()<<endl;
    cout<<f1()<<endl;
    cout<<f1()<<endl;
   /* f(5);
    static int x = 10;
    x++;
    cout<<x<<endl;

    /*
/*
const int x = 10;
//int &y = x;
x = 15;
cout<<x++<<endl;
*/
}
