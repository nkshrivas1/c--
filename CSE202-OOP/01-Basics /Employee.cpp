// create a employee class with 
// id - incremental
// name,age ,dept,email
// constructor will initialize 
// value using initialiser list
#include<iostream>
using namespace std;

class Employee{
    public:
        static int id_c;
        int id;
        string name;
        int age;
        string dept;
        string email;
        
        Employee(string n,int a,string d,string e)
        :name(n),age(a),dept(d),email(e){
            id = ++id_c;
        }
        void displayEmployee( string greet="Welcome " ){
            cout << greet<< id << " | " << name << endl;
        }
// create a function to swap two values

};

void swap(int *a,int *b){
    int temp = *a;
   *a= *b;
   *b= temp;
}
void swapByRef(int &a, int &b){
    int temp = a;
   a= b;
   b= temp;
}
int Employee::id_c=0; 
int main(){
    int a =10;
    int b = 20;
    // we are calling these by value
    //call by address
    swap(&a,&b);
    // call by reference
    swapByRef(a,b);
    cout << "value of a: " << a << endl;
    cout << "value of b: " << b << endl;

    // Employee e1("e1",22,"it","abc@gmail.com");
    // Employee e2("e2",22,"it","abc@gmail.com");
    // Employee e3("e3",22,"it","abc@gmail.com");
    // e1.displayEmployee();
    // e2.displayEmployee(" welcome back! ");
    // e3.displayEmployee();
    // cout << " current counter " << Employee::id_c << endl;

}