/**
 * ==============================================================================================
 *                         CSE202: OBJECT-ORIENTED PROGRAMMING IN C++
 *                          UNIT 4: OPERATOR OVERLOADING & POLYMORPHISM
 * ==============================================================================================
 * 
 * TOPICS COVERED:
 * ----------------
 * 1. Introduction to Operator Overloading (Compile-Time Polymorphism)
 * 2. Syntax & Rules of Operator Overloading
 * 3. Unary Operator Overloading:
 *    - Prefix Increment (++obj) & Prefix Decrement (--obj)
 *    - Postfix Increment (obj++) & Postfix Decrement (obj--)
 *    - Unary Minus (-obj)
 * 4. Binary Operator Overloading:
 *    - Arithmetic Operators (+, -, *, /)
 *    - Relational / Comparison Operators (==)
 * 5. Practical Demonstration in main()
 * 
 * ==============================================================================================
 * THEORY & EXAM NOTES: OPERATOR OVERLOADING
 * ==============================================================================================
 * 
 * 1. WHAT IS OPERATOR OVERLOADING?
 *    - Operator Overloading is a form of COMPILE-TIME (STATIC) POLYMORPHISM in C++.
 *    - It provides a mechanism to redefine the behavior of built-in operators (+, -, ++, etc.)
 *      when applied to user-defined types (classes and structures).
 *    - Example: '+' naturally adds two integers (3 + 5 = 8). Operator overloading allows '+' 
 *      to add two Complex numbers, Strings, or Distance objects (d1 + d2).
 * 
 * 2. GENERAL SYNTAX:
 *    -------------------------------------------------------------------------------------------
 *    return_type operator op (arguments) {
 *        // Body of the operator function
 *    }
 *    -------------------------------------------------------------------------------------------
 *    - 'operator': A C++ keyword.
 *    - 'op': The operator symbol being overloaded (+, -, ++, ==, etc.).
 * 
 * 3. RULES & RESTRICTIONS OF OPERATOR OVERLOADING:
 *    - Only EXISTING operators can be overloaded; you CANNOT create brand-new operators.
 *    - Operator PRECEDENCE and ASSOCIATIVITY CANNOT be altered.
 *    - ARITY (number of operands) CANNOT be changed:
 *        * Unary operators must remain unary (1 operand).
 *        * Binary operators must remain binary (2 operands).
 *    - At least ONE operand must be of user-defined type (class/enum); you cannot overload 
 *      operators for fundamental types alone (e.g., you cannot redefine 1 + 2).
 *    - Default arguments cannot be used in operator functions.
 * 
 * 4. OPERATORS THAT CANNOT BE OVERLOADED (VIVA / EXAM FAVORITE):
 *    1. Scope Resolution Operator          ::
 *    2. Member Access (Dot) Operator       .
 *    3. Pointer-to-Member Operator         .*
 *    4. Ternary / Conditional Operator     ?:
 *    5. Size-of Operator                   sizeof
 *    6. Type identification Operator       typeid
 * 
 * 5. OPERATORS THAT MUST BE OVERLOADED AS MEMBER FUNCTIONS (NOT FRIENDS):
 *    - Assignment operator:                =
 *    - Subscript operator:                 []
 *    - Function call operator:             ()
 *    - Class member access by pointer:     ->
 * ==============================================================================================
 */

#include <iostream>
#include <iomanip>
using namespace std;

// ==============================================================================================
// 1. UNARY OPERATOR OVERLOADING
// ==============================================================================================
/**
 * Unary operators operate on a single operand (e.g., ++x, --x, -x, !flag).
 * 
 * When overloaded as a MEMBER function:
 *   - Takes ZERO explicit parameters.
 *   - The calling object (*this) implicitly acts as the single operand.
 * 
 * Prefix vs. Postfix:
 * ---------------------------------------------------------------------------------------------
 * Feature          | Prefix (++obj, --obj)             | Postfix (obj++, obj--)
 * ---------------------------------------------------------------------------------------------
 * Signature        | ClassName& operator++()           | ClassName operator++(int)
 * Dummy Parameter  | None                              | 'int' (signals compiler it's postfix)
 * Mechanism        | Increments first, returns updated | Copies old state, increments, returns copy
 * Return Type      | Reference (ClassName&)            | By Value (ClassName)
 * Chaining         | Supported (++++obj)               | Not allowed on rvalue copies
 * ---------------------------------------------------------------------------------------------
 */
