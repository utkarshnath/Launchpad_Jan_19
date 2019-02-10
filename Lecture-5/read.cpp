#include<iostream>
using namespace std;
int main(){
    char arr[100];
    cin.getline(arr,100,'$');
    cout<<arr<<endl;
    /*char c;
    //cin>>c;
    c = cin.get();
    int i;
    for(i=0;c!='\n';i++){
        arr[i] = c;
        //cin>>c;
        c = cin.get();
    }
    arr[i] = '\0';
    cout<<arr<<endl;
    */
}
