#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(){

    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
node * createll(){
    cout<<"Enter a number and -1 to exit"<<endl;
    int data;
    cin>>data;
    node * head = NULL;
    if(data!=-1){
        head = new node();
        head->data = data;
        head->next = NULL;
    }else{
        return head;
    }
    node * tail  = head;
    cin>>data;
    while(data!=-1){
        node * temp = new node();
        temp->data = data;
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
        //tail = temp
        cin>>data;
    }
    return head;
}
void createll2(node * & head){
    cout<<"Enter a number and -1 to exit"<<endl;
    int data;
    cin>>data;
    if(data!=-1){
        head = new node(data);
    }else{
        return;
    }
    node * tail = head;
    cin>>data;
    while(data!=-1){
        node * temp = new node(data);
        tail->next = temp;
        tail = tail->next;
        cin>>data;
    }
    return;
}
void print(node * head){
    while(head){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
void createll3(node **head){
    cout<<"Enter a number and -1 to exit"<<endl;
    int data;
    cin>>data;
    if(data!=-1){
        *head = new node(data);
        //(*head)->data = data;
    }else{
        return;
    }
    node * tail = *head;
    cin>>data;
    while(data!=-1){
        node * temp =  new node(data);
        tail->next = temp;
        tail = tail->next;
        cin>>data;
    }
    return;
}
node * nextElelment(node * head){
    if(head==NULL){
        return NULL;
    }
    return head->next;
}
node* insertAtHead(node * head,int data){
    node * newhead = new node(data);
    newhead->next = head;
    return newhead;
}
void insertAtHead1(node **head,int data){
    node * temp = new node(data);
    temp->next = *head;
    *head = temp;
}
void insertAtTail(node **head,int data){
    node * temp = new node(data);
    if(*head==NULL){
        *head = temp;
        return;
    }
    node * tail = *head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = temp;
    return;
}
void insertAtPositionK(node **head,int data,int k){
    node * temp = new node(data);
    if(k==0){
        temp->next = *head;
        *head = temp;
        return;
    }
    node * it = *head;
    while(--k){
        it = it->next;
    }
    temp->next =  it->next;
    it->next = temp;
    return;
}
node * findAtPositionK(node * head,int k){
    while(k-- && head){
        head = head->next;
    }
    return head;
}

int main(){
//node * head = createll();
node * head = NULL;
//createll2(head);
createll3(&head);
//insertAtTail(&head,12);
print(head);
head = insertAtHead(head,10);
insertAtHead1(&head,11);
print(head);
insertAtTail(&head,12);
print(head);
node * temp = findAtPositionK(head,4);
cout<<temp->data<<endl;
}





