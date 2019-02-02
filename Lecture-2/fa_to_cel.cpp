#include<iostream>
using namespace std;
int main(){
int initial = 0;
int f = 300;
while(initial<=f){
    int c  = (5*(initial-32))/9;
    cout<<initial<<"  "<<c<<endl;
    initial  = initial+20;
}
}
