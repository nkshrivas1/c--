# Unit 4: Operator Overloading, Type Conversion & Inheritance
## Comprehensive Student Study Notes (CSE202 - Object-Oriented Programming in C++)

---

## Syllabus Roadmap (Topics Covered Till Date)

```
Unit 4: Advanced OOP Mechanics & Polymorphism
 ├── 1. Operator Overloading (Compile-Time Polymorphism)
 │    ├── Concept & Definition (Keyword: operator)
 │    ├── Rules and Restrictions of Overloading
 │    ├── Operators that CANNOT be Overloaded (::, ., .*, ?:, sizeof, typeid)
 │    ├── Member vs. Friend Operator Functions
 │    ├── Unary Operator Overloading:
 │    │    ├── Prefix Increment (++obj) & Decrement (--obj) [Returns Reference]
 │    │    ├── Postfix Increment (obj++) & Decrement (obj--) [Dummy 'int', Returns Copy]
 │    │    └── Unary Minus (-obj) [Non-modifying]
 │    └── Binary Operator Overloading:
 │         ├── Arithmetic Operators (+, -, *, /)
 │         └── Relational / Equality Operators (==)
 ├── 2. Type Conversion & Type Casting
 │    ├── Implicit (Coercion) vs. Explicit (Casting) Conversions
 │    ├── Basic Type to Class Type (Single-argument Conversion Constructor)
 │    ├── The 'explicit' Keyword (Blocking Unintended Implicit Conversions)
 │    └── Class Type to Basic Type (Overloaded Conversion Operator: operator type() const)
 └── 3. Inheritance Fundamentals
      ├── Concept & Definition (Code Reusability, "IS-A" Relationship)
      ├── Terminology: Base (Parent/Super) vs. Derived (Child/Sub) Class
      ├── General Syntax of Inheritance
      ├── Visibility Modes Overview (Public, Protected, Private)
      └── Public Inheritance Case Study: Person -> Student & Teacher
```

---

## 1. Operator Overloading (Compile-Time Polymorphism)

### 1.1 Definition & Concept
- **Operator Overloading** is a feature in C++ that allows existing built-in operators (such as `+`, `-`, `++`, `==`) to be redefined and given special meaning when applied to user-defined data types (objects of classes).
- It is a form of **Compile-Time Polymorphism** (also known as *Static Binding* or *Early Binding*).

### 1.2 General Syntax
```cpp
return_type operator op (parameter_list) {
    // Function body
}
```
- `operator`: C++ reserved keyword.
- `op`: The operator symbol being overloaded.

### 1.3 Rules and Restrictions
1. **No New Operators**: You can only overload existing C++ operators; you cannot invent new operators like `**` or `<>`.
2. **Precedence and Associativity**: Precedence and associativity rules cannot be altered.
3. **Arity Invariance**: The number of operands an operator expects cannot be changed (a unary operator remains unary; a binary operator remains binary).
4. **User-Defined Requirement**: At least one operand must be a user-defined type (class or enum). You cannot redefine operations purely on fundamental types (e.g., `1 + 2`).
5. **No Default Arguments**: Operator functions cannot have default parameters (except the function call operator `()`).

### 1.4 Operators That CANNOT Be Overloaded (Exam Essential)
| Operator Symbol | Name | Reason |
| :--- | :--- | :--- |
| `::` | Scope Resolution | Identifies names, not computed at runtime |
| `.` | Member Access (Dot) | Guarantees unambiguous direct member selection |
| `.*` | Pointer-to-Member Dereference | Essential core language semantic |
| `?:` | Ternary / Conditional | Has short-circuit evaluation semantics that cannot be preserved |
| `sizeof` | Size-of Operator | Evaluated entirely at compile time |
| `typeid` | Type Identification | Run-Time Type Information (RTTI) primitive |

### 1.5 Operators That MUST Be Overloaded as Member Functions
These four operators cannot be overloaded as standalone or friend functions:
1. Assignment: `=`
2. Array Subscript: `[]`
3. Function Call: `()`
4. Class Member Access via Pointer: `->`

---

## 2. Unary Operator Overloading

### 2.1 Concept
Unary operators take a single operand (e.g., `++x`, `--x`, `-x`).
When overloaded as a **member function**, it takes **zero explicit parameters** because the calling object (`*this`) is implicitly the sole operand.

### 2.2 Prefix vs. Postfix Comparison
| Feature | Prefix Increment (`++obj`) | Postfix Increment (`obj++`) |
| :--- | :--- | :--- |
| **Function Signature** | `ClassName& operator++()` | `ClassName operator++(int)` |
| **Dummy Parameter** | None | `int` (signals compiler to invoke postfix) |
| **Mechanism** | 1. Increments internal state<br>2. Returns updated object | 1. Saves old state in temporary copy<br>2. Increments internal state<br>3. Returns old copy |
| **Return Type** | `ClassName&` (by reference) | `ClassName` (by value) |
| **Chaining (`++++obj`)** | Allowed (modifies the same lvalue) | Disallowed (modifies a temporary rvalue) |

### 2.3 Unary Minus Operator (`-obj`)
```cpp
Counter operator-() const {
    return Counter(-value); // Non-modifying: leaves original unchanged
}
```

---

## 3. Binary Operator Overloading

### 3.1 Concept
Binary operators take two operands (e.g., `a + b`, `a - b`, `a == b`).
When overloaded as a **member function**:
- The left operand is the calling object (`*this`).
- The right operand is passed as an explicit parameter (typically `const ClassName& other`).

