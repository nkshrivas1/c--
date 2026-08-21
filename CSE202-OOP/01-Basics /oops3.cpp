#include<iostream>
using namespace std;

static int hidden_var =10;

// create a class name bank with attributes
// private account number, account holder name, balance
// and methods deposit, withdraw, displayBalance
// constructor - a special method that is
//  automatically called when an object of 
//  a class is created
class BankAccount{
    public:
        static int count;
    private:
        int accountNumber;
        string accountHolderName;
        double balance;
        
    public:
        //constructor overloading
        // multiple constructor with different parameters
        BankAccount(int accNum, string accountHolderName, double balance){
            accountNumber = accNum;
            this -> accountHolderName = accountHolderName;
            this -> balance = balance;
            count++;
        }
        // initializer list
        BankAccount(string a, double b)
        :accountHolderName(a),balance(b) {
            // random value for account number
            accountNumber =  rand() % 1000000;
            count++;
        }
        BankAccount(){
            accountNumber = 0;
            accountHolderName = "Unknown";
            balance = 0.0;
            count++;
        }
        //copy constructor - a special constructor
        //  that is used to create a new object 
            // as a copy of an existing object
        BankAccount(const BankAccount &other){
            accountNumber = other.accountNumber;
            accountHolderName = other.accountHolderName;
            balance = other.balance;
            count++;
        }
       static void totalAccounts(){
        cout << count << endl;
       }
        void displayAccountDetails(){
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder Name: " << accountHolderName << endl;
            cout << "Balance: $" << balance << endl;
        }
        // deposite methods 
        void deposit(double amount){
            balance += amount;
        }
        // withdraw methods
        void withdraw(double amount){
            if(amount > balance){
                cout << "Insufficient balance" << endl;
            } else {
                balance -= amount;
            }
        }
        // calculate interest method - year , rate
        double calculateInterest(int years, double rate){
            return balance * rate * years / 100;
        }
};
int BankAccount::count =0;
void counter(){
     static int count = 0;
     count++;
     cout<< " Count " << count << endl;
}
// counter() - count -1
// counter() - count - 2
// counter() - count - 3
// counter() - count -  4

int main() {
    BankAccount account(12345, "John Doe", 1000.0);
    account.displayAccountDetails();
    BankAccount account2("Jane Doe", 500.0);
    account2.displayAccountDetails();
    BankAccount account3;

    BankAccount account4 = account;
    account4.displayAccountDetails();
    account4.deposit(500.0);
    account4.withdraw(200.0);
    account4.displayAccountDetails();
    double interest = account4.calculateInterest(2, 5.0);
    cout << "Interest for 2 years at 5%: $" << interest << endl;
    BankAccount::totalAccounts();
    return 0;
}
// global static variable + methods - used by file only
// function static members
// class static variables + member functions
