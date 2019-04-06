#include<iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    node * left;
    node * right;
    node(int data){
        this->data = data;
        left = right = NULL;
    }
};
node * createBtree(){
    cout<<"enter data and -1 if empty"<<endl;
    int data;
    cin>>data;
    node * root;
    if(data!=-1){
        root = new node(data);
    }else{
        return NULL;
    }
    queue<node *>q;
    q.push(root);
    while(!q.empty()){
        node * top = q.front();
        cout<<"Enter data for left child of "<<top->data<<endl;
        cin>>data;
        if(data!=-1){
            node * temp = new node(data);
            top->left = temp;
            q.push(temp);
        }
        cout<<"Enter data for right child of "<<top->data<<endl;
        cin>>data;
        if(data!=-1){
            node * temp = new node(data);
            top->right = temp;
            q.push(temp);
        }
        q.pop();
    }
    return root;
}
void preorder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void postorder(node * root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}

void inorder(node * root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

void levelorder(node * root){
    queue<node *>q;
    if(root){
        q.push(root);
    }
    while(!q.empty()){
        node * top = q.front();
        cout<<top->data<<" ";
        if(top->left){
            q.push(top->left);
        }
        if(top->right){
            q.push(top->right);
        }
        q.pop();
    }
    return;
}
int count(node * root){
    if(root==NULL){
        return 0;
    }
    int left = count(root->left);
    int right = count(root->right);

    return left+right+1;
}
int greatestNode(node * root){
    if(root==NULL){
        return INT_MIN;
    }
    int left = greatestNode(root->left);
    int right = greatestNode(root->right);
    return max(root->data,max(left,right));
}
int countGreaterThenX(node * root,int x){
    if(root==NULL){
        return 0;
    }
    int left = countGreaterThenX(root->left,x);
    int right = countGreaterThenX(root->right,x);
    if(root->data > x){
        return left+right+1;
    }
    return left+right;
}
pair<node *,int> maxPair(pair<node *,int> a, pair<node *,int> b){
    if(a.second > b.second){
        return a;
    }
    return b;
}
pair<node *,int> maxGroup(node * root){
    if(root==NULL){
        pair<node *,int> p(NULL,INT_MIN);
        return p;
    }
    pair<node *,int> left = maxGroup(root->left);
    pair<node *,int> right = maxGroup(root->right);
    int sum = root->data;
    if(root->left){
        sum+=root->left->data;
    }
    if(root->right){
        sum+=root->right->data;
    }
    pair<node *,int> curr(root,sum);
    return maxPair(curr,maxPair(left,right));


}
// 8 10 3 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main(){
node * root = createBtree();
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;
levelorder(root);
cout<<endl;
cout<<count(root)<<endl;
cout<<greatestNode(root)<<endl;

pair<node *,int> p = maxGroup(root);
cout<<p.second<<endl;
}




