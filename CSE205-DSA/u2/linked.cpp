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


// void display(Node* head){
//     Node* current = head;
//     while(current != NULL){
//         cout << current->data << " -> ";
//         current = current->next;
//     }
// }
// int getSize(Node* head){
//     Node* current = head;
//     int size=0;
//     while(current != NULL){
//         size++;
//         current = current->next;
//     }
//     return size;
// }
class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = nullptr;
        }
};
class LL{
    Node* head;
    Node* tail;
    public:
        LL(){
            head = NULL;
            tail = NULL;
        }
        // create a function to insert at beginning
        void insertAtBeginning(int x){
            //1. create a new node
            Node* newNode = new Node(x);
            //2. head == null
                // head=tail=newNode
                if(head == NULL){
                    head = tail = newNode;
                    return;
                }
                else{
                    newNode->next = head;
                    head = newNode;
                }
        }
        void insertAtEnd(int val){
             Node* newNode = new Node(val);
                 if(head == NULL){
                    head = tail = newNode;
                    return;
                }
                else{
                    tail->next = newNode;
                     tail = newNode;
                }      
        }
        void insertAtKPosition(int val,int k){
            //list is null
            // k is greater than size
            if(k<=0){
                cout << "Invalid Position" << endl;
                return;
            }  
            Node* temp = head;
            Node* newNode = new Node(val);
            if(k == 1){
                newNode->next = head;
                head = newNode;
                return;
            }
            int c=0;
            while(temp != NULL && c< k-1){
                temp = temp->next;
                c++;
            }
            if(temp == NULL){
                cout << "Invalid Position" << endl;
                return;
            }
            Node* curr = temp->next;
            temp->next = newNode;
            newNode->next = curr;
        }
        void popFront(){
            if(head == NULL) return;
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        void popBack(){
            //case 1: Empty list
            if(head== NULL) return;
            if(head->next == NULL){
                delete head;
                head = NULL;
                return;
            }//find target element 20 in given linklist
            Node* temp = head;
            //temp.next.next != null
            while(temp->next->next != NULL){
                temp=temp->next;
            }
            tail = temp;
            delete temp->next;
            temp->next = nullptr;
        }
        // find an element in linklist 
        // 1.findbyvalue 2.findbyposition
        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout<<endl;
        }
        int find(int target){
            Node* temp = head;
            int k=0;
            while(temp!=NULL){
                if(temp->data==target) return k;
                k++;
                temp = temp->next;
            }
            return -1;
        }
        int findAtPos(int k){
            Node* temp= head;
            for(int i=0; i<k && temp->next!=nullptr;i++){
                temp = temp->next;
            }
            return temp->data;
        }// write a funtion to reverse a link list
        int size(){
            Node* temp = head;
            int length=0;
            while(temp!=NULL){
                length++;
                temp = temp->next;
            }
            return length;
        }
        void reverseList(){
            Node* curr = head, *prev = nullptr, *next;
            while(curr!=NULL){
                    // store next
                    next = curr->next;
                    //reverse current next pointer
                    curr->next = prev;
                    prev = curr;
                    curr= next;
            }
        }
};
//write a function to find the size of linked list
int main(){
    // linked list is a linear ds used to store data in non -contigous memory locations
    // linked lists store elements dynamically in memory
    // each element is called a node
    // nodes are connecting using pointers
    // Data - > stores the actual value
    // next pointer: stores the address of next node
    LL list;
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(0);
    // list.display();
    list.insertAtKPosition(1,80);
    // list.display();
    cout<<endl;
    // list.popFront();
    list.display();
    cout << list.findAtPos(1)<<endl;
    // Node* n1 = new Node(10);
    // Node* n2 = new Node(20);
    // Node* n3 = new Node(30);
    // Node* n4 = new Node(40);
    // // (*n1).next = n2;
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // // display(n1);
    // cout << n1->next->data << "->"<< n1->next->next->data<<endl;
    // // create 4 nodes and print data of them after linking
    //we have to use first node for traversal only
    // write a function to create multiple nodes
    return 0;
}