
#include <iostream>
using namespace std;

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
int main(){
    // Node* root = new Node(5);
    // root->left = new Node(4);
    // root->right = new Node(6);
    // root->left->left = new Node(2);
    // root->left->right = new Node(3);
    // root->right->left = new Node(4);
    // root->right->right = new Node(2);
    int tree[7] = {10,20,30,40,50,60,70};
    int n= 7;
    // index formulas for zero based array representation of binary tree
    // left child index = 2*i + 1
    // right child index = 2*i + 2
    // parent index = (i-1)/2
    for(int i=0;i<n;i++){
        cout<<"Node: "<<tree[i]<<" ";
        int leftChildIndex = 2*i + 1;
        int rightChildIndex = 2*i + 2;
        if(leftChildIndex < n){
            cout<<"Left Child: "<<tree[leftChildIndex]<<" ";
        }
        if(rightChildIndex < n){
            cout<<"Right Child: "<<tree[rightChildIndex]<<" ";
        }
        cout<<endl;
    } //1. What is the left-child index for a node at index 3? -- 7
    //2. Which representation uses child pointers?
    // a) linked representation ans
    // b) sequential representation
    // c) both a and b
    // 3.Which representation is especially convenient 
    // for complete binary trees?
    // a) linked representation
    // b) sequential representation - correct
    // 4. What does nullptr mean for a child pointer?
    // a). The node contains zero
    // b). No child is connected
    // c). The tree is full
    

    //


    return 0;
}














// Degree of Node = Number of children of the node
// Depth of node = Number of edges from root to the node
// Level of node = depth,under our zero based indexing, level of root node = 0
// Height of node = Number of edges from the node to the deepest leaf node
// height of tree = height of root node
// subtree = tree formed by a node and all its descendants

// properties of binary tree
// 1. maximum number of nodes at level l = 2^l
// example: 
// level 0 = 2^0 = 1, 
// level 1 = 2^1 = 2, 
// level 2 = 2^2 = 4
// Q: maximum number of nodes at level 10
// A: 2^10 = 1024

//2. maximum number of nodes in a binary tree of height h = 2^(h+1) - 1
// Example:
// height 0 = 2^(0+1) - 1 = 1
// height 1 = 2^(1+1) - 1 = 3
// height 2 = 2^(2+1) - 1 = 7
// Q: maximum number of nodes in a binary tree of height 10
// A: 2^(10+1) - 1 = 2047
//3.Minimum number of nodes in a binary tree of height h = h + 1
//4. Maximum number of leaves in a binary tree of height h = 2^h
//5. Full binary tree = a binary tree in which every node
//   has either 0 or 2 children
//6. Complete binary tree = a binary tree in which every level,
//      except possibly the last,is completely filled, 
//      and all nodes are as far left as possible
// properties of complete binary tree
// 1.Complete binary tree is said to be proper binary tree where 
//all leaves have the same depth or same level
//2. in a complete binary tree with n nodes,  
// height of the tree is log(n)
//3. all the leveles are completely filled except possibly the last level

// representation of tree
// 1. Linked representation- stores the elements of the tree 
//          in a linked list
// 2. Sequential representation- stores the elements of the tree in an array

