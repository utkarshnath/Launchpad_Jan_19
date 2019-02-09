#include<iostream>
using namespace std;
int main(){
int a = 0;
for(int i=0;i<20;i++){
    int j = 0;
    for(j=5;j<i;j++){
        a++;
    }
    for(int k=i;k<j;k++){
        a++;
    }
}

cout<<a;
}
