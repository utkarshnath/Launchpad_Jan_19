#include<iostream>
using namespace std;
int main(){
char arr[100];
cin.getline(arr,100);
int start=0;
int end;
for(end=0;arr[end]!='\0';end++);
end--;
while(start<end){
    if(arr[start]!=arr[end]){
        cout<<"NOT"<<endl;
        return 0;
    }
    start++;
    end--;
}
cout<<"YES"<<endl;
}


