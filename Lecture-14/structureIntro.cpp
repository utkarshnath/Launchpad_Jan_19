#include<iostream>
using namespace std;
// no memory is allocated now
struct student{
    char name[100];
    int age;
    char gender;
};
int main() {
    student s[3];
    for(int i=0;i<3;i++){
        s[i].age = i;
        s[i].gender = 'F';
        cin.getline(s[i].name,100);
    }
    for(int i=0;i<3;i++){
        cout<<s[i].name<<endl;
        cout<<s[i].age<<endl;
        cout<<s[i].gender<<endl;
    }
    /*
    s.age = 10;
    s.gender = 'F';
    cin.getline(s.name,100);
    // cout<<sizeof(s)<<endl;

    cout<<s.name<<endl;
    cout<<s.age<<endl;
    cout<<s.gender<<endl;

*/
}
