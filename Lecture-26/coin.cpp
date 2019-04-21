#include<iostream>
using namespace std;
int coinDeno(int n,int arr[],int size){
    if(n<0 || size<=0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return coinDeno(n,arr,size-1) +coinDeno(n-arr[size-1],arr,size);
}
int coinDp(int n,int arr[],int size){
    int table[n+1][size+1];
    for(int i=0;i<=size;i++){
        table[0][i] = 1;
    }
    for(int i=0;i<=n;i++){
        table[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=size;j++){
            int x = table[i][j-1];
            int y = 0;
            if(i-arr[j]>=0){
                y = table[i-arr[j]][j];
            }
            table[i][j] = x+y;
        }
    }
    return table[n][size];
}
int main(){

}
