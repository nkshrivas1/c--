

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
 /*
 Benifits of inheritance
    1. Code reusability
    2. Maintainability
    3. Extensibility
    4. Logical organization
 */
#include<iostream>

// Hiererichal inheritance
using namespace std;
//  class Person{
    
//     protected:
//         int age;
//     private:
//         int password;
//     public: 
//         string name;
//            void displayPerson() const{
//             cout << "Name: "<< name<<endl;
//          }
//          Person(string n):name(n){
//             cout<< "Person constructor called"<< endl;
//          }
        
//  };
//  class Student: protected Person{
//     public:
//         int rollno;
//     Student(string n,int r):Person(n),rollno(r){
//         cout << "Student constructor called"<<endl;
//     }
//     void displayStudent() const{
//         displayPerson();
//         cout << "Roll no: "<< rollno << endl;
//     }
//  };
//  class Teacher : protected Person{
//     private:
//         string subject;
//     public:
//         Teacher(string n,string s):Person(n),subject(s){
//         }
//         void displayTeacher() {
//             displayPerson();
//             cout<< "Subject "<< subject << endl;
//         }
//  };
//  class Animal{
//     public:
//         void eat(){
//             cout << "Animal is eating"<< endl;
//         }
//         virtual void sound(){
//             cout << "Animal sound"<< endl;
//         }
//  };
//  class Dog : public Animal{
//     public:
//         void sound(){
//             cout << "Dog is barking"<< endl;
//         }
//  };
//  class Shape {
//     public:
//         virtual void draw() {
//             cout << "Drawing a generic shape" << endl;
//         }
// };
// class Circle : public Shape {
// public:
//     void draw() override {
//         cout << "Drawing a circle" << endl;
//     }
// };
// class Rectangle : public Shape {
// public:
//     void draw() override {
//         cout << "Drawing a rectangle" << endl;
//     }
// };
// void displayShape(Shape& shape) {
//     shape.draw();
// }

//  int main(){
//         Circle c;
//     Rectangle r;
//     displayShape(c);
//     displayShape(r);

//     // Animal* a;
//     // Dog d;
//     // a=&d;
//     // a->sound();
//     // d.Animal::sound();
// //     Person p("Rahul");
// //     Student st("Nikhil",1);
// //     // st.name;
// //     // st.age;
// //     st.displayStudent();
// //     // st.displayPerson();
// //    p.displayPerson(); 
//  }
 /*
 Develop a simple university system with the following requirements:
Base class: Person
Data members:
name
age
Member function:
displayPerson()
Derived class: Student
Additional data members:
registrationNumber
course
Member function:
displayStudent()
Tasks
Create the Person class.
Create Student using public inheritance.
Initialize the members.
Display all information.
Explain which members are inherited and which belong only to Student.
Sample output
Name: Rahul
Age: 21
Registration Number: 202601
Course: B.Tech IT

*/

/*
TYPES OF INHERITANCE:
1. SINGLE INHERITANCE
2. MULTILEVEL INHERITANCE- occurs when a class is derived from another derived class
3. MULTIPLE INHERITANCE-occurs when one derived class inherits 
    from two or mor base classes
4. HIERARCHICAL INHERITANCE
*/
 

 //multiple inmheritance
 class Camera{
    public:
        void takePhoto(){
            cout << "Photo captured "<< endl;
        }
 };
 class Phone{
    public:
        void makeCall(){
            cout << "Calling someone "<< endl;
        }
 };
  class SmartPhone: public Camera,public Phone{
    public:
        void browseInternet(){
            cout << "Browsing the internet"<< endl;
        }
 };
// to rmove ambiguity
//  s.Camera::takePhoto();
/*
Modes of inheritenc 
1. Public mode
=> A student should be able to use the public functionality provided by
 Person, such as displaying a name, while the derived class can access
  protected data where appropriate.
2. Protected inheritance makes the base class's public and protected members protected within the derived class.
Base public members become protected.
Base protected members remain protected.
Base private members are not directly accessible in derived-class code.
Diagram
Base Class
   |
   | protected inheritance
   v
Derived Class

Base public    -> Derived protected
Base protected -> Derived protected
Base private   -> Not directly accessible

Function overridibng-
occurs when a derived class provides its own implementation of an inherited virtual member
function with a matching signature
A virtual function is a member function declared with the virtual keyword in a base class.
 When called through a base-class pointer or reference, 
 C++ can select the final overrider according to the actual object type at runtime.

*/


// class Person {
// public:
//     Person() {
//         cout << "Person constructor\n";
//     }
//     ~Person() {
//         cout << "Person destructor\n";
//     }
// };
// class Student : public Person {
// public:
//     Student() {
//         cout << "Student constructor\n";
//     }
//     ~Student() {
//         cout << "Student destructor\n";
//     }
// };

// int main() {
//     Student s;
//     return 0;
// }

// class Person {
// public:
//     Person() {
//         cout << "Person constructor\n";
//     }
//     ~Person() {
//         cout << "Person destructor\n";
//     }
// };
// class Employee : public Person {
// public:
//     Employee() {
//         cout << "Employee constructor\n";
//     }
//     ~Employee() {
//         cout << "Employee destructor\n";
//     }
// };
// class Manager : public Employee {
// public:
//     Manager() {
//         cout << "Manager constructor\n";
//     }
//     ~Manager() {
//         cout << "Manager destructor\n";
//     }
// };
// int main() {
//     Manager m;
// }
// class Person {
// protected:
//     string name;
// public:
//     Person(string n) {
//         name = n;
//         cout << "Person constructor: " << name << '\n';
//     }
// };
// class Student : public Person {
// private:
//     int rollNo;
// public:
//     Student(string n, int r) : Person(n), rollNo(r) {
//         cout << "Student constructor: " << rollNo << '\n';
//     }
// };
// int main() {
//     Student s("Aman", 101);
// }
// class Demo {
// private:
//     int first;
//     int second;
// public:
//     Demo() : second(20), first(10) {
//         cout << "Constructor body\n";
//     }
//     void display() {
//         cout << "first = " << first << '\n';
//         cout << "second = " << second << '\n';
//     }
// };
// int main() {
//     Demo d;
//     d.display();
// }
// class Person {
// public:
//     Person() {
//         cout << "Person constructor\n";
//     }
//     ~Person() {
//         cout << "Person destructor\n";
//     }
// };
// class Student : virtual public Person {
// public:
//     Student() {
//         cout << "Student constructor\n";
//     }
//     ~Student() {
//         cout << "Student destructor\n";
//     }
// };
// class Employee : virtual public Person {
// public:
//     Employee() {
//         cout << "Employee constructor\n";
//     }
//     ~Employee() {
//         cout << "Employee destructor\n";
//     }
// };
// class TeachingAssistant : public Student, public Employee {
// public:
//     TeachingAssistant() {
//         cout << "TeachingAssistant constructor\n";
//     }
//     ~TeachingAssistant() {
//         cout << "TeachingAssistant destructor\n";
//     }
// };
// int main() {
//     TeachingAssistant ta;
// }
class Person {
public:
    int id;
    Person() {
        id = 100;
        cout << "Person constructor\n";
    }
};
class Student : virtual public Person {
};
class Employee : virtual public Person {
};
class TeachingAssistant : public Student, public Employee {
};
int main() {
    TeachingAssistant ta;

    // cout << ta.id;  // Ambiguous

    cout << ta.Student::id << '\n';
    cout << ta.Employee::id << '\n';

    return 0;
}
