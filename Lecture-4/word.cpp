#include<iostream>
using namespace std;
int main(){
    char c;
    c = cin.get();
    int cCount = 0;
    int lCount = 0;
    int wCount = 0;
    int curr_word_length = 0;
    while(c!='$'){
         if(c==' ' || c=='\t'){
            if(curr_word_length>0){
                wCount++;
                curr_word_length = 0;
            }
         }
        else if(c=='\n'){
            if(curr_word_length>0){
                wCount++;
                curr_word_length = 0;
            }
            lCount++;
        }else{
            curr_word_length++;
        }
        cCount++;
        c = cin.get();
    }
    lCount++;
    if(curr_word_length>0){
        wCount++;
        curr_word_length = 0;
    }
    cout<<"CHar "<<cCount<<endl;
    cout<<"Word "<<wCount<<endl;
    cout<<"Line "<<lCount<<endl;
}
