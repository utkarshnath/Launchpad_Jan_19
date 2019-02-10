#include<iostream>
using namespace std;
int main(){

    for(int i=0;i<10;i++){
        cout<<"hello"<<endl;
        if(i>3){
            continue;
        }
        cout<<"hey!";
    }
    for(int i=0;i<10;i++){
        if(i==3){
            break;
        }
        for(int j=0;j<10;j++){
            cout<<i<<" "<<j<<endl;
        }
        cout<<"HEY!"<<endl;
    }
}
