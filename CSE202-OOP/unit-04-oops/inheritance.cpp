/**
 * ==============================================================================================
 *                         CSE202: OBJECT-ORIENTED PROGRAMMING IN C++
 *                          UNIT 4: INHERITANCE FUNDAMENTALS
 * ==============================================================================================
 * 
 * TOPICS COVERED:
 * ----------------
 * 1. Introduction to Inheritance (Concept, Need & Real-World Analogy)
 * 2. Terminology: Base Class (Parent) vs. Derived Class (Child)
 * 3. General Syntax of Inheritance in C++
 * 4. Visibility Modes in Inheritance (Focus on 'public' Inheritance)
 * 5. Practical Implementation:
 *    - Base Class: Person (name, age, display details)
 *    - Derived Class 1: Student (roll number, course details, display)
 *    - Derived Class 2: Teacher (employee ID, subject details, display)
 * 6. Demonstration in main()
 * 
 * ==============================================================================================
 * THEORY & EXAM NOTES: INHERITANCE FUNDAMENTALS
 * ==============================================================================================
 * 
 * 1. WHAT IS INHERITANCE?
 *    - Inheritance is a core pillar of Object-Oriented Programming (OOP) that allows a new 
 *      class (Derived Class) to acquire accessible data members and member functions from an 
 *      existing class (Base Class).
 *    - Represents an "IS-A" relationship:
 *        * A Student IS-A Person.
 *        * A Teacher IS-A Person.
 *    - Core Advantages:
 *        a) Code Reusability: Common attributes/behaviors are written once in the Base class 
 *           and reused across all Derived classes.
 *        b) Extensibility: New functionality can be added without modifying tested base code.
 *        c) Modularity & Readability: Organizes software into clean logical hierarchies.
 * 
 * 2. TERMINOLOGY:
 *    - Base Class (Parent / Super Class): The existing class whose members are inherited.
 *    - Derived Class (Child / Sub Class): The new class that inherits from the base class.
 * 
 * 3. GENERAL SYNTAX:
 *    -------------------------------------------------------------------------------------------
 *    class DerivedClass : access_specifier BaseClass {
 *        // Additional data members and member functions specific to DerivedClass
 *    };
 *    -------------------------------------------------------------------------------------------
 *    Example:
 *        class Student : public Person { ... };
 * 
 * 4. VISIBILITY MODES & ACCESS CONTROL:
 *    The access specifier (public, protected, private) controls how members of the base class
 *    are accessed inside the derived class:
 * 
 *    -------------------------------------------------------------------------------------------
 *    Base Member     | Inherited as 'public'   | Inherited as 'protected' | Inherited as 'private'
 *    -------------------------------------------------------------------------------------------
 *    public          | public                  | protected                | private
 *    protected       | protected               | protected                | private
 *    private         | NOT ACCESSIBLE          | NOT ACCESSIBLE           | NOT ACCESSIBLE
 *    -------------------------------------------------------------------------------------------
 * 
 *    KEY TAKEAWAYS FOR 'public' INHERITANCE:
 *    - 'public' members of the Base class become 'public' in the Derived class (accessible anywhere).
 *    - 'private' members of the Base class can NEVER be directly accessed by the Derived class.
 *      (They can only be accessed indirectly through public/protected methods of the Base class).
 * ==============================================================================================
 */

#include <iostream>
#include <string>
using namespace std;

// ==============================================================================================
// 1. BASE CLASS: Person
// ==============================================================================================
/**
 * Common entity representing a general person with basic attributes (name, age).
 */
class Person {
public:
    string name;
    int age;

    // Default & Parameterized Constructor
    Person(string n = "", int a = 0) : name(n), age(a) {}

    // Display common person details
    void displayPerson() const {
        cout << "Name: " << name << " | Age: " << age;
    }
};

// ==============================================================================================
// 2. DERIVED CLASS 1: Student (Publicly inherits from Person)
// ==============================================================================================
/**
 * Student IS-A Person.
 * Inherits 'name' and 'age' from Person, and adds 'rollno' and 'course'.
 */
class Student : public Person {
public:
    int rollno;
    string course;

    // Parameterized Constructor: initializes base members via Base Constructor
    Student(string n = "", int a = 0, int r = 0, string c = "") 
        : Person(n, a), rollno(r), course(c) {}

    // Display student-specific details along with base details
    void displayStudent() const {
        displayPerson(); // Call base class method
        cout << " | Roll No: " << rollno << " | Course: " << course << endl;
    }
};

// ==============================================================================================
// 3. DERIVED CLASS 2: Teacher (Publicly inherits from Person)
// ==============================================================================================
/**
 * Teacher IS-A Person.
 * Inherits 'name' and 'age' from Person, and adds 'employeeId' and 'subject'.
 */
class Teacher : public Person {
public:
    int employeeId;
    string subject;

    // Parameterized Constructor
    Teacher(string n = "", int a = 0, int empId = 0, string sub = "")
        : Person(n, a), employeeId(empId), subject(sub) {}

    // Display teacher-specific details along with base details
    void displayTeacher() const {
        displayPerson(); // Call base class method
        cout << " | Employee ID: " << employeeId << " | Subject: " << subject << endl;
    }
};

// ==============================================================================================
// 4. MAIN FUNCTION & DEMONSTRATION
// ==============================================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "           INHERITANCE IN C++: PERSON HIERARCHY          " << endl;
    cout << "=========================================================" << endl;

    // 1. Creating and configuring a Student object
    cout << "\n--- Student Object (Derived from Person) ---" << endl;
    Student st("Nikhil", 20, 101, "Computer Science & Engineering");

    // Accessing inherited Base Class data members directly (due to public inheritance)
    cout << "Direct access to inherited Base member (st.name): " << st.name << endl;
    cout << "Direct access to derived member (st.course):     " << st.course << endl;

    cout << "\nDisplaying Full Student Details:" << endl;
    st.displayStudent();

    // 2. Creating and configuring a Teacher object
    cout << "\n--- Teacher Object (Derived from Person) ---" << endl;
    Teacher prof("Dr. Sharma", 45, 5001, "Object-Oriented Programming");

    cout << "Direct access to inherited Base member (prof.name): " << prof.name << endl;
    cout << "Direct access to derived member (prof.subject):    " << prof.subject << endl;

    cout << "\nDisplaying Full Teacher Details:" << endl;
    prof.displayTeacher();

    cout << "\n=========================================================" << endl;
    return 0;
}