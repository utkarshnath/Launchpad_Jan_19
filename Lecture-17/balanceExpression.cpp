#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
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
*/
int main(){
stack<char>s;
char arr[100] = "{()}]";
int i=0;
while(arr[i]!='\0'){
    if(arr[i]=='(' || arr[i]=='{' || arr[i]=='['){
        s.push(arr[i]);
       }else{
        char top = s.top();
        if((arr[i]==')' && top=='(') || (arr[i]=='}' && top=='{') || (arr[i]==']' && top=='[')){
            s.pop();
        }else{
            cout<<"Unbalanced"<<endl;
            return 0;
        }
       }
       i++;
}
if(s.empty()){
    cout<<"Balanced"<<endl;
}else{
    cout<<"Unbalanced"<<endl;
}
}





