#include<iostream>
using namespace std;
void farenheit_to_cel(){
    for(int f=0;f<=300;f+=20){
       int c = (5*(f-32))/9;
       cout<<f<<" "<<c<<endl;
    }
}
void farenheit_to_cel1(int start,int end,int step){
    for(int f=start;f<=end;f+=step){
       int c = (5*(f-32))/9;
       cout<<f<<" "<<c<<endl;
    }
}

int sum_of_N(int n){
    int sum=0;
    for(int i=0;i<=n;i++){
        sum+=  i;
    }
    return sum;
}
bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void allPrime(int n){
    for(int i=2;i<=n;i++){
        //check for i
        if(isPrime(i)){
            cout<<i<<endl;
        }
    }
}
int main(){
int s;
int e;
int step;
int n;
cin>>n;
allPrime(n);
/*
bool prime = isPrime(n);
if(prime){
    cout<<n<<" is prime"<<endl;
}else{
    cout<<n<<" is not prime"<<endl;
}*/
//cin>>s>>e>>step;
//farenheit_to_cel1(s,e,step);
//cout<<sum_of_N(10)<<endl;
}
