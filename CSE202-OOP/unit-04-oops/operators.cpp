#include<iostream>
using namespace std;




// Built in operations
// ++x
//-x
//!flag
//Operations on a user defined objects
// ++obj
//-obj
//!obj
//// what is unary operator?
//A unary operator is an operator that takes only one operand
//  and performs an operation on it. 
// Examples of unary operators include increment (++),
//  decrement (--), negation (-), and logical NOT (!)
// . In the context of user-defined objects, 
// syntax for overloading unary operators 
// is similar to that of built-in types,
// General syntax
// return_type operator unary_operator (){
//     // implementation of the operator
// }
class Counter{
    public:
        int value;
        Counter(int v=0){
            value = v;
        }
        // operator - is a C++ keyword

        //Prefix overloading of unary operator ++
        Counter& operator++(){
            ++value;
            return *this;
        }
        //Postfix overloading of unary operator ++
        Counter operator++(int){
            Counter temp = *this;
            ++value;
            return temp;
        }
        // Prefix =
        // 1.operator++()
        // 2.increment before returning the value
        //3. return the updated object
        //4. return type Counter& 
        // Postfix =
        // 1.operator++(int)
        // 2.increment after returning the value
        //3. return the original object
        //4. return type Counter
        // Overloading the Decrement operator
        // Prefix overloading of unary operator --
        Counter& operator--(){
            --value;
            return *this;
        }
        //Postfix decrement
        Counter operator--(int){
            Counter temp = *this;
            --value;
            return temp;
        }
        // void operator-(){
        //     value = -value;
        // }
        //Non modifying unary minus operator
        Counter operator-(){
            return Counter(-value);
        }
        void display(){
            cout<<value<<endl;
        }
};

// Binary operator overloading
// Binary operators are operators that take two operands and perform 
// an operation on them.
// Examples of binary operators include addition (+),
//  subtraction (-), multiplication (*), division (/),
// assignment (=). (==),(<), (>) etc.

//syntax of binary operator overloading
// return_type operator binary_operator (const ClassName& other){
//     // implementation of the operator
// }
class Distance{
    
    public:
        int feet;
        int inches;
        Distance(int f=0,int i=0){
            feet = f;
            inches = i;
        }
        // Overloading the + operator
        Distance operator+(const Distance& d){
            int totalInches = (feet + d.feet) * 12 + (inches + d.inches);
            return Distance(totalInches / 12, totalInches % 12);
        }
        //Overloading the - operator
        Distance operator-(const Distance& d){
            int totalInches1 = (feet * 12 + inches);
            int totalInches2 = (d.feet * 12 + d.inches);
            int diffInches = totalInches1 - totalInches2;
            return Distance(diffInches / 12, diffInches % 12);
        }
        //Overloading the * operator
        Distance operator*(int multiplier){
            int totalInches = (feet * 12 + inches) * multiplier;    
            return Distance(totalInches / 12, totalInches % 12);
        }
        //Overloading the / operator
        Distance operator/(int divisor){
            int totalInches = (feet * 12 + inches) / divisor;
            return Distance(totalInches / 12, totalInches % 12);
        }
        // overload the == operator
        bool operator==(const Distance& d) const {
            return (feet == d.feet) && (inches == d.inches);
        }
        void display(){
            cout<<feet<<" feet "<<inches<<" inches"<<endl;
        }
};

int main() {

    Distance d1(5, 8);
    Distance d2(3, 10);
    Distance d3 = d1 + d2; // Using overloaded + operator
    d3.display(); // Output: 9 feet 6 inches



    // Counter c1(5);
    // (++c1).display(); // Prefix increment
    // (c1++).display(); // Postfix increment
    // c1.display(); // Display current value after increments
    // (--c1).display(); // Prefix decrement
    // (c1--).display(); // Postfix decrement
    // c1.display(); // Display current value after decrements
    // (-c1).display(); // Unary minus operator
    // c1.display(); // Display current value after unary minus








    // cout<< "Negative of c1: " << (-c1).value << endl;
    // ++++++c1;
    // c1.display();
    // Counter c2 = c1++;
    // c2.display();
    // c1.display();
    return 0;

}