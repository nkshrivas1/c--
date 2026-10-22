#include<iostream>
using namespace std;

void printReverseArray(int arr[],int n){
    if(n==0) return;
    cout<<arr[n-1]<<" ";
    printReverseArray(arr,n-1);
}
//Q. write a recursive fun to print an array
// [0][n-1][1][n-2][2][n-3]...
//example: arr[] = {1,2,3,5,6} 
// output: 1 6 2, 5 ,3

void printArray(int arr[],int i,int j){
    if(i>j) return;
    cout<<arr[i]<<" ";
    if(i!=j) cout<<arr[j]<<" ";
    printArray(arr,i+1,j-1);
}

// write a recursive fun to remove all odd integers from an array
// do not use any extra space or print in the function
// example: arr[] = {1,2,3,4,5,6}
// output: arr[] = {2,4,6} n=3

// write a recursive fun to comopute nth fibonacci number
//series: 0,1,1,2,3,5,8,13,21,34
//example: n=5
// output: 5

int fibonacci(int n){
    if(n<=1) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

void removeOdd(int arr[],int &n,int i,int j){
    if(i>j) return;
    if(arr[i]%2!=0){
        arr[i] = arr[j];
        j--;
        n--;
        removeOdd(arr,n,i,j);
    }
    else{
        removeOdd(arr,n,i+1,j);
    }

}


// Implement binary search recursively, 
// i.e. given an array of sorted integers
//example: arr[] = {1,2,3,4,5,6} n=6 key=4
// output: 3 (index of key in the array)
int binarySearch(int arr[],int n,int key,int i,int j){
    if(i>j) return -1;
    int mid = i + (j-i)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]>key) return binarySearch(arr,n,key,i,mid-1);
    else return binarySearch(arr,n,key,mid+1,j);
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    removeOdd(arr,n,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}