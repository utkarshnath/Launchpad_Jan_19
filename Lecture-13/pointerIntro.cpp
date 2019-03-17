#include<iostream>
using namespace std;
int main(){
   /*
int x = 10;
cout<<&x<<endl;
int* ptr = &x;
cout<<x<<endl;
cout<<ptr<<endl;
cout<<&ptr<<endl;
int ** y = &ptr;
cout<<y<<endl;

char ch = 'A';
char * ptr = &ch;

char arr[10] = "ABC";
//cout<<arr<<endl;
cout<<(int*)ptr<<endl;
cout<<(void*)ptr<<endl;
cout<<(double*)ptr<<endl;
*/


cout<<sizeof(int*)<<endl;
cout<<sizeof(char*)<<endl;
cout<<sizeof(double*)<<endl;
bool y = 1;
bool * a = &y;
cout<<a<<endl;
cout<<a+1<<endl;

char ch = 'A';
int * cptr = (int*)&ch;
cout<<cptr<<endl;
cout<<&cptr<<endl;
cout<<cptr+1<<endl;

}




