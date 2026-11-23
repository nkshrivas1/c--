#include <iostream>
#include<map>
using namespace std;
template <typename T>
class heap{
    public:
        T arr[100];
        int size;
    heap(){
        arr[0]=T();
        size=0;
    }
    void insert(T val){
        size+=1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else return;
        }
    }
    void deleteFromHeap(){
        if(size ==0) return;
        arr[1]=arr[size];
        size--;
        int i=1;
        heapify(size,i);
        // while(i<size){
        //     int largest =i;
        //     int leftIndex = 2*i;
        //     int rightIndex = 2*i+1;
        //     if(leftIndex<=size && arr[largest]<arr[leftIndex]){
        //         largest=leftIndex;
        //     }
        //     if(rightIndex<=size && arr[largest]<arr[rightIndex]){
        //         largest=rightIndex;
        //     }
        //     if(largest == i) break;
        //     swap(arr[i],arr[largest]);
        //     i=largest;
        // }
    }
    void heapify(int n,int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;
        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest != i){
            swap(arr[i],arr[largest]);
            heapify(n,largest);
        }
    }
    void heapSort(){
        int n = size;
        for(int i=n/2;i>=1;i--){
            // this will rebalance each node
            heapify(n,i);
        }
        for( int i =n;i>1;i--){
            swap(arr[i],arr[1]);
            heapify(i-1,1);
        }
    }
    void printHeap(){
        for(int i =1;i<=size;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    map<int,int> m1;
    map<int,string> m2 = {{1,"A"},{2,"B"},{3,"C"}};
    // Iteration of map
    for(auto& it: m2){
        cout<<it.first<< " -> "<< it.second<<endl;
    }
    //inserting element in map
    m1.insert({1,99});
    heap<int> h;
    h.insert(8);
    h.insert(9);        
    // heap h;
    // h.insert(8);
    // h.insert(9);
    // h.insert(5);
    // h.insert(3);
    // h.insert(11);
    // h.insert(10);
    // // h.printHeap();
    // // h.deleteFromHeap();
    // int n=5;
    // h.printHeap();
    // h.heapSort();
    // cout<< "Sorted array: ";
    // h.printHeap();

    // for( int i =n/2;i>=0;i--){
    //     h.heapify(i);
    // }





    return 0;
}
/*
    Hashing-is a technique in ds that efficiently stores and retrieves 
    data in a way that allow for quick access
    1. it involves mapping data to a specific index in a hash table
        using hash function
    2. we can achieve search delete and insert at average O(1)
    3. Hashing is mainly used to implement a set of distinct items 
        (only keys) and dictionaries (key value pairs)
*/
#include<iostream>
#include<vector>
class HashTableChaining {
int buckets;
vector<vector<int>> table;
int hashFunction(int key) { return key % buckets; }
public:
    HashTableChaining(int size) : buckets(size), table(size) {}
    void insert(int key) {
        int idx = hashFunction(key);
        table[idx].push_back(key);
    }
};

