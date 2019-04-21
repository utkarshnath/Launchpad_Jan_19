#include<iostream>
using namespace std;
int arr[1000] = {0};
int fibo(int n){
    if(n==0 || n==1){
        arr[n] = n;
        return n;
    }
    int x;
    if(arr[n]!=0){
        return arr[n];
    }
    x = fibo(n-1)+fibo(n-2);
    arr[n] = x;
    return x;
}

int fiboDP(int n){
    int arr[1000] ={0,1};
    for(int i=2;i<=n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int steps(int n){
    if(n==1){
        return 0;
    }
    int a = INT_MAX,b = INT_MAX,c = INT_MAX;
    if(n%3==0){
        a = steps(n/3)+1;
    }
    if(n%2==0){
        b = steps(n/2)+1;
    }
    c = steps(n-1)+1;
    return min(a,min(b,c));
}
int stepDP(int n){
    int arr[1000] = {-1,0,1,1};
    for(int i=4;i<=n;i++){
        int a = INT_MAX,b = INT_MAX,c = INT_MAX;
        if(i%3==0){
            a = arr[i/3]+1;
        }
        if(i%2==0){
            b = arr[i/2]+1;
        }
        c = arr[i-1]+1;
        arr[i] = min(a,min(b,c));
    }
    return arr[n];
}


int main(){

}
