#include<iostream>
#include<queue>
using namespace std;
struct stack{
private:
    queue<int>q1;
    queue<int>q2;
public:
    bool isEmpty(){
        if(q1.empty() && q2.empty()){
            return true;
        }
        return false;
    }
    int size(){
        if(q1.empty()){
            return q2.size();
        }
        return q1.size();
    }
    void push(int data){
        if(isEmpty()){
            q1.push(data);
            return;
        }
        if(q1.empty()){
            q1.push(data);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }else{
            q2.push(data);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    void pop(){
        if(!isEmpty()){
            if(q1.empty()){
                q2.pop();
            }else{
                q1.pop();
            }
        }
    }

    int top(){
        if(!isEmpty()){
            if(q1.empty()){
               return q2.front();
            }else{
                return q1.front();
            }
        }
    }
};
void reverseQueue(queue<int>&q){
    if(q.empty()){
        return;
    }
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
    return;
}
int main(){
stack s;
s.push(10);
s.push(20);
s.push(30);
cout<<s.top()<<endl;;
s.pop();
cout<<s.top()<<endl;;
s.pop();
cout<<s.top()<<endl;;
}
