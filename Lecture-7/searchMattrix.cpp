#include<iostream>
using namespace std;
int main(){
int arr[4][4] = {{10,20,30,40},
                {15,27,36,50},
                {17,34,40,57},
                {25,39,47,60}};
int m = 4,n=4;
int k;
cin>>k;
int i=0,j=n-1;
while(i>=0 && i<m && j>=0 && j<n){
    if(arr[i][j]==k){
        cout<<"FOUND"<<endl;
        return 0;
    }
    if(arr[i][j]>k){
        j--;
    }else{
        i++;
    }
}
cout<<"NOT FOUND"<<endl;
}






