#include<iostream>
using namespace std;
void f(int &x,int &y){
    cout<<&x<<endl;
    x++;
    y++;
    return;
}
int main(){

int a = 10;
int b =20;
int &refer = b;
cout<<&a<<endl;
f(a,b);
cout<<a<<endl;
cout<<b<<endl;
}
