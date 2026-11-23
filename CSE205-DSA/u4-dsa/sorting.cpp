#include<iostream>
using namespace std;

/*
    qs(arr,low,high){
        if(low<high){
            partition = fn(arr,low,high);
            qs(arr,low,partition-1);
            qs(arr,partition+1,high)
        }
    }

*/
int partition(vector<int> &arr,int low,int high){
    int pivot = arr[low];
    int i =low;
    int j= high;
    while(i<j){
        while(arr[i]<= pivot && i <= high-1) i++;
        while(arr[j] > pivot && j>=low) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
   void qs(vector<int> &arr,int low,int high){
        if(low<high){
           int partIdx = partition(arr,low,high);
            qs(arr,low,partIdx-1);
            qs(arr,partIdx+1,high);
        }
    }
    // merge sort
    /*
        1.Divide- divide the list recursively into two halves
        2.Conquer- each subarray is sorted individually
        3.Merge:the sorted subarrays are merged back together in sorted order
    */
    void merge(vector<int> &arr,int left,int mid,int right){
        int n1= mid -left+1;
        int n2 = right -mid;
        vector<int> L(n1),R(n2);
        for(int i =0;i<n1;i++)
            L[i] = arr[left+i];
        for(int j =0;j<n2;j++)
            R[j] = arr[mid+1+j];
        
            int i =0,j=0,k=left;
            while(i<n1 && j<n2){
                if(L[i] <= R[j])  arr[k] = L[i++];
                else arr[k]=R[j++];
                k++;
            }
            while(i<n1) arr[k++]=L[i++];
            while(j<n2) arr[k++]=R[j++];

    }

    void mergeSort(vector<int> & arr,int left,int right){
        if(left>= right) return;
        int mid = left + (right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }

    int main(){
        vector<int> arr={4,7,3,6,5,1};
        qs(arr,0,5);
        for(int i=0;i<6;i++){
            cout<< arr[i] << " ";
        }
    }