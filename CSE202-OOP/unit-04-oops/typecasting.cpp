/**
 * ==============================================================================================
 *                         CSE202: OBJECT-ORIENTED PROGRAMMING IN C++
 *                          UNIT 4: TYPE CONVERSION & TYPE CASTING
 * ==============================================================================================
 * 
 * TOPICS COVERED:
 * ----------------
 * 1. Overview of Type Conversions in C++ (Implicit vs. Explicit)
 * 2. Categories of Type Conversions in Object-Oriented Programming:
 *    a) Basic Type to Basic Type (Built-in casting)
 *    b) Basic Type to Class Type (Conversion Constructor & 'explicit' keyword)
 *    c) Class Type to Basic Type (Conversion Operator Functions / Casting Operators)
 *    d) (One Class Type to Another Class Type - Category Overview)
 * 3. Preventing Unintended Implicit Conversions using the 'explicit' Keyword
 * 4. Practical Demonstrations:
 *    - Distance (Basic to Class)
 *    - DistanceExplicit (Preventing implicit conversion)
 *    - DistanceToInt (Class to Basic)
 *    - Temp (Celsius to Fahrenheit Conversion)
 *    - Number (Primitive Wrapper & Bidirectional Conversion)
 * 
 * ==============================================================================================
 * THEORY & EXAM NOTES: TYPE CONVERSION
 * ==============================================================================================
 * 
 * 1. WHAT IS TYPE CONVERSION?
 *    - In C++, type conversion is the process of converting a value of one data type into another.
 *    - IMPLICIT CONVERSION (Coercion): Performed automatically by the compiler when types are 
 *      compatible (e.g., int to double).
 *    - EXPLICIT CONVERSION (Casting): Performed intentionally by the programmer to enforce a type change.
 * 
 * 2. CLASSIFICATION OF CONVERSIONS IN C++ OOP:
 *    -------------------------------------------------------------------------------------------
 *    Conversion Type                  | Mechanism Used in C++
 *    -------------------------------------------------------------------------------------------
 *    1. Basic Type -> Basic Type      | Built-in casting rules / static_cast<type>(val)
 *    2. Basic Type -> Class Type      | Single-argument Constructor (Conversion Constructor)
 *    3. Class Type -> Basic Type      | Overloaded Conversion Operator function: operator type()
 *    4. Class Type -> Class Type      | Conversion Constructor in Destination Class OR 
 *                                     | Conversion Operator in Source Class
 *    -------------------------------------------------------------------------------------------
 * 
 * 3. BASIC TYPE TO CLASS TYPE CONVERSION:
 *    - Accomplished using a CONSTRUCTOR that accepts a single argument of the basic type.
 *    - Syntax:
 *        class ClassName {
 *        public:
 *            ClassName(BasicType val) { ... }
 *        };
 *    - Initialization forms:
 *        * Direct Initialization: ClassName obj(value);
 *        * Copy Initialization:   ClassName obj = value; // Implicitly invokes constructor!
 * 
 * 4. THE 'explicit' KEYWORD:
 *    - Applying 'explicit' to a single-parameter constructor PREVENTS the compiler from using it
 *      for implicit conversions or copy-initialization.
 *    - Syntax:
 *        explicit ClassName(BasicType val);
 *    - Effect:
 *        * Allowed:  ClassName obj(value);             (Direct Initialization)
 *        * Allowed:  ClassName obj = ClassName(value); (Explicit Cast)
 *        * BLOCKED:  ClassName obj = value;            (Compilation Error!)
 * 
 * 5. CLASS TYPE TO BASIC TYPE CONVERSION:
 *    - Accomplished using a special member function called a CONVERSION FUNCTION (Casting Operator).
 *    - Syntax:
 *        operator target_basic_type() const {
 *            return converted_value;
 *        }
 *    - FIVE STRICT RULES FOR CONVERSION FUNCTIONS (EXAM ESSENTIALS):
 *        1. Must be a member function of the class.
 *        2. Name MUST begin with the keyword 'operator', followed by the target type.
 *        3. Must NOT specify any return type (not even void); the return type is implicitly the target type.
 *        4. Must NOT accept any parameters/arguments.
 *        5. Should typically be declared 'const' since it merely reads state to compute a basic value.
 * ==============================================================================================
 */

#include <iostream>
#include <iomanip>
using namespace std;

// ==============================================================================================
// 1. BASIC TYPE TO CLASS TYPE CONVERSION
// ==============================================================================================
/**
 * Class Distance: Converts a primitive integer (meters) into a Distance object.
 * Because the constructor is NOT marked 'explicit', implicit conversion is allowed.
 */
class Distance {
private:
    int meters;
    int centimeters;

public:
    // Single-argument constructor serves as a Conversion Constructor
    Distance(int m) {
        meters = m;
        centimeters = 0;
    }

    void display() const {
        cout << meters << " meters " << centimeters << " centimeters" << endl;
    }
};

// ==============================================================================================
// 2. PREVENTING IMPLICIT CONVERSIONS: THE 'explicit' KEYWORD
// ==============================================================================================
/**
 * Class DistanceExplicit: Uses the 'explicit' keyword on the constructor.
 * This ensures that conversions must be intentional and prevents subtle bugs.
 */
class DistanceExplicit {
private:
    int meters;
    int centimeters;

public:
    // 'explicit' prevents: DistanceExplicit d = 5;
    explicit DistanceExplicit(int m) {
        meters = m;
        centimeters = 0;
    }

    void display() const {
        cout << meters << " meters " << centimeters << " centimeters" << endl;
    }
};

