// given an array of integers , write a recursive soln to print 
// in reverse order

#include <iostream>
using namespace std;

void printReverseArray(int arr[],int n){
    if(n==0) return;
    cout<<arr[n-1]<<" ";
    printReverseArray(arr,n-1);
}

// print an array in the following order
// [0][n-1][1][n-2][2][n-3]...
//example: arr[] = {1,2,3,5,6} 
// output: 1 6 2 5 3

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

int removeOdds(int arr[],int n,int index){
    if(index >= n) return n;
    if(arr[index] % 2 != 0){
        for(int i = index; i < n - 1; i++){
            arr[i] = arr[i + 1];
        }
        return removeOdds(arr, n - 1, index);
    }
    return removeOdds(arr, n, index + 1);
}
//Write a recursive program to compute nth fibonacci number.
//  1st and 2nd fibonacci numbers are 1, 1.

int fibonacci(int n){
    if(n <= 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// write a recursive function to implement binary search,
// i.e. given an array of sorted integers
//example: arr[] = {1,2,3,4,5,6}

int binarySearch(int arr[], int key, int i, int j){
    if(i > j) return -1;
    int mid = i + (j - i) / 2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] > key) return binarySearch(arr, key, i, mid - 1);
    else return binarySearch(arr, key, mid + 1, j);
}

 void towerOfHanoi(int n, char source, char destination, char helper) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to "
         << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, helper, destination);
    cout << "Move disk " << n << " from " << source << " to "
     << destination << endl;
    towerOfHanoi(n - 1, helper, destination, source);
}

//cli

int main(){
    towerOfHanoi(1, 'S', 'D', 'H');
    return 0;
}