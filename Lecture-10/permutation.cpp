#include<iostream>
using namespace std;
void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}
void permutate(int arr[],int n,int i){
    if(i==n-1){
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int j=i;j<n;j++){
        swap(arr[i],arr[j]);
        permutate(arr,n,i+1);
        swap(arr[i],arr[j]);
    }
    return;
}
int main(){
int arr[10] = {1,2,3};
permutate(arr,3,0);
}
