#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class queuell{
    Node* front;
    Node* rear;
    int size;
    public:
    queuell(){
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    void enqueue(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if(rear == nullptr){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void dequeue(){
        if(front == nullptr){
            cout << "Queue is empty" << endl;       
        return;
        }
        Node* temp = front;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        size--;
    }
    int peek(){
        if(front == nullptr){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        return size == 0;
    }
    void display(){
        if(front == nullptr){
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int getSize(){
        return size;
    }
};
int main(){
    queuell q;
    q.enqueue(10);      
    q.dequeue();
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    q.display();
    cout << "Front element: " << q.peek() << endl;
    return 0;
}   