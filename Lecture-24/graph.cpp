#include<iostream>
#include<list>
#include<queue>
#include<vector>
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
    void bfsDriver(int vertex,vector<bool>& visited){
        queue<int>q;
        q.push(vertex);
        visited[vertex] = 1;
        while(!q.empty()){
            int top = q.front();
            cout<<top;
            //list<int>:: iterator it;
            for(auto it = l[top].begin();it!=l[top].end();it++){
                int curr = *it;
                if(visited[curr]==false){
                    q.push(curr);
                    visited[curr] = true;
                }
            }
            q.pop();
        }
    }

    void bfs(){
        vector<bool> visited;
        for(int i=0;i<v;i++){
            visited.push_back(false);
        }
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                bfsDriver(i,visited);
            }
        }
    }
    void dfsDriver(int vertex, vector<bool>& visited){
        if(visited[vertex]){
            return;
        }
        cout<<vertex<<" ";
        visited[vertex] = true;
        for(auto it = l[vertex].begin();it!=l[vertex].end();it++){
            dfsDriver(*it,visited);
        }
    }

    void dfs(){
        vector<bool> visited;
        for(int i=0;i<v;i++){
            visited.push_back(false);
        }
        for(int i=0;i<v;i++){
            dfsDriver(i,visited);
        }
    }

    void print(){
        for(int i=0;i<v;i++){
            //list<int>:: iterator it;
            cout<<i<<"  --> ";
            for(auto it = l[i].begin();it!=l[i].end();it++){
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
cout<<endl;
//g.bfs();cout<<endl;
g.dfs();cout<<endl;
}











