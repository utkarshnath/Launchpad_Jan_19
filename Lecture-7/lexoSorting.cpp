#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
cin.get();
char arr[10][100];

for(int i=0;i<n;i++){
    cin.getline(arr[i],100);
}
// Code here
for(int i=0;i<n;i++){
    for(int j=0;j<n-1-i;j++){
        int k=0;
        while((arr[j][k]==arr[j+1][k]) && arr[j][k]!='\0'){
            k++;
        }
        // kth is not same
        if(arr[j][k]>arr[j+1][k]){
            //swap
            char temp[100];
            //temp = arr[j];
            int p;
            for(p=0;arr[j][p]!='\0';p++){
                temp[p] = arr[j][p];
            }
            temp[p] = '\0';
            //arr[j] = arr[j+1];
            for(p=0;arr[j+1][p]!='\0';p++){
               arr[j][p] = arr[j+1][p];
            }
            arr[j][p] = '\0';

            //arr[j+1] = temp;
            for(p=0;temp[p]!='\0';p++){
                arr[j+1][p] = temp[p];
            }
            arr[j+1][p] = '\0';

        }
    }
}

for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}
}
