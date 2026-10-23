
#include<iostream>
using namespace std;
// basic type to basic type
// basic type to class type
// class type to basic type
// one class type to another class type

//Type of conversions 
// Implicit
// Explicit


//Basic type to class type 
class Distance{
    private:
        int meters;
        int centimeters;
    public:
    Distance(int m){
        meters = m;
        centimeters = 0;
    }
    void display(){
        cout<<meters<<" meters "<<centimeters<<" centimeters"<<endl;
    }
    
};
// copy initialization
// Distance d1 = 5; // Implicit conversion from int to Distance
//Direct initialization
// Distance d2(5); // Implicit conversion from int to Distance
// using the explicit keyword to prevent implicit conversion
class DistanceExplicit{
    private:
        int meters;
        int centimeters;
    public:
    explicit DistanceExplicit(int m){
        meters = m;
        centimeters = 0;
    }
    void display(){
        cout<<meters<<" meters "<<centimeters<<" centimeters"<<endl;
    }   
};
// class type to basic type conversion
// the function name begins with operator
// the target type follows operator keyword
// no return type is specified for the conversion function
// fn has no explicit parameter list
// const qualifier indicates that the conversion
//  function does not modify the state of the object
// syntax
//operator type() const{
// return value;
// }
class DistanceToInt{
    private:
        int meters;
        int centimeters;
    public:
    DistanceToInt(int m){
        meters = m;
        centimeters = 0;
    }
    operator int() const {
        return meters;
    }
    void display(){
        cout<<meters<<" meters "<<centimeters<<" centimeters"<<endl;
    }
};  

//Q. create a class with type conversion which 
 //convert temperature from celcius to fahrenheit
 class Temp{
    private:
    double celcius;
    public:
    Temp(double c): celcius(c){}
    operator double() const{
        return (9.0/5.0)*celcius + 32.0;
    }
    void display(){
        cout << celcius << " celcius" << endl;
    }

 };
 class Number{
    public:
        int value;
        Number(int v):value(v){}
        operator int() const{
            return value;
        }
        void display() const{
            cout << "Stores value: "<< value<<endl;
        }
};
int main(){
    Temp celc = 40;
    cout<<" First " << celc << endl;

    celc.display();
    double farh= celc;
    cout << farh << endl;
    //int to number
    Number n =40;
    // Number to int 
    cout << n << endl;


//    Distance d = 5; // Implicit conversion from int to Distance
//     d.display(); // Output: 5 meters 0 centimeters
//     DistanceExplicit de(5); // Explicit conversion from int to DistanceExplicit
//     de.display(); // Output: 5 meters 0 centimeters 
//     DistanceExplicit de2 = 5; // Error: cannot convert from int to DistanceExplicit
//     de2.display(); // This line will not compile due to the previous error
//     double x = 12.8;
    // int y = 3;

// DistanceToInt d1(10);
// int meter = d1;

    // cout << x/y << endl;
    return 0;
}