class Counter {
public:
    int value;

    // Constructor with default argument
    Counter(int v = 0) : value(v) {}

    // -------------------------------------------------------------------------
    // 1. Prefix Increment (++c)
    // -------------------------------------------------------------------------
    // Steps:
    // 1. Increment value first.
    // 2. Return the updated object (*this) by reference.
    Counter& operator++() {
        ++value;
        return *this;
    }

    // -------------------------------------------------------------------------
    // 2. Postfix Increment (c++)
    // -------------------------------------------------------------------------
    // Steps:
    // 1. Capture current state in a temporary object.
    // 2. Increment the actual object value.
    // 3. Return the unmodified temporary object by value.
    Counter operator++(int) {
        Counter temp = *this;
        ++value;
        return temp;
    }

    // -------------------------------------------------------------------------
    // 3. Prefix Decrement (--c)
    // -------------------------------------------------------------------------
    Counter& operator--() {
        --value;
        return *this;
    }

    // -------------------------------------------------------------------------
    // 4. Postfix Decrement (c--)
    // -------------------------------------------------------------------------
    Counter operator--(int) {
        Counter temp = *this;
        --value;
        return temp;
    }

    // -------------------------------------------------------------------------
    // 5. Unary Minus (-c)
    // -------------------------------------------------------------------------
    // Non-modifying: Returns a new Counter holding the negated value without
    // altering the original object state.
    Counter operator-() const {
        return Counter(-value);
    }

    // Display helper
    void display() const {
        cout << value << endl;
    }
};

// ==============================================================================================
// 2. BINARY OPERATOR OVERLOADING
// ==============================================================================================
/**
 * Binary operators operate on two operands (e.g., +, -, *, /, ==, <, >).
 * 
 * When overloaded as a MEMBER function:
 *   - Takes ONE explicit parameter (representing the right operand).
 *   - The calling object (*this) implicitly acts as the left operand.
 * 
 * Syntax:
 *   return_type operator op (const ClassName& rightOperand) const;
 */
class Distance {
public:
    int feet;
    int inches;

    // Constructor with default arguments
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {
        normalize();
    }

    // Normalize inches into feet (ensures inches < 12)
    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        } else if (inches < 0) {
            // Adjust negative inches if needed
            int borrow = (-inches + 11) / 12;
            feet -= borrow;
            inches += borrow * 12;
        }
    }

    // -------------------------------------------------------------------------
    // 1. Binary Addition (+) : Distance + Distance
    // -------------------------------------------------------------------------
    Distance operator+(const Distance& d) const {
        int totalInches = (feet * 12 + inches) + (d.feet * 12 + d.inches);
        return Distance(totalInches / 12, totalInches % 12);
    }

    // -------------------------------------------------------------------------
    // 2. Binary Subtraction (-) : Distance - Distance
    // -------------------------------------------------------------------------
    Distance operator-(const Distance& d) const {
        int totalInches1 = (feet * 12 + inches);
        int totalInches2 = (d.feet * 12 + d.inches);
        int diffInches = totalInches1 - totalInches2;

        if (diffInches < 0) {
            diffInches = 0; // Prevent negative distances
        }
        return Distance(diffInches / 12, diffInches % 12);
    }

    // -------------------------------------------------------------------------
    // 3. Binary Multiplication (*) : Distance * int (Scalar scaling)
    // -------------------------------------------------------------------------
    Distance operator*(int multiplier) const {
        int totalInches = (feet * 12 + inches) * multiplier;
        return Distance(totalInches / 12, totalInches % 12);
    }

    // -------------------------------------------------------------------------
    // 4. Binary Division (/) : Distance / int (Scalar division)
    // -------------------------------------------------------------------------
    Distance operator/(int divisor) const {
        if (divisor == 0) {
            cout << "Error: Division by zero!" << endl;
            return *this;
        }
        int totalInches = (feet * 12 + inches) / divisor;
        return Distance(totalInches / 12, totalInches % 12);
    }

    // -------------------------------------------------------------------------
    // 5. Relational Equality (==) : Distance == Distance
    // -------------------------------------------------------------------------
    bool operator==(const Distance& d) const {
        return (feet == d.feet) && (inches == d.inches);
    }

    // Display helper
    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

