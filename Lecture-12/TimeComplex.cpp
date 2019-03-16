#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[],int n){
 for(int i=0;i<n;i++){
        int min = INT_MAX;
        int minIndex = i;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[minIndex] = temp;
    }
}
void merge(int arr[],int start1,int start2,int end){
    int k = start1;
    int m = start2-1;
    int n = end;
    int temp[1000000];
    int index=0;
    while(start1<=m && start2<=n){
        if(arr[start1]<arr[start2]){
            temp[index++] = arr[start1++];
        }else{
            temp[index++] = arr[start2++];
        }
    }
    while(start1<=m){
        temp[index++] = arr[start1++];
    }
     while(start2<=n){
        temp[index++] = arr[start2++];
    }
    for(int i=0;i<index;i++){
        arr[k+i] = temp[i];
    }
    return;
}
void mergeSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid+1,end);
    return;
}
int main(){
int arr[1000000] = {0};
clock_t start = clock();
bubbleSort(arr,1000000);
//selectionSort(arr,1000);
//mergeSort(arr,0,999999);
clock_t end = clock();
cout<<end-start<<endl;
}







