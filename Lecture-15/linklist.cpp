#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    bool visited;
    node(){

    }
    node(int data){
        this->data = data;
        this->next = NULL;
        visited = false;
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

pair<node*,node*> kreverse(node* head,int k){
    if(head==NULL){
        pair<node*,node*>p(NULL,NULL);
        return p;
    }
    node * it = head;
    for(int i=1;i<k;i++){
        if(it->next==NULL){
            break;
        }
        it = it->next;
    }
    node * newHead = it->next;
    it->next = NULL;
    pair<node*,node*>p = reversell(head);
    pair<node*,node*>currp = kreverse(newHead,k);
    if(currp.first==NULL){
        return p;
    }
    p.second->next = currp.first;
    p.second = currp.second;
    return p;

}
node * mergell(node * head1, node * head2){
    node * head = NULL;
    if(head1==NULL && head2==NULL){
        return NULL;
    }
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data < head2->data){
        head = head1;
        head1 = head1->next;
    }else{
        head = head2;
        head2 = head2->next;
    }
    node * it = head;
    while(head1 && head2){
        if(head1->data < head2->data){
            it->next = head1;
            it = it->next;
            head1 = head1->next;
        }else{
            it->next = head2;
            it = it->next;
            head2 = head2->next;
        }
    }
    if(head1){
        it->next = head1;
    }
    if(head2){
        it->next = head2;
    }
    return head;
}
node * mergeSort(node * head,int start,int end){
    if(start>end){
        return NULL;
    }
    if(start==end){
        return head;
    }
    int mid = (start+end)/2;
    // note this line
    node * midNode = findAtPositionK(head,mid-start);
    node * head1 = head;
    node * head2 = midNode->next;
    midNode->next = NULL;
    head1 = mergeSort(head1,start,mid);
    head2 = mergeSort(head2,mid+1,end);
    head = mergell(head1,head2);
    return head;
}
bool isCircular(node * head){
    while(head){
        if(head->visited==true){
            return true;
        }
        head->visited=true;
        head = head->next;
    }
    return false;
}
int main(){
    /*
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
*/
node * head1 = NULL;
createll2(head1);
print(head1);
//node * head2 = NULL;
//createll2(head2);
//node * head = mergeSort(head1,0,6);
//print(head);
pair<node*,node*> p =kreverse(head1,3);
print(p.first);

}





