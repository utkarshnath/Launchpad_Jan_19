#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int i=0;
int v = 1;
while(i<n){
    int j=0;
    while(j<=i){
        cout<<v<<" ";
        j++;
        v++;
    }
    cout<<endl;
    i++;
}

}
