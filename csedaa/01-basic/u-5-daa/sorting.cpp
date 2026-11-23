#include<iostream>
using namespace std;

vector<int> countsort(vector<int>& arr){
    int n= arr.size();
    // find maximum
    int maxx = 0;
    for(int i=0;i<n;i++) maxx = max(maxx,arr[i]);
    vector<int> count(maxx+1,0);
    for(int i=0;i<n;i++) count[arr[i]]++;
    for(int i=1;i<=maxx;i++) count[i] += count[i-1];
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        ans[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
}
vector<int> countsortr(int arr[],int n,int i){
    int output[n];
    int j,count[10] = {0};

    for(j=0;j<n;j++)
    count[(arr[j]/i)%10]++;
    for(j=1;j<10;j++)
        count[j]+=count[j-1];
    for(j=n-1;j>=0;j--){
        output[count[(arr[j]/i)%10]-1] = arr[j];
        count[(arr[j]/i)%10]--;
    }
    for(j=0;j<n;j++)
        arr[j] = output[j];
  
}
int getMax(int arr[],int n){
    int mx = arr[0];
    for( int i =1;i<n;i++){
        if(arr[i]>mx) mx = arr[i];
    }
    return mx;
}
void radixsort(int arr[],int n){
    int m = getMax(arr,n);

    for(int i=1; m/i>0;i*=10)
        countsortr(arr,n,i);
}
/*
    Bucket Sort 
    step 1- create an array of size 10.where each slot represents a bucket
    step 2-  insert elements into the buckets from the input array 
        based on their range
    step 3- Sorting individual bucket
    step 4-gather the elements from each bucket and put them back into the
    original array

*/
void insertionsort(vector<float>& bucket){
    for(int i=1;i<bucket.size();++i){
        float key = bucket[i];
        int j=i-1;
        while(j>=0 && bucket[j]>key){
            bucket[j+1] = bucket[j];
            j--;
        }
        bucket[j+1] = key;
    }
}
void bucketSort(float arr[],int n){
    vector<float> b[n];
    for(int i=0;i<n;i++){
        int bi =n*arr[i];
        b[bi].push_back(arr[i]);
    }
    for(int i =0;i<n;i++){
        insertionsort(b[i]);
    }
    int index =0;
    for(int i =0;i<n;i++){
        for(int j=0;j<b[i].size();j++){
            arr[index++] = b[i][j];
        }
    }
}
int main(){
    return 0;
}