#include <iostream>
using namespace std;

//create Node class with data and next pointer
struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
// write display funtion to print all elements of linked list
//create a class for circular linked list
class CircularLinkedList {
    Node* head;
    Node* tail;
public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    // write a program to traverse the circular linked list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head; // make it circular
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // maintain circularity
        }
    }
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head; // make it circular
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head; // maintain circularity
        }
    }
    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head == tail) head = tail = nullptr;
        else {
            head = head->next;
            tail->next = head; // maintain circularity
        }
        delete temp;
    }// write  a function to delete from end of circular linked list
    void deleteFromEnd() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            while (temp->next != tail) {        
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = head; // maintain circularity
        }
    }
    // write a function to delete a node with given value from circular linked list
    void deleteNode(int val) {
        if (head == nullptr) return;
        Node* temp = head;
        Node* prev = tail;
        do {
            if (temp->data == val) {
                if (temp == head) {
                    deleteFromBeginning();
                } else if (temp == tail) {
                    deleteFromEnd();
                } else {
                    prev->next = temp->next;
                    delete temp;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }
    void display() {
        if (head == nullptr) return;
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};