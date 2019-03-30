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
void deleteAtPositionK(node ** head,int k){
    if(k==0){
        node * temp = *head;
        *head = temp->next;
        //*head = (*head)->next;
        delete temp;
        return;
    }
    node * it = *head;
    while(--k){
        it = it->next;
    }
    node * temp = it->next;
    it->next = temp->next;
    //it->next = it->next->next;
    delete temp;
    return;
}
int length(node * head){
    int l = 0;
    while(head!=NULL){
        l++;
        head = head->next;
    }
    return l;
}

node * midpoint(node * head){
    node * it1 = head;
    node * it2 = head;
    while(it2->next && it2->next->next){
        it1 = it1->next;
        it2 = it2->next->next;
    }
    return it1;
}
bool findElemet(node * head,int data){
    if(head==NULL){
        return false;
    }
    if(head->data==data){
        return true;
    }
     bool x =  findElemet(head->next,data);
     return x;

}
void swap(node ** head,int i,int j){
    if(i==0 && j==1){
        node * a = *head;
        node * b = a->next;
        node * bnext = b->next;
        *head = b;
        b->next = a;
        a->next = bnext;
        return;
    }else if(i==0){
        node * a = *head;
        node * prevb = findAtPositionK(*head,j-1);
        node * b = prevb->next;
        node * bnext = b->next;
        *head = b;
        b->next = a->next;
        prevb->next = a;
        a->next = bnext;
        return;
    }else if(j-i==1){
        node * preva = findAtPositionK(*head,i-1);
        node * a = preva->next;
        node * b = a->next;
        node * bnext = b->next;
        preva->next = b;
        b->next = a;
        a->next = bnext;
        return;
    }else{
    node * prev1 = findAtPositionK(*head,i-1);
    node * prev2 = findAtPositionK(*head,j-1);
    node * a = prev1->next;
    node * b =  prev2->next;
    node * bnext = b->next;
    prev1->next = b;
    b->next = a->next;
    prev2->next = a;
    a->next = bnext;
    }
}
void bubbleSort(node ** head){
    int n = length(*head);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            node * a = findAtPositionK(*head,j);
            node * b = findAtPositionK(*head,j+1);
            if(a->data > b->data){
                swap(head,j,j+1);
            }
        }
    }
}
node * ithFromLast(node * head,int& i){
    if(head==NULL){
        return NULL;
    }
    node * it = ithFromLast(head->next,i);
    i--;
    if(i==0){
        return head;
    }
    return it;
}
node * ithFromLast1(node * head,int n){
    static int i = n;
    if(head==NULL){
        return NULL;
    }
    node * it = ithFromLast1(head->next,i);
    i--;
    if(i==0){
        return head;
    }
    return it;
}
node * reversell(node* head, node *&tail){
    if(head->next==NULL){
        tail = head;
        return head;
    }
    node * newhead = reversell(head->next,tail);
    tail->next = head;
    tail = head;
    tail->next = NULL;
    return newhead;
}
pair<node *,node *> reversell(node * head){
    if(head->next == NULL){
        pair<node *,node*> p;
        p.first = head;
        p.second = head;
        return p;
    }
    pair<node *,node *> p = reversell(head->next);
    p.second->next = head;
    p.second = head;
    head->next = NULL;
    return p;

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
//node * temp = findAtPositionK(head,4);
//cout<<temp->data<<endl;
//deleteAtPositionK(&head,2);
//print(head);
//deleteAtPositionK(&head,0);

bubbleSort(&head);
print(head);
node * tail = 0;
pair<node*,node*>p = reversell(head);
print(p.first);
}





