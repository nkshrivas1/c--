/**
 * ==============================================================================================
 *                         CSE205: DATA STRUCTURES & ALGORITHMS (DSA)
 *                          UNIT 4: TREE TERMINOLOGY & REPRESENTATIONS
 * ==============================================================================================
 * 
 * TOPICS COVERED:
 * ----------------
 * 1. Introduction to Non-Linear Data Structures: Trees & Binary Trees
 * 2. Tree Terminology & Mathematical Formulations:
 *    - Degree, Depth, Level, Height of Node, Height of Tree, Subtree
 * 3. Mathematical Properties of Binary Trees:
 *    - Max nodes at level l = 2^l
 *    - Max nodes in tree of height h = 2^(h+1) - 1
 *    - Min nodes in tree of height h = h + 1
 *    - Max leaves in tree of height h = 2^h
 * 4. Types of Binary Trees:
 *    - Full (Strict / Proper) Binary Tree
 *    - Complete Binary Tree
 *    - Perfect Binary Tree
 * 5. Binary Tree Representations:
 *    - Sequential (Array) Representation (Index formulas for 0-based indexing)
 *    - Linked (Pointer-based) Representation (Node class with left and right pointers)
 * 6. Viva Questions & Practice MCQ Concepts
 * 7. Comprehensive Demonstration in main()
 * 
 * ==============================================================================================
 * THEORY & EXAM NOTES: BINARY TREES
 * ==============================================================================================
 * 
 * 1. CORE TERMINOLOGY (0-BASED CONVENTION):
 *    - Root Node: The topmost node of the tree with no parent.
 *    - Edge: The connecting link between a parent node and a child node.
 *    - Leaf / Terminal Node: A node with no children (Degree = 0).
 *    - Internal / Non-Terminal Node: A node with at least one child.
 *    - Degree of a Node: The total number of children connected to that node.
 *    - Depth of a Node: Number of edges on the path from the root node to that node (Root depth = 0).
 *    - Level of a Node: Equal to depth (Root is at Level 0).
 *    - Height of a Node: Number of edges on the longest downward path from the node to a leaf.
 *    - Height of a Tree: Height of the root node (Edges from root to deepest leaf).
 *    - Subtree: A tree consisting of a node and all its descendants.
 * 
 * 2. MATHEMATICAL PROPERTIES (EXAM FORMULAS):
 *    -------------------------------------------------------------------------------------------
 *    Property                                         | Formula (Height = h, Level = l)
 *    -------------------------------------------------------------------------------------------
 *    1. Maximum nodes at level l                      | 2^l
 *       (e.g., Level 0: 1, Level 1: 2, Level 2: 4, Level 10: 1024)
 *    2. Maximum nodes in a binary tree of height h    | 2^(h + 1) - 1
 *       (e.g., Height 0: 1, Height 1: 3, Height 2: 7, Height 10: 2047)
 *    3. Minimum nodes in a binary tree of height h    | h + 1 (Degenerate / Skewed tree)
 *    4. Maximum leaves in a binary tree of height h   | 2^h
 *    5. Height of Complete Binary Tree with n nodes   | floor(log2(n))
 *    -------------------------------------------------------------------------------------------
 * 
 * 3. TYPES OF BINARY TREES:
 *    - Full Binary Tree (Strict / Proper):
 *        Every node has either 0 or 2 children. No node has only 1 child.
 *    - Complete Binary Tree:
 *        All levels are completely filled except possibly the last level, and on the last level,
 *        all nodes are aligned as far left as possible.
 *    - Perfect Binary Tree:
 *        All internal nodes have exactly 2 children and all leaf nodes are at the exact same level.
 * 
 * 4. TREE REPRESENTATION METHODS:
 *    -------------------------------------------------------------------------------------------
 *    Representation   | Structure Used          | Pros & Cons
 *    -------------------------------------------------------------------------------------------
 *    A. Sequential    | 1D Array (0-based)      | * Extremely compact for Complete Trees (no pointer overhead).
 *                     |                         | * Wastes massive memory for skewed / sparse trees.
 *    B. Linked        | Pointers (Node* left,   | * Dynamic sizing; flexible for any tree structure.
 *                     | Node* right)            | * Requires extra memory for two pointers per node.
 *    -------------------------------------------------------------------------------------------
 * 
 *    0-BASED ARRAY INDEXING RULES:
 *    For a node residing at array index i:
 *      * Left Child Index:   2 * i + 1
 *      * Right Child Index:  2 * i + 2
 *      * Parent Index:       (i - 1) / 2  (for i > 0)
 * ==============================================================================================
 */

