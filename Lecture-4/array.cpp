#include<iostream>
using namespace std;
int main(){
int arr1[10] = {1,2,3,4,5,6,7,8,9,0};
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}
}
