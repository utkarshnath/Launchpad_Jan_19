#include<iostream>
using namespace std;
void f(int arr1[],int n){
    cout<<&arr1<<endl;
for(int i=0;i<n;i++){
    arr1[i] = 0;
}
}
int main(){
int arr[10] = {1,2,3,4,5};
cout<<&arr<<endl;
cout<<arr<<endl;
f(arr,5);
for(int i=0;i<5;i++){
    cout<<arr[i];
}
cout<<endl;
}
