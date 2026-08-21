#include<iostream>
using namespace std;
int findSecondLargest(int arr[], int n)
{
     if(n<2) return -1;
    int first = arr[0];
    int second = arr[1];
   if(second>first){
    int temp = first;
    first = second;
    second = temp;
   }
   for( int i=2; i< n;i++){
    if(arr[i] > first){
        second = first;
        first  = arr[i];
    }
    else if( arr[i] > second && arr[i] != first){
        second =  arr[i];
    }
    else if(first == second && arr[i] < first){
        second = arr[i];
    }
   }
   return (first == second) ? -1 : second;
}
int main()
{
    //write a program to get the second largest element in array
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array elements are: ";
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    int arr[5] = {1, 3, 4, 5,0};
    int pos= 2;
    for(int i = 4;i>pos;i--){
        arr[i] = arr[i-1];
    }
    //deletion
    arr[pos] = 2;
    for(int i= pos ; i< 5-1;i++){
        arr[i] = arr[i+1];
    }
    // find the index of target element in an
    cout << endl;
    return 0;
}