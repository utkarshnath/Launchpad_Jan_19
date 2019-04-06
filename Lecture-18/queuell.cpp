#include<iostream>
using namespace std;
struct node{
    int data;
    node * next;

    node(int data){
        this->data = data;
        next = NULL;
    }
    int getData(){
        return data;
    }
    void setData(int d){
        data = d;
    }
};

class queue{
    node * head = NULL;
    node * tail;
    int size;

public:
    queue(){
        head = tail = NULL;
        size = 0;
    }

    void enqueue();
};

int main(){
node * head = new node(5);
cout<<head->data;
}

