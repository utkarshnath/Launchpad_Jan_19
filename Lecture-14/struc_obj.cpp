#include<iostream>
using namespace std;
// no memory is allocated now
struct student{
    char name[100];
    int age;
    char gender;

    student(){
        cout<<"I am default constructor"<<endl;
        name[0] = 'a';
        name[1] = 'b';
        name[2] = '\0';
    }
    student(char newname[]){
        cout<<"I am constructor 1"<<endl;
        int i;
        for(i=0;newname[i];i++){
            name[i] = newname[i];
        }
        name[i] ='\0';
    }
    student(char newname[],int age){
        this->age = age;
        cout<<"I am constructor 2"<<endl;
        int i;
        for(i=0;newname[i];i++){
            name[i] = newname[i];
        }
        name[i] ='\0';
    }
};
int main() {
    student s("ABCDEF");
    cout<<s.name<<endl;
    cout<<s.age<<endl;

    student s2("ABCDEF",15);
    cout<<s.name<<endl;
    cout<<s2.age<<endl;

    student s1[10];
    s.age = 10;
    s.gender = 'F';
    cin.getline(s.name,100);
    // cout<<sizeof(s)<<endl;

    cout<<s.name<<endl;
    cout<<s.age<<endl;
    cout<<s.gender<<endl;


}

