#include<iostream>
using namespace std;
int i=10;
int main(){
    for(int i=0;i<4;i++){
        i++;
    }
    int i=5;
    {
    int i=19;

    }

    int i=6;
    cout<<::i;
}

