#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node{
    int data;
    node * left;
    node * right;
    int depth;
    node(int data){
        this->data = data;
        left = right = NULL;
        depth = 0;
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
int degree(node * root){
    if(root==NULL){
        return 0;
    }
    return (bool)root->left+(bool)root->right;
}
int height(node * root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight,rightHeight)+1;
}
void populate(node * root,int d){
    if(root==NULL){
        return;
    }
    root->depth = d;
    populate(root->left,d+1);
    populate(root->right,d+1);
    return;
}
void printAtDepthK(node * root,int k){
    if(root==NULL){
        return;
    }
    if(root->depth==k){
        cout<<root->data<<" ";
    }
    printAtDepthK(root->right,k);
    printAtDepthK(root->left,k);
    return;
}
void levelOrderPrint(node * root){
    if(root==NULL){
        return;
    }
    queue<node *>q1;
    queue<node *>q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty()){
        if(!q1.empty()){
            //work for q1
            while(!q1.empty()){
                node * top = q1.front();
                cout<<top->data<<" ";
                if(top->left){
                    q2.push(top->left);
                }
                if(top->right){
                    q2.push(top->right);
                }
                q1.pop();
            }
            cout<<endl;
        }else{
        // work for q2
        while(!q2.empty()){
                node * top = q2.front();
                cout<<top->data<<" ";
                if(top->left){
                    q1.push(top->left);
                }
                if(top->right){
                    q1.push(top->right);
                }
                q2.pop();
            }
            cout<<endl;
        }
    }
}
int diameter(node * root){
    if(root==NULL){
        return 0;
    }
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int lh = height(root->left);
    int rh = height(root->right);
    return max(ld,max(lh+rh+1,rd));
}
pair<int,int> diaFaster(node * root){
    if(root==NULL){
        pair<int,int> p(0,0);
        return p;
    }
    pair<int,int> left = diaFaster(root->left);
    pair<int,int> right = diaFaster(root->right);
    int ld = left.first;
    int rd = right.first;
    int lh = left.second;
    int rh = right.second;
    int d =  max(ld,max(lh+rh+1,rd));
    int h = max(lh,rh)+1;
    pair<int,int> p(d,h);
    return p;
}

bool findNode(node * root,int k){
    if(root==NULL){
        return false;
    }
    if(root->data==k){
        return true;
    }
    bool left = findNode(root->left,k);
    bool right = findNode(root->right,k);
    return left|right;
}
node * mirror(node * root){
    if(!root){
        return NULL;
    }
    node * newRoot = new node(root->data);
    newRoot->right = mirror(root->left);
    newRoot->left = mirror(root->right);
    return newRoot;
}
int find(vector<int>v,int s,int e,int k){
    for(int i=s;i<=e;i++){
        if(v[i]==k){
            return i;
        }
    }
    return -1;
}
node * treeFromInAndPre(vector<int>pre,int pstart,int pend,vector<int>in,int istart,int iend){
        if(pstart>pend){
            return NULL;
        }
        int rootData = pre[pstart];
        node * root = new node(rootData);
        int index = find(in,istart,iend,rootData);
        int l = index - istart;
        int r = iend - index;
        root->left = treeFromInAndPre(pre,pstart+1,pstart+l,in,istart,index-1);
        root->right = treeFromInAndPre(pre,pstart+l+1,pend,in,index+1,iend);
        return root;
}
void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
bool path(node * root,int k,stack<int>&s){
    if(!root){
        return false;
    }
    if(root->data==k){
        s.push(k);
        cout<<"Print stack"<<endl;
        cout<<s.top();
        printStack(s);
        return true;
    }
    s.push(root->data);
    bool left = path(root->left,k,s);
    if(left){
        return true;
    }
    bool right = path(root->right,k,s);
    if(right){
        return true;
    }
    s.pop();
    return false;
}

// 8 10 3 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main(){

node * root = createBtree();
levelorder(root);
cout<<endl;
/*
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
*/
//levelOrderPrint(root);
//cout<<diameter(root)<<endl;
/*
vector<int>pre;
pre.push_back(1);pre.push_back(2);pre.push_back(4);pre.push_back(3);pre.push_back(5);
vector<int>in;
in.push_back(4);in.push_back(2);
in.push_back(1);in.push_back(5);in.push_back(3);
node * root1 = treeFromInAndPre(pre,0,4,in,0,4);
preorder(root1);
cout<<endl;
inorder(root1);
cout<<endl;
*/
stack<int>s;
path(root,13,s);
}




