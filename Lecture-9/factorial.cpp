#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    int fact = factorial(n-1);
    return fact*n;
}
// it returns nth fibo number
int fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        cout<<"*"<<endl;
        return 1;
    }
    int a = fibo(n-1);
    int b  = fibo(n-2);
    int c = a+b;
    return c;
}
//checks whether array is sorted or not starting from index
bool checkSorted(int arr[100],int n,int index){
    if(index==n-1){
        return true;
    }
    bool right = checkSorted(arr,n,index+1);
    if(arr[index]<=arr[index+1] && right){
        return true;
    }
    return false;
}

//returns sum starting from i
int sumArray(int arr[10],int n,int i){
    if(n-1==i){
        return arr[i];
    }
    int right = sumArray(arr,n,i+1);
    int curr = arr[i];
    return right+curr;
}
void printInInc(int n){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    printInInc(n-1);
    cout<<n<<endl;
    return;
}

void printDec(int n){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    cout<<n<<endl;
    printDec(n-1);
    return;
}
void selectionSort(int arr[100],int n,int i){
    if(i==n-1){
        return;
    }
    int min = INT_MAX;
    int minIndex = i;
    for(int j=i;j<n;j++){
        if(arr[j]<min){
            min = arr[j];
            minIndex = j;
        }
    }
    int temp = arr[i];
    arr[i] = min;
    arr[minIndex] = temp;
     selectionSort(arr,n,i+1);
     return;
}
int power(int n,int m){
    if(m==0){
        return 1;
    }
    return power(n,m-1)*n;
}
void printNUmDigit(int n){
switch(n){
    case 0:
        cout<<"zero"<<endl;
        break;
    case 1:
        cout<<"one"<<endl;
        break;
    case 2:
        cout<<"two"<<endl;
        break;
    case 3:
        cout<<"three"<<endl;
        break;
    default:
        cout<<"does not exits"<<endl;
        break;
}
return;
}

void intToALpha(int n){
    if(n/10<1){
        printNUmDigit(n);
        return;
    }
    intToALpha(n/10);
    printNUmDigit(n%10);
    return;
}

int main(){
intToALpha(123);

}