#include <iostream>
using namespace std;

// ==============================================================================================
// 1. LINKED REPRESENTATION: NODE CLASS
// ==============================================================================================
/**
 * A binary tree node containing data and two self-referential child pointers.
 */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Parameterized constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to print linked binary tree (Inorder Traversal)
void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Helper function to clean up dynamically allocated memory
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// ==============================================================================================
// 2. MAIN FUNCTION & DEMONSTRATION
// ==============================================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "       CSE205: TREE TERMINOLOGY & REPRESENTATIONS        " << endl;
    cout << "=========================================================" << endl;

    // -------------------------------------------------------------------------
    // PART A: SEQUENTIAL (ARRAY) REPRESENTATION
    // -------------------------------------------------------------------------
    cout << "\n--- PART A: Sequential (Array) Representation ---" << endl;
    // Complete Binary Tree stored in level-order:
    //          10
    //        /    \
    //       20    30
    //      /  \   /  \
    //     40  50 60  70
    int tree[7] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;

    cout << "Array Contents (Level Order): ";
    for (int k = 0; k < n; k++) cout << tree[k] << " ";
    cout << "\n\nParent-Child Relationships calculated via formulas:" << endl;

    for (int i = 0; i < n; i++) {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        cout << "Index [" << i << "] (Value " << tree[i] << "): ";
        if (leftChildIndex < n) {
            cout << "Left Child -> " << tree[leftChildIndex] << " [idx " << leftChildIndex << "]  ";
        } else {
            cout << "Left Child -> None  ";
        }

        if (rightChildIndex < n) {
            cout << "Right Child -> " << tree[rightChildIndex] << " [idx " << rightChildIndex << "]";
        } else {
            cout << "Right Child -> None";
        }
        cout << endl;
    }

    // -------------------------------------------------------------------------
    // PART B: LINKED (POINTER-BASED) REPRESENTATION
    // -------------------------------------------------------------------------
    cout << "\n--- PART B: Linked (Pointer-Based) Representation ---" << endl;
    // Manually constructing a linked binary tree:
    //          5
    //        /   \
    //       4     6
    //      / \   / \
    //     2   3 4   2
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(2);

    cout << "Root node value: " << root->data << endl;
    cout << "Root->left value: " << root->left->data << ", Root->right value: " << root->right->data << endl;
    cout << "Inorder Traversal of Linked Tree: ";
    printInorder(root);
    cout << endl;

    // Clean up allocated nodes
    deleteTree(root);

    // -------------------------------------------------------------------------
    // PART C: CONCEPTUAL VIVA / EXAM QUESTIONS & ANSWERS
    // -------------------------------------------------------------------------
    cout << "\n--- PART C: Viva & Quiz Concept Review ---" << endl;
    cout << "Q1: What is the left-child index for a node at index 3 in 0-based indexing?" << endl;
    cout << "Ans: 2 * 3 + 1 = 7" << endl;

    cout << "\nQ2: Which representation uses child pointers?" << endl;
    cout << "Ans: Linked representation (stores left and right pointers in each node)" << endl;

    cout << "\nQ3: Which representation is especially convenient for Complete Binary Trees?" << endl;
    cout << "Ans: Sequential (Array) representation (preserves left-to-right filling without wasted gaps)" << endl;

    cout << "\nQ4: What does nullptr / NULL mean for a child pointer?" << endl;
    cout << "Ans: No child is connected at that branch (leaf or single child node)" << endl;

    cout << "\n=========================================================" << endl;
    return 0;
}
