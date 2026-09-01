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
void merge(int arr1[],int arr2[],int n,int m){
    int i=0,j=0,k=0;
    int output[n+m];

// arr1 = {3,7,9,12}
int arr[5];

// arr2 = {1,8,11,13,15,17}
    while(i<n && j<m){
        if(arr1[i]<arr2[j]) {
            output[k] = arr1[i];
            k++;
            i++;
        }
        else output[k++] = arr2[j++];
    }
    while(i<n) output[k++]=arr1[i++];
    while(j<m) output[k++]=arr2[j++];

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
#include<vector>
//vector- is a dynamic array,which dynamically resizes
// whenever we add or remove element
// stl

int main(){
    // vector<int> v(5,10);
    vector<int> v={10,20,40,50};
    // cout << v[5] <<endl;
    cout<< v.capacity()<<" size "<< v.size();//size
      v.push_back(80);
    v.push_back(90);
    cout<< v.capacity()<<" size2 "<< v.size();//size
    //insert 30 in vector v 2 position
    v.insert(v.begin()+2,30);
    //remove an element at given index
    v.erase(v.begin()+2);
    // erase element from range of 2 to 4
    v.erase(v.begin()+2,v.begin()+4);
    // find target 40 in v
    auto it = find(v.begin(),v.end(),40);
    if(it != v.end()){
        cout << "found";
    }
    //print all elemnts of v
    // for(int i=0;i<v.size();i++){
    //     cout << v[i] <<endl;
    // }
    int sum =0;
    // for( int x : v){
    //     sum+=x;
    //     cout << x << " ";
    // }
    //find the sum of all element in v
    // add more element inside our vector
  
  
    // remove last 
    v.pop_back();
//    for( int x : v){
//         cout << x << " ";
//     }
// push_back(x)
// Add at end
// pop_back()
// Remove last
// size()
// Number of elements
//capacity()
//
// empty()
// Check whether vector is empty
// front()
// First element
// back()
// Last element
// clear()
// Remove all elements











    // int n=6;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }
    // selection(arr,n);
    return 0;
}

// arr1 = {3,7,9,12}

// arr2 = {1,8,11,13,15,17}

// o/p sorted array- {1,3,7,8,9,11,12,13,15,17}