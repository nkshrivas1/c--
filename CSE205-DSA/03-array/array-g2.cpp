#include<iostream>
using namespace std;
int missingNumber(int arr[], int n)
{
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
        total -= arr[i];
    return total;
}
int missingNumberXOR(int arr[],int size){
    int x1 = 0;
    int x2= 0;
    int n = size+1;
    for( int i =1;i <= n;i++){
        x1=x1^i;
    }
    for( int i= 0;i<size;i++){
        x2=x2^arr[i];
    }
    return (x1^x2);
}
 // Given a positive integer n,
    //  find its square root.
    //  If n is not a perfect square, 
    // then return floor of √n.
int binarySearchIterative( int arr[],int target,int n){
    int low =0;
    int high = 5;
    while(low<= high){
        int mid = low + (high- low)/2;
        if(arr[mid]== target)
            return mid;
        else if( arr[mid] < target)
             low = mid + 1;
        else high = mid -1;
    }
    return -1;
}
         // write a function to get the fibbonaci series 
        //  0,1,1,2,3,5,8...n
    void fun(int n){
        int t1 =0 , t2 = 1, nextTerm =0;
        // cout << t1 << " , " << t2 << " , ";
        for(int i=2;i<=n;i++){
            nextTerm = t1+t2;
            t1 = t2;
            t2 = nextTerm;

        }  
            cout << nextTerm << " , ";

    // space complexity O(logn)

    }
int search(int arr[], int n, int target) {
    int x =0;
    int y =10;
    int arr2[n][n];
    for(int i = 0; i < n; i++) {

        if(arr[i] == target)
            return i;
    }

    return -1;
}
// O(1)
// O(log n)
// O(n)
// O(n log n)
// O(n²)
// O(2ⁿ)
// O(n!)





int main()
{
     fun(5);
    //write a program to get the second largest element in array
    // int arr[5] = {1, 2, 3, 4, 5};
    // cout << "Array elements are: ";
    // for(int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // // count occurrence of an element in an array
    // // find the targetvalue of an element in an array
    // // delete an element from an array at given position
    // int arr[5] = {1, 3, 4, 5,6};
    // int pos= 2;
    // for(int i=pos;i<5-1;i++){
    //     arr[i] = arr[i+1];
    // }
    // int arr[5] = {2, 3, 4, 5,0};
    // int pos= 0;
    // int n = 4;
    // for(int i = n;i>pos;i--){
    //     arr[i] = arr[i-1];
    // }
    // arr[pos] =1;
    // n++;
   
    // int arr[5] = { 1,2,1,2,7};
    // int x =0;
    // for(int i=0;i<5;i++){
    //     x ^= arr[i];
    // }
    // // cout << x << endl;
    // // 2d array input from user
    // int arr2d[3][3];
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cin >> arr2d[i][j];
    //     }   
    // }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout << arr2d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // // get the sum of this 2 d array
    // int sum = 0;
    //  for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //        sum += arr2d[i][j];
    //     }
    // }
    // // binary search - O(logn) to find the target value into sorted array
    
    // // Given a positive integer n,
    // //  find its square root.
    // //  If n is not a perfect square, then return floor of √n.
    //     int i =1;
    //     while(i*i <= 11){
    //         i++;
    //     }
    //     cout << i-1 << endl;
    //     int n =30;
    //     int lo =1,hi = n;
    //     int res=1;
    //     while(lo <= hi){
    //         int mid = lo +(hi-lo)/2;
    //         if(mid*mid <=n){
    //             res = mid;
    //             lo = mid+1;
    //         }
    //         else hi = mid -1;
    //     }
    //     cout << res <<endl;

// 
    // cout << sum;
    return 0;
}