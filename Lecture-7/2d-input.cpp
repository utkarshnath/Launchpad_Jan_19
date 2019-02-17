#include<iostream>
using namespace std;
int main(){
int arr[10][10];
int n,m;
cin>>m>>n;
for(int i=0;i<m;i++){
    //for ith row
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
int k;
cin>>k;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(arr[i][j]==k){
            cout<<"FOUND";
            return 0;
        }
    }
}
cout<<"NOT FOUND"<<endl;
return 0;
}



