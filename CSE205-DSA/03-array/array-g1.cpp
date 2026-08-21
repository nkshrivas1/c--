#include<iostream>
using namespace std;

int main()
{
  
    // int arr[5] = {2, 3, 4, 5,0};
    // int pos= 0;
    // int n = 4;
    // for(int i = n;i>pos;i--){
    //     arr[i] = arr[i-1];
    // }
    // arr[pos] =1;
    // n++;
    // int idx =1;
    // for(int i= idx; i < n-1;i++){
    //     arr[i] = arr[i+1];
    // }
    // n--;

    // search frequency of every element  in an array where value of
    //  element range b/w 0 to 100
    int num[10] = { 1,1,4,65,7,65,7,1,3,3};
    int freq[101] = {0};

    for(int i=0;i<10;i++){
        freq[num[i]]++;
    }
    for(int i=0;i<101;i++){
        if(freq[i]>0){
            cout << "freq of "<< i << " - " << freq[i] << endl;
        }
    }
    // find the missing number in an array which have no
    // from 1 to n
    int n =7;
    int arr[6]={1,5,7,6,4,2};
    int totalsum = n * (n+1)/2;
    for(int i =0;i<n-1;i++){
        totalsum -= arr[i];
    }
    cout << totalsum << endl;
   
    return 0;
}