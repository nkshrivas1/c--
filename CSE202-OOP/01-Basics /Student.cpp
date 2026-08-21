
#include <iostream>
using namespace std;

class Subject{
    public:
    // variables | attributes -
        string name;
        double marks;
        int displayMarks(){
            cout << "Marks of " << name << " is: " << marks << endl;
            return marks;
        }
        void getRecommendedData(){
            cout << "Recommended data is: " << algo() << endl;
        }
    //helper function to get recommended data
    private:
       string algo(){
        return "recommended data";
       }

};
struct Student{
    int regno;
    string name;
    int rollno; 
    int age;
    string mobile;
    double marks;
    void study(){
        cout << name << " is studying" << endl;
    }
};




// Student 
//reg no,name,rollno ,age,mobile ,marks
// study,give exam,display details,display marks,display result
class Student{
    // Access specifier
    // private:
    // public 
    // protected
    // attributes
    public:
        int regno;
        string name;
        int rollno; 
        int age;
        string mobile;
        //behaviours or methods
        void study(){
            cout << name << " is studying" << endl;
        }
    private:
        double marks;
    // private - means they cannot be accessed outside the class
    // public - means they can be accessed outside the class
    public:
        void setMarks(double m){
            if(m<0 || m>100){
                cout << "Invalid marks" << endl;
                return;
            }
            marks = m;
        }
    //create a class name subject 
    // with attributes name,marks and methods displayMarks

    void displayMarks(){
        cout << "Marks of " << name << " is: " << marks << endl;
    }
};

int main() {
     // student 1;
     int a = 10;
     //s1 is an object of class Student
     Student s1;
     cout << s1.name << endl;
     s1.name = "Nikhil";
     s1.setMarks(85.5);
    //  s1.marks = 85.5;
     cout << s1.name << endl;
    //  s1.displayMarks();
    //  cout << s1.marks << endl;
    //  s1.study();
     Student s2;
     s2.name = "Rohit";
    //  s2.study();
     Subject sub1;
     sub1.name = "Maths";
     sub1.marks = 100.96;
     int subjectMarks = sub1.displayMarks();
     cout << "subject marks -" << subjectMarks ;
    //  sub1.getRecommendedData();
    return 0;
}


// class -> object -> attributes and methods
// -> private data -> public methods -> working program