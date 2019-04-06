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
    node * head;
    node * tail;
    int size;

public:
    queue(){
        head = tail = NULL;
        size = 0;
    }
    void enqueue(int data){
        node * temp = new node(data);
        size++;
        if(head==NULL){
            head = tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
        return;
    }

    void dequeue(){
        if(head!=NULL){
            node * temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
    }
    int front(){
        if(head!=NULL){
            return head->data;
        }
        return -1;
    }
};

int main(){

}

