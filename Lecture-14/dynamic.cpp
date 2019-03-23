#include<iostream>
using namespace std;
int * f(){
    //int * ptr = new int;
    int x = 10;
    int * ptr = &x;;
    //*ptr = 12;
    return ptr;
}

int * f2(int n){
    int * ptr = new int[n];
    return ptr;
}
int main(){
    int * x = f();
    cout<<*x<<endl;
    delete x;
/*
int * ptr = new int;
*ptr = 10;
cout<<*ptr<<endl;
*/
/*
char * ptr = new char;
*ptr = 'C';
cout<<*ptr<<endl;
delete ptr;

int * ptr = new int[10];
for(int i=0;i<10;i++){
    *(ptr+i) = i;
     //ptr[i] = i;
}
for(int i=0;i<10;i++){
     cout<<ptr[i]<<endl;
}
delete []ptr
ptr = 0;
*/
}
