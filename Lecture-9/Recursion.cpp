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
bool checkSeven(int arr[],int n,int i){
    if(i==n){
        return false;
    }
    if(arr[i]==7){
        return true;
    }
    bool right = checkSeven(arr,n,i+1);
    return right;
    /*if(right){
        true;
    }
    return false;*/
}
// returns first index of seven starting from i
int firstIndexOfSeven(int arr[],int n,int i){
    if(i==n){
        //array does not exits
        return -1;
    }
    if(arr[i] == 7){
        return i;
    }
    return firstIndexOfSeven(arr,n,i+1);
}
int lastIndexOfSeven(int arr[],int n,int i){
    if(i==n){
        return-1;
    }
    int right = lastIndexOfSeven(arr,n,i+1);
    if(right!=-1){
        return right;
    }
    if(arr[i]==7){
        return i;
    }
    return -1;
}
void allIndexOfSeven(int arr[],int n,int i){
    if(i==n){
        return;
    }
    if(arr[i]==7){
        cout<<i<<" ";
    }
    allIndexOfSeven(arr,n,i+1);
    return;
}
int multiply(int a,int b){
    if(a==0||b==0){
        return 0;
    }
    if(a==1){
        return b;
    }
    return multiply(a-1,b) + b;
}
void bubbleSort(int arr[],int n,int i){
    cout<<"A"<<endl;
    if(n==0 || n==1){
        return;
    }
    if(i==n-1){
        bubbleSort(arr,n-1,0);
       return;
    }
    if(arr[i]>arr[i+1]){
        //swap
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    bubbleSort(arr,n,i+1);
    return;
}
bool binarySearch(int arr[],int start,int end,int k){
    if(start>end){
        return false;
    }
    int mid = (start+end)/2;
    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]>k){
         return binarySearch(arr,start,mid-1,k);
    }else{
        return binarySearch(arr,mid+1,end,k);
    }
}
void tow(int n,char source,char destination,char helper){
    if(n==1){
        cout<<source<<"-->"<<destination<<endl;
        return;
    }
    tow(n-1,source,helper,destination);
    //tow(1,source,destination,helper);
    cout<<source<<"-->"<<destination<<endl;
    tow(n-1,helper,destination,source);
    return;
}

void permutate(int arr[],int n,int i){
    if(i==n-1){
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int j=i;j<n;j++){
        swap(arr[i],arr[j]);
        permutate(arr,n,i+1);
        swap(arr[i],arr[j]);
    }
    return;
}
int main(){
int arr[10] = {1,2,3,4};
permutate(arr,4,0);
//cout<<binarySearch(arr,0,2,3)<<endl;;
//tow(5,'A','C','B');
}









