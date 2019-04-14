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

    void addElement(node *& root, int data){
        node * temp = new node(data);
        if(!root){
            root = temp;
            return;
        }
        node * it = root;
        while(it!=NULL){
            if(it->data>data){
                // move to left sub tree
                if(it->left==NULL){
                    it->left = temp;
                    return;
                }
                it = it->left;
            }else{
                // move to right subtree
                if(it->right==NULL){
                    it->right = temp;
                    return;
                }
                it = it->right;
            }
        }
    }

    bool search(node * root, int data){
        node * it = root;
        while(it){
            if(it->data==data){
                return true;
            }
            if(it->data > data){
                it = it->left;
            }else{
                it = it->right;
            }
        }
        return false;
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


node * removeElement(node * root,int data){
        if(root==NULL){
            return NULL;
        }
        if(root->data==data){
            // remove node
            //no child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            // 1 child
            if(root->left && !root->right){
                node * newroot = root->left;
                delete root;
                return newroot;
            }
            if(!root->left && root->right){
                node * newroot = root->right;
                delete root;
                return newroot;
            }

            //2 child
            node * parent = root->right;
            node * it = root->right;
            if(it->left==NULL){
                it->left = root->left;
                delete root;
                return it;
            }
            while(it->left){
                //parent = it;
                it = it->left;
            }
            it->left = root->left;
            delete root;
            return parent;
        }
        if(root->data>data){
            root->left = removeElement(root->left,data);
        }else{
            root->right = removeElement(root->right,data);
        }

        return root;
    }

void printInRange(node * root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->data > k1){
        printInRange(root->left,k1,k2);
    }
    if(root->data >=k1 && root->data<=k2){
        cout<<root->data<<" ";
    }
    if(root->data < k2){
        printInRange(root->right,k1,k2);
    }
    return;
}

node * sortedLL(node * root){
    if(root==NULL){
        return NULL;
    }
    node * temp = new node(root->data);
    node * headLeft = sortedLL(root->left);
    node * headRight = sortedLL(root->right);
    node * it = headLeft;
    if(it==NULL){
        headLeft = temp;
        temp->left = headRight;
        return temp;
    }
    while(it->left){
        it = it->left;
    }
    it->left = temp;
    temp->left = headRight;
    return headLeft;
}

void printLL(node * root){
    while(root){
        cout<<root->data<<"-->";
        root = root->left;
    }
    cout<<"NULL"<<endl;
}
bool isBST(node * root){
    static int prev = INT_MIN;
    if(!root){
        return true;
    }
    bool left = isBST(root->left);
    if(root->data < prev  || !left){
        return false;
    }
    prev = root->data;
    bool right  = isBST(root->right);
    return right;
}

node *  bstFromSortedArray(int * arr, int start,int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    node * root = new node(arr[mid]);
    root->left = bstFromSortedArray(arr,start,mid-1);
    root->right = bstFromSortedArray(arr,mid+1,end);
    return root;
}
int medianBst(node * root, int len){
    if(root==NULL){
        return -1;
    }
    static int index = -1;
    int l = medianBst(root->left,len);
    if(l!=-1){
        return l;
    }
    index++;
    if(index==len/2){
        return root->data;
    }
    int r = medianBst(root->right,len);
    return r;
}
bool balanced(node * root){
    if(root==NULL){
        return true;
    }
    bool leftBal = balanced(root->left);
    bool rightBal = balanced(root->right);
    int lh = height(root->left);
    int rh = height(root->right);
    return leftBal & rightBal & (abs(lh-rh)<=1)

}
// 8 10 3 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main(){
node * root = NULL;
addElement(root,8);
addElement(root,10);
addElement(root,3);
addElement(root,1);
addElement(root,6);
addElement(root,14);
addElement(root,4);
addElement(root,7);
addElement(root,13);
addElement(root,9);
//levelOrderPrint(root);
//cout<<search(root,11);
//cout<<search(root,13);
//cout<<endl;
//root = removeElement(root,8);
//levelOrderPrint(root);
//root = sortedLL(root);
//printLL(root);
cout<<medianBst(root,8)<<endl;
}







