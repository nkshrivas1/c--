#include<iostream>
using namespace std;

// int maximum(int a,int b){
//     return (a>b)?a:b;
// }
// float maximum(float a,float b){
//     return (a>b)?a:b;
// }
// double maximum(double a,double b){
//     return (a>b)?a:b;
// }

// Generic Programming - Function Template
/*
Template is a feature in C++ that allows you to write generic 
and reusable code. It enables you to define functions and 
classes that can work with different data types without having to
write separate code for each type. 
*/
template <typename T>
T maximum(T a,T b){
    return (a>b)?a:b;
}
template <typename T1,typename T2>
auto add(T1 a,T2 b){
    return a+b;
}

template <typename T1,typename T2>
void display(T1 a,T2 b){
    cout << a << " " << b << endl;
}

template <typename T1,typename T2>
struct Pair {
    public:
    T1 first;
    T2 second;
    Pair(T1 a,T2 b){
        first = a;
        second = b;
    }
    void display(){
        cout << first << " " << second << endl;
    }
};

int main(){
    cout << "addition of 10 and 20.5 is: " << add(10,20) << endl;
    // cout << maximum(10,20) << endl;
    // cout << maximum(10.5f,20.5f) << endl;
    // cout << maximum(10.5,20.5) << endl;
    // cout << maximum('A','B') << endl;
    // display(10,20);
    // display(10.5f,20.5f);
    // display(10.5,20 );
    // display('A',9);
    // Pair<int,float> p1(10,20.5f);
    // p1.display();
    // Pair<char,string> p2('A',"Hello");
    // p2.display();
    return 0;
}