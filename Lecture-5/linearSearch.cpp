#include<iostream>
using namespace std;
int global[100000000];
int main(){
int arr[1000000] = {1,2,3,44,56,7,0,8,9,10};
int n;
cin>>n;
for(int i=0;i<10;i++){
    if(arr[i]==n){
        cout<<"found"<<endl;
        return 0;
    }
}
cout<<"not found"<<endl;
}
