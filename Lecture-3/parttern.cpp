#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int i=0;
while(i<n){
    // for ith row
    int j=0;
    while(j<n-i-1){
        cout<<" ";
        j++;
    }
    //inc part
    j = i+1;
    while(j<=2*i+1){
        cout<<j;
        j++;
    }
    //dec part
    j = 2*i;
    while(j>=i+1){
        cout<<j;
        j--;
    }
    cout<<endl;
    i++;
}

}
