


#include<iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node* prev;
        Node* next;
        // Node(int data){
        //     this->data=data;
        //     prev=nullptr;
        //     next=nullptr;
        // }
        Node(int data,Node* prev=nullptr,Node* next=nullptr){
            this->data = data;
            this->prev=prev;
             this->next = next;
        }
};

// create a clss DLL with head and tail for doubly linked list
//traversal,insertion,deletion
class DLL {
    private:
        Node* head;
        Node* tail;
    public:
        DLL() : head(nullptr),tail(nullptr) {}
        //1. insert at head (front)
        void insertAtHead(int val){
            Node* newNode = new Node(val,nullptr,head);
            if(head != nullptr){
                head->prev = newNode;
            }else{
                tail = newNode;
            }
            head = newNode;
        }
        // 2. insert at tail
         void insertAtTail(int val){
            Node* newNode = new Node(val,tail,nullptr);
            if(tail != nullptr){
                tail->next = newNode;
            }else{
                head = newNode;
            }
            tail = newNode;
        }
        // 3. delete head value from the lis

        void deleteFromHead(){
            if(head == nullptr) return;
            Node* temp = head;
            head = head->next;
            if(head != nullptr){
                head->prev = nullptr;
            }else{
                tail = nullptr;
            }
            delete temp;
        }

        //4. print forward using head
        //5. print backward using tail
        void printBackward(){
            Node* curr = tail;
            while(curr != nullptr){
                cout<<curr->data<<" ";
                curr = curr->prev;
            }
            cout << endl;
        }
        //create a node class with data and next for circlular linked list
        // write a program to delete middleNode of a doubly linked list
        void deleteMiddleNode(){
            Node* slow = head;
            Node* fast = head->next->next;
            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;    
            }
            Node* temp = slow->next;
            slow->next = temp->next;
            temp->next->prev = slow;
            delete temp;
        }
        //create a destructor
};

void display(Node* head,bool isReverse=false){
  // write a function to print all element of our linked list in both
// direction  
    if(head==NULL) return;
    if(isReverse){
        display(head->next,isReverse);
        cout<< head->data<<" ";
    }else{
        cout<< head->data<<" ";
        display(head->next,isReverse);
    }
}
int main(){
    /*
    A doubly linked list is a linked list in which each node 
    contains data,a pointer to the previous node,
     and a pointer to the next node.
     */
    // create 4 Nodes for our doubly linked list
    Node* node4 = new Node(40);
    Node* node3 = new Node(30,nullptr,node4);
    Node* node2 = new Node(20,nullptr,node3);
    Node* node1 = new Node(10,nullptr,node2);
//     Node* dummyForNode2 =new Node(0,nullptr,node3);
//     Node* node2 = new Node(20,nullptr,dummyForNode2);
//   Node* dummyForNode1 =new Node(0,nullptr,node2);
//     Node* node1 = new Node(100,nullptr,dummyForNode1);

    node2->prev = node1;
    node3->prev = node2;
    node4->prev = node3;
    display(node1);
    cout<<endl;
    display(node1,true);

//     delete dummyForNode1;
//     delete dummyForNode2;
// write a function to print all element of our linked list in both
// direction
    return 0;
}