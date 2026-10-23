#include<iostream>
using namespace std;

// Binary Search Tree 
// organizes data in a hierarchical structure
// each node has a value and two child nodes
// left child node has a value less than its parent node
// right child node has a value greater than its parent node
// allows for efficient searching, insertion, and deletion of values
// 50, 30 ,70,20,40 ,60 ,80

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
// 50,30,70,20,40,60,80,35

// step 1 : insert 50
// step 2: compare 30 with 50, 30 < 50, go left
// step 3: compare 70 with 50, 70 > 50, go right
// .
//.
// step 8: compare 35 with 40, 35 < 40, go left
// step 9: insert 35 as left child of 40    
Node* insert(Node* root,int val){
    if(root == NULL){
        return new Node(val);
    }
    Node* current = root;
    while(true){
        if(val < current->data){
            if(current->left == NULL){
                current->left = new Node(val);
                break;
            }
            current = current->left;
        }
        else{
            if(current->right == NULL){
                current->right = new Node(val);
                break;
            }
                current = current->right;
        }
    }
    return root;
}
//Build a BST from an array of integers
Node* buildBST(int arr[],int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
        root = insert(root,arr[i]);
    }
    return root;
}
// preorder traversal of BST
void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
// inorder traversal of BST
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);   
}
// postorder traversal of BST
void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
//deletion of a node in BST
Node* deleteNode(Node* root,int val){
    if(root == NULL) return root;
    if(val < root->data){
        root->left = deleteNode(root->left,val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right,val);
    }
    else{
        // Node with only one child or no child
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}
int main(){
    int arr[] = {50,30,70,20,40,60,80,35};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = buildBST(arr,n);
    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder traversal: ";
    postorder(root);
    cout<<endl;
    return 0;
}