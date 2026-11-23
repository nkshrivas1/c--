
// // errors - a problem in a program that causes it to behave incorrectly
/*
    Types of errors:
    1. Compile time errors - errors that occur during compilation of the program
    2. Runtime errors - errors that occur during execution of the program
        examples:
            Division by zero
            Accessing an array out of bounds
            opening a file that does not exist
            memory allocation failure
    3. Logical errors - errors that occur due to incorrect logic in the program
    Exception handling - a mechanism to handle runtime errors in a program
    keywords -
    try - block of code that may throw an exception
        the program executes the statement inside the try block 
        if no exception is thrown, the catch block is skipped
        otherwise, the catch block is executed
    catch - block of code that handles the exception

    throw - keyword used to throw an exception
    finally - block of code that is executed regardless of whether an exception is thrown or not

    */
// #include <iostream>
// using namespace std;
// void checkAge(int age){
//     if(age < 0){
//         throw "Age cannot be negative";
//     }
//     else if(age > 150){
//         throw age;
//     }
//     else{
//         cout << "Your age is: " << age << endl;
//     }
// }
// int main(){

//     int a;
//     cout << "Enter a number: ";
//     cin >> a;
//     try{
//         checkAge(a);
//     }
//     catch(const char* msg){
//         cout << "Error: " << msg << endl;
//     }
//     catch(int num){
//         cout << "Error: Number cannot be greater than 150, you entered: " << num << endl;
//     }
//     catch(...){// catch all block
//         cout << "Error: Unknown error occurred" << endl;
//     }

// }



//     // int age;
//     // cout << "Enter your age: ";
//     // cin >> age;
//     // if(age < 0){
//     //     cout << "Age cannot be negative" << endl;
//     // }
//     // else if(age > 150){
//     //     cout << "Age cannot be greater than 150" << endl;
//     // }
//     // else{
//     //     cout << "Your age is: " << age << endl;
//     // }


// #include <iostream>
// using namespace std;
// int main() {    
//     try {
//         cout << "A";
//         throw 10;
//         cout << "B";
//     }
//     catch (int e) {
//         cout << "C";
//     }
//     cout << "D";
//     return 0;
// }

#include <iostream>
#include <stdexcept>
// runtime_error - base class for all standard exceptions
// invalid_argument - derived class of runtime_error
// out_of_range - derived class of runtime_error
// logic_error - base class for all logic errors
using namespace std;
class MyException : public exception {
    public: 
    // override the what() function to provide a custom error message
        const char* what() const noexcept override {
            return "My custom exception occurred";
        }
};
void testFunction() {
    throw MyException();
}
void testFunction2() {
     // rethrowing an exception
    try {
        throw runtime_error("Runtime error occurred");
    }
    catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
        throw; // rethrow the exception
    }
}
int main() {
    // try {
    //     throw 10.5;
    // }
    // catch (int e) {
    //     cout << "Integer exception";
    // }
    // catch (double e) {
    //     cout << "Double exception";
    // }
// try {
//     throw 100;
// }
// catch (int x) {
//     cout << "First";
// }
// catch (int x) {
//     cout << "Second";
// }

    try {
        cout << "Start ";
        throw invalid_argument("Invalid argument");
        cout << "Middle ";
    }
    catch (const invalid_argument& e) {
        cout << "Caught exception: " << e.what()    << " ";
    }
    cout << "End";
    try {
        throw 10;
    }
    catch (int e) {
        cout << "Integer exception";
    }
      catch (...) {
        cout << "General exception";
    }
    try{
        testFunction2();
    }
    catch(const runtime_error& e){
        cout << "Caught exception in main: " << e.what() << endl;
    }


    return 0;
}