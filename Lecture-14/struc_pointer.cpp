#include<iostream>
using namespace std;
struct address{
    int house;
    char street[100];
    int pincode;

    address(int house,char street[],int pincode){
        this->house = house;
        this->pincode = pincode;
        int i;
        for(i=0;street[i];i++){
            this->street[i] = street[i];
        }
        this->street[i] ='\0';
    }
};

// no memory is allocated now
struct student{
    char name[100];
    int age;
    char gender;
    address* location;

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

void printStudent(student s){
    cout<<s.name<<endl;
    cout<<s.age<<endl;
    cout<<s.gender<<endl;
    cout<<(*(s.location)).house<<endl;
    cout<<(s.location)->house<<endl;
    cout<<(*(s.location)).street<<endl;
    cout<<(*(s.location)).pincode<<endl;
}
int main() {
    address adr(101,"abcdef",101010);
    student s("XYZ",15);
    s.location = &adr;
    printStudent(s);


    student* s = new student();
    (*s).age = 20;
    s->age = 20;


}


