#include<iostream>
using namespace std;
void update(int * x){
    int y = 20;
    (*x)++;
    x = &y;
}
void f(int * x,int *y){
    int a = 10;
    int b = 20;
    x = &a;
    y = &b;
}

int * f1(){
    int x = 10;
    int * ptr = &x;
    return ptr;
}
int main(){
    int x = 11,y=12;
   // update(&x);
    //cout<<x<<endl;
    //f(&x,&y);
    //cout<<x<<" "<<y<<endl;

    cout<<*f1()<<endl;

}
