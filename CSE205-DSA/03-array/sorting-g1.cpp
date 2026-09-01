#include<iostream>
using namespace std;
#include<algorithm>

// selection - > selct minimum
// Bubble ->. compare neighbours and 
// place the largest at last
//Insertion -> insert into sorted part
void bubble(int aarr[],int n){
// [9 , 8 ,7 ,6,2,5]
// [8,7,6,2,5,9]
// [7,6,2,5,8]
// write the logic to implement bubble sort
// for i=0 to n-2
        // isSwapped = 0;
//     for j = 0 to n-i-2
//         if(arr[j] > arr[j+1]) 
//             swap(arr[j],arr[j+1])
            // isSwapped = 1
    //  if(isSwapped ==0) return; // O(n) best case
    // find the 3rd largest element in an array
}
void selection(int arr[],int n){
for(int i =0; i< n-1;i++){
    int minidx = i;
    for (int j = i+1;j< n-1;j++){
        if( arr[j] < arr[minidx]) minidx = j;
    }
        int temp = arr[minidx];
        arr[minidx] = arr[i];
        arr[i]=temp;
}}

void insertion(int arr[],int n){
    /*
        for i =1 to n-1
            key = arr[i]
            j=i-1;
            while j>=0  and arr[j] > key 
                arr[j+1] = arr[j]
                j--
            arr[j+1] = key
    */
   for( int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while( j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
   }
}
// merge two arrays into one array
void mergetwo(int arr1[],int arr2[],int m, int n){
    int output[m+n];
  
    for(int i=0;i<m;i++){
        output[i] = arr1[i]; 
    }
    for(int i=0;i<n;i++){
        output[m+i] = arr2[i]; 
    }
}
//pass by reference
//const -- it will prevent modifying it
///when you only need to read a vector.
void printVector(const vector<int>& v){

}
//merge two sorted array in away output will also be sorted
// two pointer approach i -> arr1 and j -> arr2
// arr1= [5,7,9,10]
//arr2 = [3,6,8]
//output = 3,5,6,7,8,9,10
int mergeSorted(int arr1[],int arr2[],int m, int n){
    int i =0,j=0,k=0;
    int res[m+n];
    while(i<m && j<n){
        if(arr1[i]<arr2[j]) res[k++] = arr1[i++];
        else res[k++] = arr2[j++];
    }
    while(i<m) res[k++] = arr1[i++];
    while(j<n){
        res[k] = arr1[j];
        k++;
        j++; 
    }
}
//vector is a dynamic array which will automatically shrink or grow
//  whenever we remove or add any element
// contigous memory,allow access element using index
#include<vector>
int main(){
    int n=6;
    vector<int> v1;
    vector<int> v2 = {10,20,30,40};
    vector<int> v3(5,100);//{100,100,100,100,100}
    cout << v3[7] << endl;
    cout << v3.at(3) << endl;//exception check 
    //write a for loop to print all elements in vector
     
    // find the maximum in vector using range based for loop
    //range based for loop
    int maxi = v2[0];
    for(int x: v2){
        if(x > maxi)
            maxi = x;
    }
//  cout << maxi ;
 // important functions
 // insert element in vector
 v2.push_back(50); //insert at last
 // remove element at last
//  v2.pop_back();
 //number of elements
 v2.size();
 //to get the capacity
 v2.capacity();
 //check vector is empty or not
// cout <<  v2.empty();
//first element
v2.front();
// last eleement
v2.back();
//remove all eleement
// v2.clear();
// insert element at kth position in vector
// v2.insert(v.begin()+k,value)
// delete an element at position k=2
// v2.erase(v2.begin() +2);
// \\ erase a range of __element
 for(int i=0;i<v2.size();i++){
        cout << v2.at(i)<<", ";
    }
cout << endl;
v2.erase(v2.begin()+1,v2.begin()+3);
 
   for(int i=0;i<v2.size();i++){
        cout << v2.at(i)<<", ";
    }
// find target element 40 in v2 linear search
// find()
// #include<algorithm>
// auto it  = find(v2.begin(),v.end(),40)
// iterator 


//sorting
sort(v2.begin(),v2.end());
// how to pass a vector to a function

        // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }
    // selection(arr,n);
    return 0;
}