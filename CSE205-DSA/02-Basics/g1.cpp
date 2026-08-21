// Write a C++ program to input a number 
// and find the sum of first
// and last digit of the number using a for loop. 
#include<iostream>
using namespace std;
//Write a C++ program to input a number 
// from the user and calculate product of its digits. 
int product(int n) {
    int product = 1;
    while (n > 0) {
        product *= n % 10; // Multiply the last digit
        n /= 10; // Remove the last digit
    }
    return product;
}

// Write a C++ program to print 
// Fibonacci series up to n terms using loop. 
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
void fibbonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    cout << "Fibonacci Series: ";
    for(int i = 1; i <= n; ++i){
        cout << t1 << ", ";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    cout << endl;
}


int main() {
    int num, firstDigit, lastDigit, sum;
    cout << "Enter a number: ";
    cin >> num;

    lastDigit = num % 10; // Get the last digit

    // Find the first digit
    for (firstDigit = num; firstDigit >= 10; firstDigit /= 10);

    sum = firstDigit + lastDigit; // Calculate the sum of first and last digit

    cout << "The sum of the first and last digit is: " << sum << endl;
    fibbonacci(5);
    return 0;
}