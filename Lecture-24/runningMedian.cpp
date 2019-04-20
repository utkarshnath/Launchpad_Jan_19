#include<iostream>
#include<queue>
using namespace std;
int main(){

priority_queue<int>p1; // max heap
priority_queue<int,vector<int>,greater<int> >p2;
int x;
cin>>x;
int median = INT_MAX;
while(x!=-1){
    if(p1.size() > p2.size()){
        if(x<median){
            p2.push(p1.top());
            p1.pop();
            p1.push(x);
        }else{
            p2.push(x);
        }
        median = (p1.top()+p2.top())/2;
    }else if(p1.size() < p2.size()){
        if(x<median){
           p1.push(x);
        }else{
            p1.push(p2.top());
            p2.pop();
            p2.push(x);
        }
        median = (p1.top()+p2.top())/2;
    }
    else{
        if(x<median){
            p1.push(x);
            median = p1.top();
        }else{
            p2.push(x);
            median = p2.top();
        }
    }
    cout<<median<<" ";
    cin>>x;
}

}
