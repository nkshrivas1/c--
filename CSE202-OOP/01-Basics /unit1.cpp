#include<iostream>
using namespace std;
// write a function to calculat volume of a cuboid
//scope - it defines the region of your code where a 
// variable or fun is visible , accessible
inline int cuboid(int l , int b, int h){
    return l * b* h;
}
// An inline function is a performance optimization feature that suggests
// the compiler replace a function call directly with the function's
//  actual code. 

// Key Mechanics 
// Code Expansion: Eliminates the overhead of function calls
//  (like pushing arguments onto the stack). 
// Compiler Choice: The keyword is a request, not a command. 
// The compiler can ignore it. 
// Size Trade-off: Can increase the size of the final binary file 
// if the function is large. [6, 


// Manipulators are special functions or objects used with the stream 
// insertion () and extraction () operators to change how data is 
// formatted and displayed. [16, 17, 18] 

// Types of Manipulators 
// Non-parameterized: Do not take arguments (require ). 
// Parameterized: Take arguments to customize formatting (require ).
// Common Non-Parameterized Manipulators
// std::endl: Inserts a newline character and flushes the output 
// stream buffer.
// std::hex / std::oct / std::dec: Changes the number base to hexadecimal,
//  octal, or decimal.
// std::left / std::right: Aligns text output to the left or right.
//  [1, 2, 3, 4, 5]
// Common Parameterized Manipulators (<iomanip>)
// std::setw(int n): Sets the field width for the next output to exactly n
//  characters.
// std::setfill(char c): Specifies the character to fill the
//  empty spaces created by setw.
// std::setprecision(int n): Sets the total number of digits or
//  decimal places for floating-point numbers.


class myclass{
    private:
        int private_variable;
        int* dataBuffer;
        void greet(){
            cout << " welcome to my class " << endl;
        }
    public:
        myclass(){
            dataBuffer = new int[100];
            private_variable = 10;
        }
    // destructor is a special member function that is automatically called 
    // when an object goes out of scope or is explicitly deleted,
    //  serving as the primary mechanism to free resources
    //  and prevent memory leaks.
        ~myclass(){
            delete[] dataBuffer;
            cout<< "resource cleaned" << endl;
        }
        friend class cse;
        // friend void friendfn(myclass & obj);
        int fact(int n){
            if(n == 0 || n== 1)
                return 1;
            return n*fact(n-1);
        }
};
// void friendfn(myclass &obj){
//     cout << " my class private variable" << obj.private_variable;
//     obj.greet();
// }


class cse{
    public:
        void greetings(myclass &c){
            cout << "hello" << c.private_variable << endl;
        }
};
#include <iomanip>
int main(){
    cse c1;
    myclass my;
      double pi = 3.1415926535;
    int number = 255;
    // github - nkshrivas1/c--
    // https://github.com/nkshrivas1/c--
    // Base conversion
    std::cout << "Hexadecimal: " << std::hex << number << std::endl;

    // Formatting widths and fills
    std::cout << std::setfill('*') << std::setw(10) << "Hi" 
    << std::endl;

    // Precision management
    std::cout << "Pi to 3 decimal places: " << std::fixed 
    << std::setprecision(3) << pi << std::endl;

    // c1.greetings(my);
    // friendfn(my);
}