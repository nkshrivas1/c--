#include <iostream>
using namespace std;

// class MyString
// {
// private:

//     // =========================================
//     // DATA MEMBER
//     // =========================================

//     char str[100];


// public:

//     // =========================================
    // CONSTRUCTORS
    // =========================================

    // // Default constructor
    // MyString()
    // {
    //     // TODO:
    //     // Initialize the string as empty
    //     str[0] = '\0';
    // }


    // Parameterized constructor
//     MyString(const char s[])
//     {
//         // TODO:
//         // Copy characters from s into str
//         // Remember to add '\0' at the end
//         // MyString str("Hello");
//         int i=0;
//         while(s[i] != '\0'){
//             str[i] = s[i];
//             i++;
//         }
//         str[i] = '\0';
//     }



//     // =========================================
//     // BASIC FUNCTIONS
//     // =========================================

//     // Display the string
//     void display()
//     {
//         // TODO
//         cout << str <<endl;
//     }


//     // Find length of string
//     int length()
//     {
//         // TODO
//         int count =0;
//         while(str[count] != '\0'){
//             count++;
//         }
//         return count;
//     }



//     // =========================================
//     // CHARACTER ACCESS
//     // =========================================

//     // Get character at a particular index
//     char get(int index)
//     {
//         // TODO
//         if( index < 0 || index >= length()){
//             return '\0';
//         }

//         return str[index];
//     }


//     // Change character at a particular index
//     void set(int index, char ch)
//     {
//         // TODO
//            if( index < 0 || index >= length()){
//             return;
//         }
//         str[index] = ch;
//     }



//     // =========================================
//     // STRING OPERATIONS
//     // =========================================

//     // Copy another MyString
//     void copyFrom(const MyString &other,int i=0)
//     {
//         // TODO
//         int j =0;
      
//         while(other.str[j] != '\0'){
//             str[i] = other.str[j];
//             i++;
//             j++;
//         }
//         str[i] = '\0';
//     }


//     // Append another MyString
//     void append(const MyString &other)
//     {
//         // TODO
//         copyFrom(other,length());
//     }


//     // Find first occurrence of a character
//     int find(char ch)
//     {
//         // TODO
//         for( int i =0;str[i] != '\0' ;i++ ){
//             if(str[i] == ch){
//                 return i;
//             }
//         }

//         return -1;
//     }


//     // Compare two strings
//     int compare(const MyString &other)
//     {
//         // TODO
//             int i=0;
//             while(str[i] != '\0' && other.str[i] !='\0'){
//                 if( str[i] != other.str[i]){
//                     return str[i] - other.str[i];
//                 }
//                 i++;
//             }
//         return str[i] - other.str[i];
//     }


//     // Reverse the string
//     void reverse()
//     {
//         // TODO
//         //define two pointers i and j
//         //swap the characters at pointers 
//         //increment i and decrement j
//         int start =0;
//         //value = 0
//         //Address=1000

//         // but if i want another variable to know where start is stored
//         every
//         int end = length() -1;
//         while( start < end){
//             char temp = str[start];
//             str[start] = str[end];
//             str[end] = temp;
//             start++;
//             end--;
//         }
//     }
// };



// =====================================================
// MAIN
// =====================================================

