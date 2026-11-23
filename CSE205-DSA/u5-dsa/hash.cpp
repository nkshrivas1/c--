#include<iostream>
using namespace std;

void unorderedMap(){
    unordered_map<int,string> um = {{1,"A"},{2,"B"},{3,"C"}};
    um.insert({4,"ABC"});
    um[2]="xyz";
    for(auto i: um)
        cout<<i.first << ": "<<i.second<<endl;
}
//calculate frequency of given array

int main(){
    // unorderedMap();
    int arr[7] = {0,1,99,98,5,55,55};
    unordered_map<int,int> freq;
    for(int i=0;i<7;i++)
        freq[arr[i]]++;
    for(auto i: freq)
        cout<<i.first << ": "<<i.second<<endl;  
    return 0;
}