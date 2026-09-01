
#include<iostream>
using namespace std;
// print n elements using recursion
// 1 - define base case
// 2 -  define recursive case
//3 - ensure the recursion terminates
// 4 - combine the soln



// 2 -find the sum of n natural number 
// using recursion
int fun(int n){
    if(n==1) return 1;
   return n + fun(n-1);
}
//  void combination(int arr[], int data[],int start,int end,int index,int r){
//         if ( index == r){
//             for( int i =0;i<r;i++){
//                 cout << data[i] << " ";
//             }
//             cout << endl;
//             return;
//         }
//         for( int i =start; i<= end && )
//  }
// find gcd of a number
// greatest common divisor
// a =12 b =20
// divide 20 by 12 = 8
//divide 12 by 8 = 4
// divide 8 by 4 = 0
int GCD(int a,int b){
    if( a==0) return b;
    return GCD(b%a,a);
}
    // find factorial of a number using recursion\
// n* fact(n-1)
//find all combination of size r from an array
// r =2 arr=. [1,2,3,4]
// [1,2],[1,3],[1,4],[2,3],[2,4],[3,4]
int main()
{
    /* code */
    return 0;
}
