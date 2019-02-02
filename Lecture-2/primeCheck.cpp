#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int i=2;
bool isPrime = true;
while(i<n){
    if(n%i==0){
        isPrime = false;
    }
    i++;
}
if(isPrime){
    cout<<"PRIME"<<endl;
}else{
cout<<"NOT PRIME"<<endl;
}

}
