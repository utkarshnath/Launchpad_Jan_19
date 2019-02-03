#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        // now check if i is prime or not
        bool isPrime = true;
        for(int j=2;j<=i/2;j++){
            if(i%j==0){
                isPrime = false;
            }
        }
        if(isPrime==true){
            cout<<i<<" ";
        }

    }
}
