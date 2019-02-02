#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int i=0;
int value;
int min = 100000;
int max = -10000;
int sum = 0;
while(i<n){
    cin>>value;
    // handle min
    if(value<min){
        min = value;
    }
    //handle max
    if(value>max){
        max = value;
    }
    //handle sum
    sum = sum+value;
    i++;
}
cout<<"min"<<min<<endl;
cout<<"max"<<max<<endl;
cout<<"avg"<<sum/n<<endl;
}


