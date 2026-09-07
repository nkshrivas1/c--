#include<iostream>
using namespace std;
class A{
    int *p;
    public:
        A(){
            p = new int(10);
            cout <<*p<<endl;
        }
        ~A(){
            delete p;
        }
        
};
int main(){
    // int x = 10; 
    // int *p = &x;
    // int *q = p;
    // *q = 50;
    // cout << x << " " << *p << " " << *q;
    // //output - 50,50,50
    // int arr[] = {10,20,30,40,50};
    // int *ap = arr;
    // cout << *ap <<endl;
    // cout << *(ap+2)<<endl;
    // ap++;
    // cout<<*ap<<endl;
    // int a = 10;
    // int b = 20;
    // int *p = &a;
    // *p = b;
    // cout << a << " " << b;
    // int arr[] = {10,20,30,40,50};
    // int *ap = arr;
    // cout << *ap+2 << endl;
    // cout <<*(ap+2);
    // int x = 10;
    // int *p = &x;
    // int **q = &p;
    // cout <<q << " - "<<*q<<" - "<<**q;

    A a;
    return 0;
}