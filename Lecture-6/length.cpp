#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char arr[100];
    cin.getline(arr,100);
    int start = 0;
    /*int i=0;
    while(arr[i]!='\0'){
        i++;
    }*/
    int end = strlen(arr) - 1;
    while(start<end){
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    cout<<arr<<endl;
}



