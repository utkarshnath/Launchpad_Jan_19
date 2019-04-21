#include<iostream>
using namespace std;
int lcs(string a,string b){
    int m = a.length();
    int n = b.length();
    int table[m+1][n+1];

    for(int i=0;i<=m;i++){
        table[i][0] = 0;
    }
    for(int i=0;i<=n;i++){
        table[0][i] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                table[i][j] = table[i-1][j-1]+1;
            }else{
                table[i][j] = max(table[i-1][j],table[i][j-1]);
            }
        }
        return table[m][n];
    }

}
int main(){

}
