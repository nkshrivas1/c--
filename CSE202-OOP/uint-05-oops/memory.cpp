
#include<iostream>
using namespace std;
// self referencing classes
class Node{
    public:
        int data;
        Node* next;
};
class Student{
    private:
        string name;
        int rollno;
        int* marks;
        // add marks array  which will be initialised  by constructor
    public:
        Student(string n,int r,int size) : name(n),rollno(r){
            marks = new int[size]{};
            cout << "Student object created"<<endl;
        }
        void display() const{
            cout << "Name: "<< name<< endl;
            cout << "Roll No: "<< rollno << endl;
        }
        Student(const Student& other){
            marks = new int(*other.marks);
            name = other.name;
            rollno = other.rollno;
        }
        ~Student(){
            delete[] marks;
            cout << "Student object destroyes";
        }
};
// create a shallow copy and deep copy of object student here
/*
    1. Early Binding (Static Binding)
        it occurs with:
            1. Non virtual member function
            2.Function overloading
            3. function templates
    2. Late Binding (Runtime)-
        it occurs with virtual functions called through base-class
        pointers or references 
    3. Virtual Destructor
    4.pure virtual function
        virtual return_type function(parameters)=0;
    5. Abstract class has at least one pure virtual function that has not been
     overridden in that class
     6. Concrete class implements all inherited pure virtual function 
     and can be instatiated
*/
class Animal{
    public:
       virtual void sound() =0;
        void display(){
            cout<<"Animal "<<endl;
        }
        virtual ~Animal(){
            cout<<"Animal destructor"<<endl;
        }
};
class Dog: public Animal{
    public:
        void sound(){
            cout << "Dog sound" << endl;
        }
        void sound(string name){
            cout << name <<" barks"<<endl;
        }
        void display(){
            cout<<"Dog "<<endl;
        }
        ~Dog() {
            cout << "Dog destructor "<<endl;
        }
};
class Appliance {
    public:
        virtual void turnon()=0;
        virtual void turnoff()=0;
        virtual ~Appliance()=default;
};
class Fan : public Appliance {
    public:
        void turnon() override{
            cout << "Fan is on" << endl;
        }
        void turnoff() override{
            cout << "Fan is off" << endl;
        }
};
int main(){
// Dog dog;
// Animal a;
Animal* ptr = new Dog();
delete ptr;
return 0;
// ptr->sound();
// ptr->display();






    // Student* s = new Student("Aman",101);
    // s->display();
    // delete s;
    // s= nullptr;
    /*
 
    int n;
    cin >> n;
    int* marks = new int[n]{};
    int sum =0;
    for(int i=0;i<n;i++){
        cout << "enter marks: "<<endl;
        cin >> marks[i];
        sum +=marks[i];
    }
    cout << "sum: " << sum;
    delete[] marks;
    marks=nullptr;
    
   
    */
    return 0;
    //object lifecycle
    // 1. memory allocate_shared
    // 2. constructor executes
    //3. the object is used
    //4.delete is called
    //5. destructor executes
    //6.object memory is released

    // int age = 20;
    // cout << age;

    // int * ptr = new int;
    // *ptr = 20;
    // cout << *ptr;
    // delete ptr;
}
// Types of polymorphism
/*
    1. compile time
        a. method overloading
        b. operator overloading
    2. runtime
        a. Method overriding
*/