#include<iostream>
#include<cstring>
using namespace std;
int main(){
char arr[5];
cin.getline(arr,5);
int k;
cin>>k;
int n = strlen(arr);
for(int i=0;i<k;i++){
    arr[n+i] = arr[n-k+i];
}
for(int i=n-k-1;i>=0;i--){
    arr[i+k] = arr[i];
}
for(int i=0;i<k;i++){
    arr[i] = arr[n+i];
}
arr[n] = '\0';
cout<<arr<<endl;
}