int main()
{
    // // =========================================
    // // TEST 1 — CONSTRUCTOR
    // // =========================================

    // MyString s1("Hello");

    // cout << "String: ";
    // s1.display();


    // // =========================================
    // // TEST 2 — LENGTH
    // // =========================================

    // cout << "Length: "
    //      << s1.length()
    //      << endl;


    // // =========================================
    // // TEST 3 — GET
    // // =========================================

    // cout << "Character at index 1: "
    //      << s1.get(1)
    //      << endl;


    // // =========================================
    // // TEST 4 — SET
    // // =========================================

    // s1.set(0, 'Y');

    // cout << "After modification: ";
    // s1.display();


    // // =========================================
    // // TEST 5 — COPY
    // // =========================================

    // MyString s2;

    // s2.copyFrom(s1);

    // cout << "Copied string: ";
    // s2.display();


    // // =========================================
    // // TEST 6 — APPEND
    // // =========================================

    // MyString s3(" World");

    // s1.append(s3);

    // cout << "After append: ";
    // s1.display();


    // // =========================================
    // // TEST 7 — SEARCH
    // // =========================================

    // int position = s1.find('o');

    // cout << "Position of 'o': "
    //      << position
    //      << endl;


    // // =========================================
    // // TEST 8 — COMPARE
    // // =========================================

    // MyString s4("Hello");

    // MyString s5("Hello");

    // if (s4.compare(s5) == 0)
    // {
    //     cout << "Strings are equal."
    //          << endl;
    // }
    // else
    // {
    //     cout << "Strings are different."
    //          << endl;
    // }


    // // =========================================
    // // TEST 9 — REVERSE
    // // =========================================

    // s5.reverse();

    // cout << "Reversed string: ";
    // s5.display();



 //value = 0
        //Address=1000

        // but if i want another variable to know where start is stored
        // every variable has two important things associated with it 
        // what it contains
        // where it lives

        //Address operator &
        // int marks = 90;
        // cout << marks << endl;
        // cout << &marks << endl;

        // pointers and references
        // we store memory address of a varioable in popinter]
        // ..a reference acts as an alias for an existing variable
        //pointer
        // 1.vstore the address of a variable
        //2. can be reassigned to point to different varaiable
        //3.  can store nullptr  value when not pointing 
        // to any valid memory location
        //4.  require the dereference operator (*) to access
        //  the value stores at the address
        //5. have their own memory address independent
        //  of the varaible they point to
        //syntax
        // datatype *var_name;
        //datatype* var_name;

        int x = 70;
        int* ptr;
        // cout<<*ptr;//unpredictable-wild pointer
        ptr=nullptr;// can be checked
        // dangling Pointer
        int *dp = new int(50);
        int **pp = &dp;
        // cout << *pp<<"before delete "<< **pp <<endl;
        delete dp;
        dp=nullptr;
        // cout<< *dp <<" after delete " << dp<<endl;
        int c = 10;
        // int *i = &c;
        // int **ii = &i;
        // **ii = 100;
        // cout<< c;
        //void pointer
        // a void can store the address of an 
        // object of different types , but it does not
        //  carry the  pointed to tyoe info needed
        //  to normal dereferencing
    void *vp= &c;
    // cout << *vp;
    cout << *(static_cast<int*>(vp));
// "void* gives flexibility, but it also removes
//  type safety. Don't use it just because you can."

        ptr = &x;
        // cout<< "Address of x: "<<ptr<<endl;
        // cout<< "Value of x: "<<*ptr<<endl;

        // References 
        // 1. is an alias or alternative name for an existing variable
        //2.  once it is initialized refers to the same memory location 
        // as the original varaible
        // 3. allowing both names to access the same data.
        // 4. do not require dereferencing to access the 📈
        //5.  share original memory location as original variable
        //6.  cannot reassigned to refer to another variable
        //syntax
        //datatype& ref_name= variable;

        int y = 20;
        int& refe = y;
        refe -= 50;
        // cout<<y<<endl;
    // Pointer arithmetics
    int arr[5] = {10,20,30,50,60};
    int *p = arr;
    // cout << p <<endl;
    // cout<< p+1 <<endl;
    // write a p[rogram to print 
        // thw value of array using pointer]
    // arr  =arr+1; X
    for(int i=0;i<5;i++){
        *(p+i) = *(p+i) * 2;
        // cout << *(p+i) << " ";
    }
    // using pointer double every element of the array
// reverse an array using pointers
// void reverse(int *arr,int n)
// int l =0; right = n-1;
// while( left<right){
//     swap(arr[left],arr[right])
//     left++;
//     right--
// }
int z = 5;
int *r = &z;
*r = 15;
// cout << z;










    return 0;
}