// ==============================================================================================
// 3. MAIN FUNCTION & DEMONSTRATION
// ==============================================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "           1. UNARY OPERATOR OVERLOADING DEMO            " << endl;
    cout << "=========================================================" << endl;

    Counter c1(5);
    cout << "Initial value of c1: ";
    c1.display();

    cout << "\n--- Prefix vs Postfix Increment ---" << endl;
    cout << "Prefix increment (++c1): ";
    (++c1).display(); // Increments to 6, then displays 6

    cout << "Postfix increment (c1++): ";
    (c1++).display(); // Displays 6, then increments to 7

    cout << "Value of c1 after postfix increment: ";
    c1.display(); // Displays 7

    cout << "\n--- Prefix vs Postfix Decrement ---" << endl;
    cout << "Prefix decrement (--c1): ";
    (--c1).display(); // Decrements to 6, displays 6

    cout << "Postfix decrement (c1--): ";
    (c1--).display(); // Displays 6, decrements to 5

    cout << "Value of c1 after postfix decrement: ";
    c1.display(); // Displays 5

    cout << "\n--- Unary Minus Operator ---" << endl;
    cout << "Unary minus (-c1): ";
    (-c1).display(); // Displays -5
    cout << "Original c1 remains unmodified: ";
    c1.display(); // Displays 5

    cout << "\n--- Chaining Prefix Increments ---" << endl;
    ++++++c1; // Allowed because prefix returns Counter&
    cout << "Value of c1 after ++++++c1: ";
    c1.display(); // Displays 8

    cout << "\n=========================================================" << endl;
    cout << "          2. BINARY OPERATOR OVERLOADING DEMO            " << endl;
    cout << "=========================================================" << endl;

    Distance d1(5, 8);  // 5 feet 8 inches
    Distance d2(3, 10); // 3 feet 10 inches

    cout << "Distance d1: ";
    d1.display();
    cout << "Distance d2: ";
    d2.display();

    cout << "\n--- Binary Addition (d1 + d2) ---" << endl;
    Distance d3 = d1 + d2; // 5'8" + 3'10" = 8'18" -> 9 feet 6 inches
    cout << "d1 + d2 = ";
    d3.display();

    cout << "\n--- Binary Subtraction (d1 - d2) ---" << endl;
    Distance d4 = d1 - d2; // 5'8" - 3'10" = 68" - 46" = 22" -> 1 foot 10 inches
    cout << "d1 - d2 = ";
    d4.display();

    cout << "\n--- Scalar Multiplication (d1 * 2) ---" << endl;
    Distance d5 = d1 * 2; // (5'8") * 2 = 68" * 2 = 136" -> 11 feet 4 inches
    cout << "d1 * 2 = ";
    d5.display();

    cout << "\n--- Scalar Division (d1 / 2) ---" << endl;
    Distance d6 = d1 / 2; // (5'8") / 2 = 68" / 2 = 34" -> 2 feet 10 inches
    cout << "d1 / 2 = ";
    d6.display();

    cout << "\n--- Relational Equality (==) ---" << endl;
    Distance d7(5, 8);
    cout << "Comparing d1 == d2: " << (d1 == d2 ? "Equal" : "Not Equal") << endl;
    cout << "Comparing d1 == d7: " << (d1 == d7 ? "Equal" : "Not Equal") << endl;

    cout << "=========================================================" << endl;
    return 0;
}