#include<iostream>
using namespace std;
int fac(int n){
int i=1;
for(int j=1;j<=n;j++){
    i = i*j;
}
return i;
}
int ncr(int n,int r){
int a = fac(n);
int b = fac(r);
int c = fac(n-r);
return a/(b*c);
}
int main(){
cout<<ncr(4,2);
int n;
cin>>n;
}
