#include<iostream>
#include <unordered_set>
#include<map>
using namespace std;
map<int,vector<int> >mymap;
void fillMap(node * root,int value){
    if(root==NUll){
        return;
    }
    mymap[value].push_back(root->data);
    fillMap(root->left,value-1);
    fillMap(root->right,value+1);
    return;
}
void printVertical(node * root){
    fillMap(root,0);
    map<int,vector<int> > :: iterator it;
    for(it=mymap.begin();it!=mymap.end();it++){
        cout<<it->first<<" --> ";
        for(int i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){


}
