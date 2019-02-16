#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
char c;
c = cin.get();
char largestArray[100];
int maxLength = INT_MIN;
char arr[100];
for(int i=0;i<n;i++){
    cin.getline(arr,100);
    //cout<<arr<<endl;
    int currLength = 0;
    while(arr[currLength]!='\0'){
        currLength++;
    }
    if(currLength>maxLength){
       for(int i=0;i<currLength;i++){
            largestArray[i] = arr[i];
       }
       largestArray[currLength] = '\0';
       maxLength = currLength;
    }
}
cout<<largestArray<<endl;
}

