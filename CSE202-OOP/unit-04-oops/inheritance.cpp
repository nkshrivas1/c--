

// inheritence - mechanism of oops where new class acquires
// accessible members and behaviours from an existing class.
// the existing class is called the base class or parent class.
// The new class is called the derived class or child class
// Person: name , age,display details
// Student : registration number, course details
// Teacher : employye ID , subject details
// syntax of inheritance
// class DerivedClass : public BaseClass{
    //Additional members
// }
#include<iostream>
using namespace std;
 class Person{
    public: 
    string name;
 };
 class Student: public Person{
    public:
        int rollno;
 };
 int main(){
    Student st;
    st.name = "Nikhil";
 };
 class Student: public Person{
    public:
        int rollno;
 };
 int main(){
    Student st;
    st.name = "Nikhil";
 }
 }