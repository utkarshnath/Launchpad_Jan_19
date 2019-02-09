#include<iostream>
using namespace std;
int main(){
    char c  = cin.get();
    int x = 0,y=0;
    while(c!='$'){
        if(c=='N'){
            x++;
        }
        else if(c=='S'){
            x--;
        }
        else if(c=='E'){
            y++;
        }
        else{
            y--;
        }
        c  = cin.get();
    }
    if(y>0){
        for(int i=0;i<y;i++){
            cout<<"E";
        }
    }
    if(x>0){
        for(int i=0;i<x;i++){
            cout<<"N";
        }
    }
    if(x<0){
        for(int i=0;i<(-x);i++){
            cout<<"S";
        }
    }
    if(y<0){
        for(int i=0;i<-y;i++){
            cout<<"W";
        }
    }
}






