#include<iostream>
#include<cstring>
using namespace std;
int main(){
char str1[100];
char str2[100];
cin.getline(str1,100);
cin.getline(str2,100);
int arr[256] ={0};
for(int i=0;str1[i]!='\0';i++){
    char a = str1[i];
    /*int j = a - 'a';
    arr[j] = arr[j]+1;
    */
    int x = int(a);
    arr[x]++;
}
for(int i=0;str2[i]!='\0';i++){
    char a = str2[i];
    /*int j = a - 'a';
    arr[j] = arr[j]-1;*/
    arr[a]--;
}
for(int i=0;i<256;i++){
    if(arr[i]!=0){
        cout<<"NOT"<<endl;
        return 0;
    }
}
cout<<"YES"<<endl;
}
