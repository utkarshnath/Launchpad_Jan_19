#include<iostream>
using namespace std;
int main(){
int arr[2][5] = {{1,2,3,4,5},{6,7,8,9,0}};
cout<<arr<<endl;
cout<<arr[0]<<endl;
cout<<&arr[0][1]<<endl;
cout<<&arr[1]<<endl;
/*
for(int i=0;i<2;i++){
    // For ith row
    for(int j=0;j<10;j++){
        cout<<arr[i][j];
    }
    cout<<endl;
}
*/



}
