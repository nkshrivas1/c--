// create a class name Book and struct for book with 
//attributes name,author,price 
//and methods displayBookDetails

#include <iostream>
using namespace std;
 
void outsideFunction(){
    cout << "This is an outside function" << endl;
}
class Book{
    public:  
        string name;
        string author;
        double price;
        void displayBookDetails(string name, string author, double price){
            cout << "Book class Name: " << name << endl;
            cout << "Author: " << author << endl;
            cout << "Price: $" << price << endl;
        }
};

struct BookStruct{
    string name;
    string author;
    double price;
    void displayBookDetails(string name, string author, double price){
        this -> name = name;
        this -> author = author;
        this -> price = price;
        cout << "Book struct Name: " << this -> name << endl;
        cout << "Author: " << this -> author << endl;
        cout << "Price: $" << this -> price << endl;
    }
};


// create a class name rectangle with attributes 
//length and breadth 
// and methods area and perimeter

class Rectangle{
    public:
        double length;
        double breadth;
        double area(){
            return length * breadth;
        }
        double perimeter(){
            return 2 * (length + breadth);
        }
};
// write a switch case to print the 
// day of the week based on the integer
// input (0-6) where 0 is Monday and 6 is Sunday.
enum Days { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

// suppose i have a variable that can hold one of
// several types of information, i only need one of them at a time
// ans - union

union Data {
    int i;
    float f;
    char str[20];
};
void printDayOfWeek(int day){
    switch(day){
        case MONDAY:
            cout << "Monday" << endl;
            break;
        case TUESDAY:
            cout << "Tuesday" << endl;
            break;
        case WEDNESDAY:
            cout << "Wednesday" << endl;
            break;
        case THURSDAY:
            cout << "Thursday" << endl;
            break;
        case FRIDAY:
            cout << "Friday" << endl;
            break;
        case SATURDAY:
            cout << "Saturday" << endl;
            break;
        case SUNDAY:
            cout << "Sunday" << endl;
            break;
        default:
            cout << "Invalid input. Please enter a number between 0 and 6." << endl;
    }
}

int main() {
    
    // Enum - enumeration - is a user defined 
//data type that consists of integral 
//constants and each of them is given a name.
// enum Color { RED, GREEN, BLUE };
// int color[3] = {0,1,2};
// if(color[1] == GREEN) {
//     cout << "The color is green." << endl;
// } else if(color[1] == 0) {
//     cout << "The color is not green." << endl;
// }
//     cout << "Enum colur value green: " << GREEN << endl;
//     int day;
//     cin >> day;
//     printDayOfWeek(day);
//     Data data;
//     data.i = 10;
//     cout << "Data.i: " << data.i << endl;
//     data.f = 220.5;
//     cout << "Data.f: " << data.f << endl;
//     cout << "Data.i after assigning data.f: " << data.i << endl; // This will show garbage value
    // Book book1;
    // book1.name = "The Great Gatsby";
    // book1.author = "F. Scott Fitzgerald";
    // book1.price = 10.99;
    // book1.displayBookDetails();

    // BookStruct book2;
    // book2.name = "To Kill a Mockingbird";
    // book2.author = "Harper Lee";
    // book2.price = 12.99;
    // book2.displayBookDetails();

    // Rectangle rect;
    // rect.length = 5.0;
    // rect.breadth = 3.0;     
    // cout << "Perimeter of rectangle: " << rect.perimeter() << endl;
    // cout << "Area of rectangle: " << rect.area() << endl;
    return 0;
}