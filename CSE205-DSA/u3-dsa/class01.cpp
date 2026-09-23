//push 10
// push 20
// push 30
// push 40
//cout <<  pop 
//cout <<  pop 
//cout << peek
//cout << peek
// push 50
// push 60
// peek
//isEmpty
// full stack --
// capacity

/// create a class stack ,and implement it using array
class StackArray {
    int *arr;
    int top;
    int capacity;
public:
    StackArray(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }
    void push(int val) {
        if (top == capacity - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = val;
    }
    int pop() {
        if (top == -1) {    
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top--];
    }
    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;      
        }
        return arr[top];
    }
    //display all elements of our stack without removing it
        void display() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return;
            }
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
    };













// write a program to implement stack usin g vector
#include <iostream>
#include <vector>
using namespace std;    

class Stack {
    vector<int> v;
    int capacity;
public:
    Stack(int capacity) {
        this->capacity = capacity;
    }
    // implement push function to add element to stack
    void push(int val) {
        if (v.size() == capacity) {
            cout << "Stack is full" << endl;
            return;
        }
        v.push_back(val);
    }
    // implement pop function to remove element from stack
    int pop() {
        if (v.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int val = v.back();
        v.pop_back();
        return val;     
    }
    // implement peek function to return top element of stack
    int peek() {
        if (v.empty()) {
            cout << "Stack is empty" << endl;   
            return -1;
        }
        return v.back();
    }
    // implement isEmpty function to check if stack is empty
    bool isEmpty() {
        return v.empty();
    }
    // implement isFull function to check if stack is full
    bool isFull() { 
        return v.size() == capacity;
    }
    // implement size function to return size of stack
    int size() {    
        return v.size();
    }
    // implement capacity function to return capacity of stack
    int getCapacity() {
        return capacity;        
    }
};
int main(int argc, char *argv[]){
    Stack s(5);
    cout << s.peek() << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    // for(int i=0;i<s.size();i++){
    //     cout<<s.pop()<<" ";
    // }
    while(!s.isEmpty()){
        cout<<s.pop()<<" ";
    }
}