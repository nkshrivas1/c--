/**
 * ==============================================================================================
 *                         CSE205: DATA STRUCTURES & ALGORITHMS (DSA)
 *                     UNIT 4: BINARY SEARCH TREE (BST) - GROUP 1
 * ==============================================================================================
 * 
 * TOPICS COVERED:
 * ----------------
 * 1. Introduction to Binary Search Trees (BST) & BST Invariant
 * 2. Node Structure for Binary Trees
 * 3. Step-by-Step BST Insertion (Iterative / Recursive)
 * 4. Building a BST from an Array of Keys
 * 5. Depth-First Tree Traversals:
 *    - Preorder Traversal  (Root -> Left -> Right)
 *    - Inorder Traversal   (Left -> Root -> Right) [CRITICAL: Yields Sorted Order]
 *    - Postorder Traversal (Left -> Right -> Root)
 * 6. Deletion in a BST (Handling all 3 Cases):
 *    - Case 1: Deleting a Leaf Node (0 children)
 *    - Case 2: Deleting a Node with One Child
 *    - Case 3: Deleting a Node with Two Children (Inorder Successor Replacement)
 * 7. Comprehensive Demonstration in main()
 * 
 * ==============================================================================================
 * THEORY & EXAM NOTES: BINARY SEARCH TREES
 * ==============================================================================================
 * 
 * 1. BST DEFINITION & INVARIANT:
 *    - A Binary Search Tree is a binary tree in which every node satisfies the BST Property:
 *        * All keys in the LEFT subtree are strictly LESS than the node's key.
 *        * All keys in the RIGHT subtree are strictly GREATER than the node's key.
 *        * Both the left and right subtrees must also be Binary Search Trees.
 *    - No duplicate keys are allowed (or handled via counter/frequency field).
 * 
 * 2. COMPLEXITY OF BST OPERATIONS:
 *    -------------------------------------------------------------------------------------------
 *    Operation     | Average Case (Balanced Tree)    | Worst Case (Skewed Tree)
 *    -------------------------------------------------------------------------------------------
 *    Search        | O(log N)                        | O(N)
 *    Insertion     | O(log N)                        | O(N)
 *    Deletion      | O(log N)                        | O(N)
 *    Traversals    | O(N)                            | O(N)
 *    -------------------------------------------------------------------------------------------
 * 
 * 3. TREE TRAVERSALS (DFS):
 *    - Preorder:   Root -> Left -> Right   (Useful for creating a copy/serialization of the tree)
 *    - Inorder:    Left -> Root -> Right   (MUST know: Visits nodes in ASCENDING SORTED ORDER)
 *    - Postorder:  Left -> Right -> Root   (Useful for tree deletion/freeing memory and postfix eval)
 * 
 * 4. DELETION ALGORITHM (3 CASES):
 *    - Case 1: Node has NO children (Leaf Node):
 *        Simply delete the node and return nullptr to the parent.
 *    - Case 2: Node has ONE child:
 *        Bypass the node by linking its parent directly to its child; delete the target node.
 *    - Case 3: Node has TWO children:
 *        Find the INORDER SUCCESSOR (the node with the smallest value in the RIGHT subtree).
 *        Copy the successor's data into the target node.
 *        Recursively delete the successor node from the right subtree.
 *        (Alternatively, the Inorder Predecessor from the left subtree can be used).
 * ==============================================================================================
 */

#include <iostream>
using namespace std;

