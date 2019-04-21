#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class graph{
    int v;
    unordered_map<int, list<pair<int,int> > > m;

public:
    graph(int v){
        this->v = v;
    }

    void addEdge(int src,int dest, int weight,bool bdir=true){
        pair<int,int>p(dest,weight);
        m[src].push_back(p);
        if(bdir){
            m[dest].push_back(make_pair(src,weight));
        }
        return;
    }

    void print(){
        for(auto mapit = m.begin();mapit!=m.end();mapit++){
            cout<< mapit->first <<" -->> ";
            auto currList = (mapit->second);
            for(auto it = currList.begin();it!=currList.end();it++){
                cout<<it->first<<" "<<it->second<<" , ";
            }
            cout<<"END"<<endl;
        }
    }

    void shortestpath(int src){
        vector<int>dist;
        for(int i=0;i<v;i++){
            dist.push_back(INT_MAX);
        }

        dist[src] = 0;

        set<pair<int,int> >s;
        // weight, node

        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto minPair = s.begin();
            int node  = minPair->second;
            int nodeDist = minPair->first;

            s.erase(minPair);

            auto mapit = m.find(node);
            auto listIt = (mapit->second).begin();
            for(listIt;listIt != (mapit->second).end();listIt++){
                int parentDist = dist[node];
                int weight = listIt->second;
                if(dist[listIt->first] > parentDist+ weight){
                    int curr = listIt->first;
                    auto f = s.find(make_pair(dist[curr],curr));
                    if(f!=s.end()){
                        s.erase(make_pair(dist[curr],curr));
                    }
                    s.insert(make_pair(parentDist+weight,curr));
                    dist[curr] = parentDist+weight;
                }
            }
        }

        for(int i=0;i<dist.size();i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    graph g(9);
    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);
    g.addEdge(2,3,7);
    g.addEdge(2,8,2);
    g.addEdge(2,5,4);
    g.addEdge(3,4,9);
    g.addEdge(3,5,14);
    g.addEdge(4,5,10);
    g.addEdge(5,6,2);
    g.addEdge(6,7,1);
    g.addEdge(6,8,6);
    g.addEdge(7,8,7);
    g.shortestpath(0);
    cout<<endl;
}









