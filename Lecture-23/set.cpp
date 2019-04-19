#include<iostream>
#include <unordered_set>
#include <cstring>
#include<map>
using namespace std;
int main(){
    map<string,int>mymap;
    mymap["abc"] = 10;
    mymap["reteg"] = 00;
    mymap["qwdve"] = 11;
    mymap["erbrb"] = 11;
    mymap["ponbje"] = 11;
    mymap["ed"] = 11;
    if(mymap.end()!=mymap.find("abrc")){
        cout<<"found"<<endl;
    }
    map<string,int> :: iterator it;
    for(it=mymap.begin();it!=mymap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
/*
unordered_set<int>myset;
myset.insert(10);
myset.insert(30);
myset.insert(50);
cout<< *myset.begin()<<endl;;
if(myset.end()!=myset.find(18)){
    cout<<"found"<<endl;
}
*/

}