// ==============================================================================================
// 1. NODE DEFINITION
// ==============================================================================================
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// ==============================================================================================
// 2. BST INSERTION (Iterative Approach)
// ==============================================================================================
/**
 * Inserts 'val' into the BST rooted at 'root'.
 * 
 * Trace for insertion of keys: 50, 30, 70, 20, 40, 60, 80, 35
 *   Step 1: Insert 50 -> root node
 *   Step 2: Insert 30 -> 30 < 50, go left -> attached as left child of 50
 *   Step 3: Insert 70 -> 70 > 50, go right -> attached as right child of 50
 *   Step 4: Insert 20 -> 20 < 50 (left), 20 < 30 (left) -> attached as left child of 30
 *   Step 5: Insert 40 -> 40 < 50 (left), 40 > 30 (right) -> attached as right child of 30
 *   Step 6: Insert 60 -> 60 > 50 (right), 60 < 70 (left) -> attached as left child of 70
 *   Step 7: Insert 80 -> 80 > 50 (right), 80 > 70 (right) -> attached as right child of 70
 *   Step 8: Insert 35 -> 35 < 50 (left), 35 > 30 (right), 35 < 40 (left) -> left child of 40
 */
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    Node* current = root;
    while (true) {
        if (val < current->data) {
            if (current->left == nullptr) {
                current->left = new Node(val);
                break;
            }
            current = current->left;
        } else if (val > current->data) {
            if (current->right == nullptr) {
                current->right = new Node(val);
                break;
            }
            current = current->right;
        } else {
            // Duplicate value: BST typically ignores duplicates
            break;
        }
    }
    return root;
}

// ==============================================================================================
// 3. BUILD BST FROM ARRAY
// ==============================================================================================
Node* buildBST(int arr[], int n) {
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// ==============================================================================================
// 4. TREE TRAVERSALS (DFS)
// ==============================================================================================

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right (Yields strictly ascending sorted order for BST)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// ==============================================================================================
// 5. DELETION IN BST (All 3 Cases Handled)
// ==============================================================================================
/**
 * Recursively searches and deletes the node with 'val' from the BST.
 * Returns the updated root pointer.
 */
Node* deleteNode(Node* root, int val) {
    if (root == nullptr) return nullptr; // Value not present in tree

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        // Target node found! (root->data == val)

        // CASE 1: Node with NO children (Leaf Node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // CASE 2: Node with ONE child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // CASE 3: Node with TWO children
        // Strategy: Replace node's value with its Inorder Successor
        // (the smallest node in the right subtree)
        Node* successor = root->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        // Copy successor data to current node
        root->data = successor->data;

        // Delete the successor node from the right subtree
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

// Helper to free all allocated memory
void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// ==============================================================================================
// 6. MAIN FUNCTION & DEMONSTRATION
// ==============================================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "          CSE205: BINARY SEARCH TREE (BST) DEMO          " << endl;
    cout << "=========================================================" << endl;

    // Keys to insert into BST
    int arr[] = {50, 30, 70, 20, 40, 60, 80, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Inserting keys into BST: ";
    for (int k = 0; k < n; k++) cout << arr[k] << " ";
    cout << endl;

    Node* root = buildBST(arr, n);

    // -------------------------------------------------------------------------
    // Traversals
    // -------------------------------------------------------------------------
    cout << "\n--- Depth-First Traversals ---" << endl;
    cout << "Preorder Traversal  (Root, Left, Right): ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal   (Left, Root, Right) : ";
    inorder(root);
    cout << " [Always Sorted!]" << endl;

    cout << "Postorder Traversal (Left, Right, Root) : ";
    postorder(root);
    cout << endl;

    // -------------------------------------------------------------------------
    // Demonstrating Deletion Cases
    // -------------------------------------------------------------------------
    cout << "\n--- Deletion Demonstrations ---" << endl;

    // Case 1: Deleting a Leaf Node (Node 20 has 0 children)
    cout << "1. Deleting Leaf Node (20):" << endl;
    root = deleteNode(root, 20);
    cout << "   Inorder after deleting 20: ";
    inorder(root);
    cout << endl;

    // Case 2: Deleting a Node with 1 Child (Node 40 now has only left child 35)
    cout << "\n2. Deleting Node with One Child (40):" << endl;
    root = deleteNode(root, 40);
    cout << "   Inorder after deleting 40: ";
    inorder(root);
    cout << endl;

    // Case 3: Deleting a Node with 2 Children (Node 50 is root with 2 children)
    cout << "\n3. Deleting Node with Two Children (50 - Root):" << endl;
    root = deleteNode(root, 50);
    cout << "   Inorder after deleting 50: ";
    inorder(root);
    cout << endl;

    // Free all remaining nodes
    freeTree(root);

    cout << "\n=========================================================" << endl;
    return 0;
}