#include<iostream>
#include<iomanip>
using namespace std;
int main(){
int n;
cin>>n;
float i=0;
int j=0;
float inc = 1;
while(j<3){
    while(i*i<=n){
        i = i+inc;
        cout<<fixed<<setprecision(5)<<i<<endl;
    }
    i = i-inc;
    inc = inc/10;
    j++;
}
cout<<i<<endl;



while(i*i<=n){
        cout<<i<<endl;
    i = i+0.001;
}
cout<<i-0.001;

}

