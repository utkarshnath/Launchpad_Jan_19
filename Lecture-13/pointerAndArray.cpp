#include<iostream>
using namespace std;
void f(int * arr,int n){
    cout<<*(arr)<<endl;
    cout<<*(arr+2)<<endl;
    cout<<arr[0]<<endl;
    cout<<3[arr]<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void f1(int arr[10],int n){  // int * arr
    cout<<sizeof(arr)<<endl;
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
int arr[10] =  {1,2,3,4,5};
cout<<sizeof(arr)<<endl;
f1(arr,5);
}





