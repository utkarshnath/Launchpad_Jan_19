#include<iostream>
using namespace std;
int main(){
/*
char arr[][100] = {{"ABC"},
                    {"DEF"}};
*/
char arr[10][100];
int n;
cin>>n;
cin.get();
for(int i=0;i<n;i++){
    cin.getline(arr[i],100);
}
char temp[100];
cin.getline(temp,100);
for(int i=0;i<n;i++){
    // compare temp & arr[i]
    int j=0;
    while(temp[j]==arr[i][j]){
        if(temp[j]=='\0'){
            cout<<"FOUND"<<endl;
            return 0;
        }
        j++;
    }
}
cout<<"NOT FOUND"<<endl;
}
