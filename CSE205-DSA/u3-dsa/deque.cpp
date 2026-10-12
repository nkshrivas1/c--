#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Deque{
    private:
        Node* front;
        Node* rear;
    public:
        Deque(){
            front = nullptr;
            rear = nullptr;
        }
        // insert at front 
        void pushFront(int value){
            Node* newNode = new Node(value);
            if(front == nullptr){
                front = rear = newNode;
            }else{
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
        }
        //insert at rear
        void pushRear(int value){
            Node* newNode = new Node(value);

            if(rear == nullptr){
                front = rear = newNode;
            }else{
                newNode->prev = rear;
                rear->next = newNode;
                rear = newNode;
            }
        }

        //Delete from front
        void popFront(){
            if(front == nullptr){
                cout << "Deque is empty"<<endl;
                return;
            }
            Node* temp = front;
            front = front->next;
            if(front == nullptr) rear = nullptr;
            else front->prev = nullptr;
            delete temp;
        }
         //Delete from rear
        void popRear(){
            if(rear == nullptr){
                cout << "Deque is empty"<<endl;
                return;
            }
            Node* temp = rear;
            rear = rear->prev;
            if(rear == nullptr) front = nullptr;
            else rear->next = nullptr;
            delete temp;
        }
        //getfront
        //getRear
        //isEmpty
        //display
};