#include<iostream>
using namespace std;
int main(){
   /*
int * temp = NULL;
int * temp = 0;
cout<<*temp<<endl;
*/
int x = 5;
int * ptr = &x;
int **pptr = &ptr;
cout<<ptr<<endl;
cout<<*ptr<<endl;
cout<<&ptr<<endl;
cout<<pptr<<endl;
cout<<*pptr<<endl;
cout<<**pptr<<endl;


}
