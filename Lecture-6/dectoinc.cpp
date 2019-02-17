#include<iostream>
using namespace std;
int main(){
int arr[10] = {5,4,3,10,20,30};
int n = 6;
bool dec = true;
int prev = INT_MAX;
for(int i=0;i<n;i++){
    if(dec == true){
            if(arr[i]>=prev){
                dec = false;
            }
    }else{
        // inc
        if(arr[i]<=prev){
            cout<<"False"<<endl;
            return 0;
        }
    }
    prev = arr[i];
}

}



