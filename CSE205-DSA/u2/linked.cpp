#include<iostream>
using namespace std;
struct NodeStruc{
        int data;
        NodeStruc* next;
        NodeStruc(int d){
            data = d;
            next = nullptr;
        }
};

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = nullptr;
        }
};
void display(Node* head){
    Node* current = head;
    while(current != NULL){
        cout << current->data << " -> ";
        current = current->next;
    }
}
int getSize(Node* head){
    Node* current = head;
    int size=0;
    while(current != NULL){
        size++;
        current = current->next;
    }
    return size;
}
//write a function to find the size of linked list
int main(){
    // linked list is a linear ds used to store data in non -contigous memory locations
    // linked lists store elements dynamically in memory
    // each element is called a node
    // nodes are connecting using pointers
    // Data - > stores the actual value
    // next pointer: stores the address of next node
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    display(n1);
    // cout << n1->next->data << "->"<< n1->next->next<<endl;
    // create 4 nodes and print data of them after linking
    //we have to use first node for traversal only
    // write a function to create multiple nodes
    return 0;
}