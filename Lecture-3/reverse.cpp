#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int a = 0;
while(n>0){
    a = a*10+n%10;
    n = n/10;
}
cout<<a<<endl;
}
