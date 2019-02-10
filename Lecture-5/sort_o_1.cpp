#include<iostream>
using namespace std;
int main(){
int arr[10] = {1,0,0,1,0,0};
int n = 6;
int start = 0;
int end = n-1;
while(start<end){
    while(arr[start]==0){
        start++;
    }
    while(arr[end]==1){
        end--;
    }
    if(start>=end){
        break;
    }
    arr[start] = 0;
    arr[end] = 1;
    start++;
    end--;
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}



