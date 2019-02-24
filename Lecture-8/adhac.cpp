#include<iostream>
using namespace std;
void f(int n){
    n = n+20;
    cout<<&n<<endl;
    return;
}
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
    //cout<<n<<endl;
}
int main(){
    int x = 10;
    float&y = x;
    //y++;
    x = 20;
    //cout<<y<<endl;

    int n = 10;
    int m = 20;
    swap(n,m);
    cout<<n<<endl;
    cout<<m<<endl;
    cout<<a<<endl;

    //cout<<n<<endl;
}
