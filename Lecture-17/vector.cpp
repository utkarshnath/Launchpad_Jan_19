#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> v;
/*
v.push_back(1);
v.push_back(2);
v.push_back(3);
*/
for(int i=0;i<4;i++){
    int x;
    cin>>x;
    v.push_back(x);
}
//v[1] = 4;
vector<int>:: iterator it;
for(it=v.begin();it!=v.end();it++){
    cout<<*it<<" ";
}

cout<<*(it+1)<<endl;
/*
cout<<v.size()<<endl;
//v.clear();
cout<<v.size()<<endl;
for(int i=0;i<3;i++){
    //cout<<v[i];
    cout<<v.at(i)<<" ";
}
cout<<endl;
*/
//cout<<v[2]<<endl;
}
