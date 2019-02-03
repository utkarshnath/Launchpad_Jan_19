#include<iostream>
using namespace std;
int main(){
    int n = 23;
    int c = 0;
    for(int i=0;i<32;i++){
        c+=n&1;
        n = n>>1;
    }
    cout<<c<<endl;
}
