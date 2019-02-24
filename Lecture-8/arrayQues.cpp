#include<iostream>
#include<climits>
using namespace std;
int sumOfArray(int arr[],int n){
int sum = 0;
for(int i=0;i<n;i++){
    sum+=arr[i];
}
return sum;
}
void selectionSort(int arr[10],int n){
    for(int i=0;i<n;i++){
        int min = INT_MAX;
        int minIndex = i;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                minIndex = j;
            }
        }
        int temp   = arr[i];
        arr[i] = min;
        arr[minIndex] = temp;
    }
}
void mergeArray(int arr1[10],int arr2[10],int n,int m){
int arr3[20];
int i=0,j=0;
int index = 0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            arr3[index++] = arr1[i++];
        }else{
            arr3[index++] = arr2[j++];
        }
    }
    while(i<n){
        arr3[index++] = arr1[i++];
    }
    while(j<m){
        arr3[index++] = arr2[j++];
    }
    for(int i=0;i<index;i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr1[10] = {5,10,12,13,17,20,25};
    int arr2[10] = {6,8,9,12,15};
    mergeArray(arr1,arr2,7,5);
    /*selectionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
    cout<<endl;
    */
}
