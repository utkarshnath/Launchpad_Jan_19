#include<iostream>
#include <cstring>
using namespace std;
template<typename T>
struct node{
    string key;
    T value;
    node * next;

    node(string key,T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~node(){
        // I am destructor
        if(next!=NULL){
            delete next;
        }
    }
};
template<typename T>
class hashtable{
    node<T>** table;
    int tableSize;
    int currentSize;

    int hash(string key){
        int index = 0;
        int l =key.size();
        int power=1;
        for(int i=0;i<key.size();i++){
            index += key[l-i-1]*power;
            power*=37;
            index%=tableSize;
            power%=tableSize;
        }
        return index;
    }
    void rehash(){
        node<T> ** oldTable = table;
        int oldTableSize = tableSize;
        tableSize*=2;
        currentSize = 0;
        table = new node<T>*[tableSize];
        for(int i=0;i<tableSize;i++){
            table[i] = 0;
        }
        for(int i=0;i<oldTableSize;i++){
            node<T>* head = oldTable[i];
            while(head){
                insert(head->key,head->value);
                head = head->next;
            }
            delete oldTable[i];
        }
        delete []oldTable;
    }
public:
    hashtable(int size=7){
        tableSize = size;
        currentSize = 0;
        table = new node<T>*[size];
        for(int i=0;i<size;i++){
            table[i] = 0;
        }
    }

    void insert(string key,T value){
        int index  = hash(key);
        node<T> * temp = new node<T>(key,value);
        node<T>* head = table[index];
        temp->next = head;
        table[index] = temp;
        currentSize++;
        float loadFactor = 0.8;
        if(currentSize/(tableSize*1.0) > loadFactor){
            rehash();
        }
        return;
    }

    node<T>* find(string key){
        int index  = hash(key);
        return table[index];
    }

    void erase(string key, T value){
        int index = hash(key);
        node <T> * prev = NULL;
        node <T> * head = table[index];
        while(head){
            if(head->key==key && head->value==value){
                currentSize--;
                if(prev==NULL){
                    node<T>* temp = head;
                    table[index] = head->next;
                    temp->next = NULL;
                    delete temp;
                    return;
                }
                node<T>* temp = head;
                prev->next = head->next;
                temp->next = NULL;
                delete temp;
                return;
            }
            prev = head;
            head = head->next;
        }
    }

    void print(){
        for(int i=0;i<tableSize;i++){
            node<T> * head = table[i];
            while(head){
                cout<<head->key<<" , "<<head->value<<" -->> ";
                head = head->next;
            }
            cout<<"NULL"<<endl;;
        }
        cout<<"*******************************"<<endl;
    }
};
int main(){
    hashtable<int>h;
    h.insert("Mango",100);
    h.insert("wefwer",200);
    h.insert("Apple",20);
    h.insert("uwer",20);
    h.insert("refergre",20);
    h.print();
    h.erase("wwer",100);
    h.insert("guaewrfeva",30);
    h.insert("qfe",100);
    h.print();
}














