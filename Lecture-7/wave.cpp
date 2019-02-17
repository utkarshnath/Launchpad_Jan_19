#include<iostream>
using namespace std;
int main(){
int arr[10][10] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
int n = 3;
int m = 4;
for(int i=0;i<n;i++){
    //for each column
    if(i%2==0){
        //i is even
        for(int j=0;j<m;j++){
            cout<<arr[j][i]<<" "<<endl;
        }
    }else{
        for(int j=m-1;j>=0;j--){
            cout<<arr[j][i]<<" "<<endl;
        }
    }
}
}
