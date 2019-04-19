#include<iostream>
#include<list>
using namespace std;
class graph{
    int v;
    list<int>* l;

public:
    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int src,int dest, bool bidir = false){
        l[src].push_back(dest);
        if(bidir){
            l[dest].push_back(src);
        }
    }
    void print(){
        for(int i=0;i<v;i++){
            list<int>:: iterator it;
            cout<<i<<"  --> ";
            for(it = l[i].begin();it!=l[i].end();it++){
                cout<<*it<<" , ";
            }
            cout<<endl;
        }
    }
};
int main(){
graph g(5);
g.addEdge(0,1,true);
g.addEdge(0,4,true);
g.addEdge(0,3);
g.addEdge(2,3);g.addEdge(2,4);
g.addEdge(3,4);
g.addEdge(4,2);
g.print();
}











