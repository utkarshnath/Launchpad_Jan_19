#include<iostream>
#include<stack>
using namespace std;
void reverseStack(stack<int>&s){
    stack<int>s1;
    stack<int>s2;
    while(!s.empty()){
        s1.push(s.top());
        s.pop();
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        s.push(s2.top());
        s2.pop();
    }
}
void reverseStack1(stack<int>s,stack<int>&s1){
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    reverseStack1(s,s1);
    s1.push(x);
    return;
}

int main(){

}
