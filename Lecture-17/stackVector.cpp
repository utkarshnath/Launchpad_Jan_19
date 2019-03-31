#include<iostream>
#include<vector>
using namespace std;
template<typename T>
struct stack{
    private:
    //vector<int>v;
    vector<T>v;
public:
    int size(){
        return v.size();
    }
    bool isEmpty(){
        if(v.size()==0){
            return true;
        }
        return false;
        //return v.empty();
    }
    void push(T data){
        v.push_back(data);
        return;
    }
    void pop(){
        if(!isEmpty()){
            v.pop_back();
        }
        return;
    }
    T top(){
        return v[v.size()-1];
    }
};
int main(){
stack<char> s;
stack<int> s1;
cout<<s.v[0]<<endl;
cout<<s.size()<<endl;
s.push('A');
s.push('B');
s.push('C');
cout<<s.top()<<endl;
s.pop();
cout<<s.top()<<endl;
}





