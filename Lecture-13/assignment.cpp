#include<iostream>
using namespace std;
int main(){
int x = 10;
int * xptr = &x;
int * yptr = xptr;
cout<<xptr<<endl;
cout<<yptr<<endl;
*yptr = (*yptr)+1;
//x = x+1;
cout<<x<<endl;

}
