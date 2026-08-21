#include<iostream>
using namespace std;

int sum(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
cout << "The sum of the array is: " << sum(a,n) << endl;
    return 0;
}