#include<iostream>
using namespace std;

// What is sorting?
// 5 , 2, 4, 1, 3
// 5
// 2 , 5
// 2, 4,5
// 1,2,4,5
//1,2, 3,4,5
// insertion sort - we  builds the sorted portion of an array
// one element at a time by inserting each 
//new element into its proper place within the sorted portion.
 void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
// create a functon to merge two sorted array
void merge(int arr1[], int arr2[], int n1, int n2
    , int merged[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

// find sum of array elements using recursion
int sum(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + sum(arr, n - 1);
}

// find the occurrence of an element in an array
int countOccurrences(int arr[], int n, int x) {
    if (n <= 0) {
        return 0;
    }
    int currentMatch = (arr[n - 1] == x) ? 1 : 0;
    return currentMatch + countOccurrences(arr, n - 1, x);
}

// write a method to find a power a^b
int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * power(a, b - 1);
}

int main(){
    int num[5]= {4,7,3,4,5};
    insertionSort(num,5);
    for(int i:num){
        cout << i << ", ";
    }
    return 0;
}