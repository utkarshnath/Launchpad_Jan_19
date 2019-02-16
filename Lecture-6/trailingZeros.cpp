#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int count = 0;
int i=5;
while(n/i>0){
    count+=n/i;
    i = i*5;
}
cout<<count<<endl;
}