```cpp
return_type operator op (const ClassName& other) const;
```

### 3.2 Member Function Operations Table
| Operator | Return Type | Typical Usage | Notes |
| :--- | :--- | :--- | :--- |
| `+` | `Distance` | `d1 + d2` | Adds attributes and normalizes units |
| `-` | `Distance` | `d1 - d2` | Computes non-negative difference |
| `*` | `Distance` | `d * 2` | Scalar scaling (scalar passed as int) |
| `/` | `Distance` | `d / 2` | Scalar division (handles division by zero) |
| `==`| `bool` | `d1 == d2` | Returns true if all attributes match |

---

## 4. Type Conversion in C++ (OOP)

### 4.1 Overview of Conversion Types
1. **Basic Type to Basic Type**: Built-in conversion (e.g., `int` to `double`).
2. **Basic Type to Class Type**: Implemented via a **Conversion Constructor**.
3. **Class Type to Basic Type**: Implemented via an **Overloaded Conversion Operator**.
4. **Class Type to Another Class Type**: Implemented either via a conversion constructor in the destination class or a conversion operator in the source class.

### 4.2 Basic Type to Class Type Conversion
Achieved through a constructor taking a single parameter of the primitive type:
```cpp
class Distance {
    int meters;
public:
    Distance(int m) : meters(m) {} // Conversion Constructor
};

// Usage:
Distance d1 = 10; // Implicit conversion from int to Distance
Distance d2(10);  // Direct initialization
```

### 4.3 Preventing Implicit Conversions with `explicit`
The `explicit` keyword prevents the compiler from performing unwanted automatic type coercions:
```cpp
class DistanceExplicit {
    int meters;
public:
    explicit DistanceExplicit(int m) : meters(m) {}
};

// Usage:
DistanceExplicit de1(10);               // ALLOWED: Direct initialization
DistanceExplicit de2 = DistanceExplicit(10); // ALLOWED: Explicit cast
// DistanceExplicit de3 = 10;           // COMPILE ERROR: Implicit conversion blocked!
```

### 4.4 Class Type to Basic Type (Conversion Operator)
Allows an object of a user-defined class to be converted to a primitive type (e.g., `int`, `double`):

```cpp
class Temp {
    double celsius;
public:
    Temp(double c) : celsius(c) {}

    // Conversion operator to double (calculates Fahrenheit)
    operator double() const {
        return (9.0 / 5.0) * celsius + 32.0;
    }
};

// Usage:
Temp t = 100.0;
double f = t; // Implicitly calls operator double() -> 212.0 °F
```

#### The 5 Strict Rules of Conversion Operators:
1. Must be a **member function** of the class.
2. Must start with the keyword `operator` followed by the target type name.
3. Must **NOT specify any return type** (not even `void`).
4. Must **NOT take any parameters**.
5. Should be qualified with `const` as it does not modify the source object.

---

## 5. Inheritance Fundamentals

### 5.1 Concept & Definition
- **Inheritance** is the OOP mechanism through which a new class (**Derived Class** or Child Class) inherits properties and behaviors from an existing class (**Base Class** or Parent Class).
- Models the **IS-A** relationship (e.g., A Student IS-A Person; A Teacher IS-A Person).

### 5.2 Key Benefits
- **Code Reusability**: Common code resides in the parent class and is shared among all child classes.
- **Extensibility**: Derived classes can add specialized members without modifying existing base code.
- **Hierarchy Organization**: Reflects natural real-world domain structures.

### 5.3 Syntax
```cpp
class DerivedClass : access_specifier BaseClass {
    // Derived class-specific members
};
```

### 5.4 Visibility Modes Matrix
| Base Class Member | Public Inheritance (`: public`) | Protected Inheritance (`: protected`) | Private Inheritance (`: private`) |
| :--- | :--- | :--- | :--- |
| **`public`** | `public` in derived | `protected` in derived | `private` in derived |
| **`protected`**| `protected` in derived | `protected` in derived | `private` in derived |
| **`private`** | **Not Accessible** directly | **Not Accessible** directly | **Not Accessible** directly |

*Note: Base class private members are never directly accessible by derived classes under any visibility mode.*

### 5.5 Case Study: Person -> Student & Teacher
- **Base Class (`Person`)**: Holds common attributes: `name`, `age`, and `displayPerson()`.
- **Derived Class 1 (`Student`)**: Adds `rollno`, `course`, and `displayStudent()`.
- **Derived Class 2 (`Teacher`)**: Adds `employeeId`, `subject`, and `displayTeacher()`.

---

## 6. Directory File Index & Compilation Guide

| Source File | Primary Topics Covered |
| :--- | :--- |
| `operators.cpp` | Unary (`++`, `--`, `-`), Binary (`+`, `-`, `*`, `/`, `==`), Overloading Rules |
| `typecasting.cpp` | Basic to Class, `explicit` keyword, Class to Basic (`operator type() const`) |
| `inheritance.cpp` | Single inheritance syntax, Person/Student/Teacher hierarchy, Public access |

### Build & Run Commands:
```bash
# 1. Compile & run Operator Overloading
clang++ -std=c++17 -Wall -Wextra operators.cpp -o operators && ./operators

# 2. Compile & run Type Conversion
clang++ -std=c++17 -Wall -Wextra typecasting.cpp -o typecasting && ./typecasting

# 3. Compile & run Inheritance
clang++ -std=c++17 -Wall -Wextra inheritance.cpp -o inheritance && ./inheritance
```

