#include<iostream>
using namespace std;
void insertion(int arr[],int n){
        for (int i =1; i< n;i++){
            int key = arr[i];
            int j =i -1;
            while (j>= 0 and arr[j] > key){
                arr[j+1]  = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
        // worst - O(n^2)
        // best - O(n)
        // pick the key
        //define j
        // compare till arr[j] > key
        // shift the elements
        // place the key

}

void bubble(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                swapped = true;
            };
        }
        if(!swapped) break;
    }
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    // find the minimum element after 3rd pass of selection sort
}
void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minidx = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minidx]) minidx =j;
        }
        int temp = arr[minidx];
        arr[minidx] = arr[i];
        arr[i] = temp;
        if(i==2){
            cout<< arr[i];
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    // find the minimum element after 3rd pass of selection sort
}
int main(){
    int n=6;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    selection(arr,n);
    return 0;
}