// ==============================================================================================
// 3. CLASS TYPE TO BASIC TYPE CONVERSION
// ==============================================================================================
/**
 * Class DistanceToInt: Demonstrates converting a DistanceToInt object into a basic 'int'.
 */
class DistanceToInt {
private:
    int meters;
    int centimeters;

public:
    DistanceToInt(int m, int cm = 0) : meters(m), centimeters(cm) {}

    // Overloaded Conversion Operator function
    // Rule 1: No return type specified (implicitly returns 'int')
    // Rule 2: No parameters
    // Rule 3: 'const' guarantees the function will not alter object state
    operator int() const {
        return meters; // Converts class object to basic int (meters)
    }

    void display() const {
        cout << meters << " meters " << centimeters << " centimeters" << endl;
    }
};

// ==============================================================================================
// 4. PRACTICAL CLASS: TEMPERATURE CONVERSION (Celsius to Fahrenheit)
// ==============================================================================================
/**
 * Class Temp:
 * - Accepts Celsius as basic type (double) -> Basic to Class
 * - Converts to Fahrenheit when assigned to double -> Class to Basic
 * Formula: Fahrenheit = (9.0 / 5.0) * Celsius + 32.0
 */
class Temp {
private:
    double celcius;

public:
    // Basic to Class Conversion (double -> Temp)
    Temp(double c = 0.0) : celcius(c) {}

    // Class to Basic Conversion (Temp -> double in Fahrenheit)
    operator double() const {
        return (9.0 / 5.0) * celcius + 32.0;
    }

    void display() const {
        cout << celcius << " °C" << endl;
    }
};

// ==============================================================================================
// 5. PRACTICAL CLASS: NUMBER WRAPPER (Bidirectional Conversion)
// ==============================================================================================
/**
 * Class Number: A wrapper around fundamental integer type showing both:
 * - int -> Number (Conversion Constructor)
 * - Number -> int (Conversion Operator)
 */
class Number {
private:
    int value;

public:
    // Basic to Class: int -> Number
    Number(int v = 0) : value(v) {}

    // Class to Basic: Number -> int
    operator int() const {
        return value;
    }

    void display() const {
        cout << "Stored Number: " << value << endl;
    }
};

// ==============================================================================================
// 6. MAIN FUNCTION & DEMONSTRATION
// ==============================================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "          1. BASIC TYPE TO CLASS TYPE CONVERSION         " << endl;
    cout << "=========================================================" << endl;

    // A. Implicit Conversion via Copy Initialization
    // Compiler interprets 'Distance d1 = 5;' as 'Distance d1(5);'
    Distance d1 = 5;
    cout << "Distance d1 (created via 'Distance d1 = 5;'): ";
    d1.display();

    // B. Direct Initialization
    Distance d2(12);
    cout << "Distance d2 (created via 'Distance d2(12);'): ";
    d2.display();

    cout << "\n=========================================================" << endl;
    cout << "     2. EXPLICIT CONSTRUCTORS ('explicit' KEYWORD)       " << endl;
    cout << "=========================================================" << endl;

    // Direct initialization is ALLOWED:
    DistanceExplicit de1(15);
    cout << "DistanceExplicit de1 (via 'DistanceExplicit de1(15);'): ";
    de1.display();

    // Explicit cast is ALLOWED:
    DistanceExplicit de2 = DistanceExplicit(25);
    cout << "DistanceExplicit de2 (via explicit temporary constructor): ";
    de2.display();

    // NOTE: The following line will produce a COMPILE-TIME ERROR if uncommented:
    // DistanceExplicit de3 = 50; 
    // Error: conversion from 'int' to non-scalar type 'DistanceExplicit' requested
    cout << ">> Implicit conversion 'DistanceExplicit de = 5;' is BLOCKED by compiler." << endl;

    cout << "\n=========================================================" << endl;
    cout << "          3. CLASS TYPE TO BASIC TYPE CONVERSION         " << endl;
    cout << "=========================================================" << endl;

    DistanceToInt dObj(42, 75);
    cout << "DistanceToInt object: ";
    dObj.display();

    // Class to Basic Conversion invoked implicitly
    int extractedMeters = dObj; // Invokes operator int()
    cout << "Extracted basic integer (meters): " << extractedMeters << endl;

    cout << "\n=========================================================" << endl;
    cout << "       4. CELSIUS TO FAHRENHEIT TEMPERATURE CONVERSION   " << endl;
    cout << "=========================================================" << endl;

    // 1. Basic (double) to Class (Temp)
    Temp bodyTemp = 37.0;
    cout << "Temperature in Celsius: ";
    bodyTemp.display();

    // 2. Class (Temp) to Basic (double) - returns Fahrenheit
    double fahrenheit = bodyTemp; // Invokes operator double()
    cout << "Converted to Fahrenheit: " << fixed << setprecision(1) << fahrenheit << " °F" << endl;

    // Direct output using conversion operator
    Temp boiling = 100.0;
    cout << "Boiling point: ";
    boiling.display();
    cout << "In Fahrenheit: " << double(boiling) << " °F" << endl;

    cout << "\n=========================================================" << endl;
    cout << "             5. BIDIRECTIONAL NUMBER WRAPPER             " << endl;
    cout << "=========================================================" << endl;

    // Basic to Class
    Number num = 40;
    num.display();

    // Class to Basic
    int primitiveVal = num;
    cout << "Assigned back to int: " << primitiveVal << endl;

    // Using in arithmetic expressions via conversion
    cout << "Arithmetic (num + 10): " << (num + 10) << endl;

    cout << "=========================================================" << endl;
    return 0;
}