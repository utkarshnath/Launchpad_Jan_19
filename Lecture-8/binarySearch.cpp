#include<iostream>
using namespace std;
bool binarySearch(int arr[],int n,int k){
int start = 0;
int end = n-1;
while(start<=end){
    int mid = (start+end)/2;
    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]>k){
        end = mid-1;
    }else{
        start = mid+1;
    }
}
return false;
}

