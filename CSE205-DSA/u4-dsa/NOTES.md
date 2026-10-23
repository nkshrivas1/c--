# Unit 4: Recursion, Binary Trees & Binary Search Trees (BST)
## Comprehensive Student Study Notes (CSE205 - Data Structures & Algorithms)

---

## Syllabus Roadmap (Topics Covered Till Date)

```
Unit 4: Hierarchical Data Structures & Advanced Recursion
 ├── 1. Advanced Recursion Techniques
 │    ├── Recursive Anatomy: Base Condition & Call Stack Frames
 │    ├── Reverse Array Printing: O(N) Head / Tail Call
 │    ├── Alternating Front-to-Back Array Printing: [0, n-1, 1, n-2, ...]
 │    ├── In-Place Odd Integer Removal:
 │    │    ├── Group 1: Element Shifting (O(N^2) Time, O(1) Auxiliary Space)
 │    │    └── Group 2: Two-Pointer Swap (O(N) Time, O(1) Auxiliary Space)
 │    ├── Fibonacci Series Computation (1-based vs. 0-based recursive formulations)
 │    ├── Recursive Binary Search (Divide and Conquer, O(log N))
 │    └── Tower of Hanoi (3-Step Recursive Strategy, 2^n - 1 moves)
 ├── 2. Tree Data Structure Fundamentals
 │    ├── Terminology: Root, Edge, Leaf, Internal Node, Degree, Subtree
 │    ├── Metrics: Depth vs. Level (0-based convention), Height of Node vs. Height of Tree
 │    ├── Core Mathematical Properties & Formulas:
 │    │    ├── Max Nodes at Level l = 2^l
 │    │    ├── Max Nodes in Tree of Height h = 2^(h+1) - 1
 │    │    ├── Min Nodes in Tree of Height h = h + 1 (Skewed Tree)
 │    │    ├── Max Leaves in Tree of Height h = 2^h
 │    │    └── Height of Complete Binary Tree with N nodes = floor(log2(N))
 │    └── Tree Classifications: Full (Proper / Strict), Complete, and Perfect Trees
 ├── 3. Binary Tree Representations
 │    ├── Sequential (Array) Representation (0-based Indexing):
 │    │    ├── Left Child Index = 2*i + 1
 │    │    ├── Right Child Index = 2*i + 2
 │    │    └── Parent Index = floor((i - 1) / 2)
 │    └── Linked (Pointer-based) Representation (Node class with left and right pointers)
 └── 4. Binary Search Trees (BST)
      ├── BST Definition & The BST Ordering Invariant
      ├── Iterative & Recursive BST Insertion
      ├── Building a BST from Array of Keys
      ├── Depth-First Search (DFS) Traversals:
      │    ├── Preorder (Root -> Left -> Right) [Serialization / Cloning]
      │    ├── Inorder (Left -> Root -> Right) [Yields STRICTLY SORTED Order]
      │    └── Postorder (Left -> Right -> Root) [Memory Cleanup / Bottom-up]
      └── Deletion in BST (All 3 Standard Cases):
           ├── Case 1: Leaf Node Deletion (0 children)
           ├── Case 2: Single Child Deletion (Node bypass)
           └── Case 3: Two Children Deletion (Inorder Successor Replacement)
```

---

## 1. Advanced Recursion Techniques

### 1.1 Anatomy of a Recursive Function
Every well-formed recursive function requires:
1. **Base Case (Termination Condition)**: The boundary condition where the function stops calling itself and returns a direct result, preventing infinite recursion and **Stack Overflow**.
2. **Recursive Step (Inductive Hypothesis)**: The logic that divides the problem into one or more strictly smaller subproblems of the same nature.

### 1.2 Call Stack & Activation Records
- When a function calls itself, an **Activation Record (Stack Frame)** is pushed onto the system call stack storing local variables, function arguments, and the return address.
- When the base case is reached, frames unwind and pop in Last-In, First-Out (LIFO) order.
- The space complexity equals the maximum depth of the recursive call tree ($O(\text{depth})$).

### 1.3 Recursion Problem Comparison Matrix
| Algorithm | Problem Statement | Technique | Time | Call Stack Space |
| :--- | :--- | :--- | :--- | :--- |
| **Reverse Array Print** | Print array from index $n-1$ down to 0 | Tail/Head recursion | $O(N)$ | $O(N)$ |
| **Alternating Print** | Print: `arr[0], arr[n-1], arr[1], arr[n-2]...` | Two-Pointer (`i`, `j`) | $O(N)$ | $O(N)$ |
| **Remove Odds (Shift)** | Remove odd numbers without extra array | Left-shift on match | $O(N^2)$ | $O(N)$ |
| **Remove Odds (Swap)** | Remove odd numbers without extra array | Swap with right end (`j`) | $O(N)$ | $O(N)$ |
| **Fibonacci Number** | $F(n) = F(n-1) + F(n-2)$ | Naive binary branching | $O(2^N)$ | $O(N)$ |
| **Binary Search** | Find key in sorted array | Divide & Conquer ($N/2$) | $O(\log N)$ | $O(\log N)$ |
| **Tower of Hanoi** | Move $n$ disks between 3 pegs | Divide & Conquer | $O(2^N)$ | $O(N)$ |

### 1.4 Tower of Hanoi Breakdown
- **Rules**:
  1. Only 1 disk can be moved at a time.
  2. A larger disk can never sit on top of a smaller disk.
- **Recurrence**:
  $$T(n) = 2T(n-1) + 1 \implies T(n) = 2^n - 1 \text{ moves}$$
- **Algorithm (Move $n$ disks from Source $S$ to Destination $D$ using Helper $H$)**:
  1. Move top $n-1$ disks from $S \to H$ using $D$.
  2. Move disk $n$ directly from $S \to D$.
  3. Move $n-1$ disks from $H \to D$ using $S$.

---

## 2. Tree Data Structure Fundamentals

### 2.1 Terminology & Definitions (0-Based Convention)
- **Node**: A fundamental container storing data and references to other nodes.
- **Root**: The topmost node of the tree without any parent.
- **Edge**: The directed or undirected link connecting a parent node to a child node.
- **Leaf (Terminal) Node**: A node having **0 children** ($\text{degree} = 0$).
- **Internal (Non-terminal) Node**: A node with at least one child.
- **Degree of a Node**: Number of children attached to that node.
- **Depth of a Node**: Number of edges on the path from the root to the node. ($\text{Depth}(\text{root}) = 0$).
- **Level of a Node**: Equal to its depth under the 0-based convention ($\text{Level}(\text{root}) = 0$).
- **Height of a Node**: Number of edges on the longest downward path from the node to a leaf.
- **Height of a Tree**: Height of the root node (Edges from root to the deepest leaf).
- **Subtree**: A portion of a tree consisting of a node and all of its descendants.

### 2.2 Mathematical Formulas (Exam Essentials)
For a binary tree where height is $h$ and level is $l$ (0-based indexing):

| Property | Formula | Examples |
| :--- | :--- | :--- |
| **Max nodes at level $l$** | $2^l$ | Level 0: 1, Level 1: 2, Level 2: 4, Level 10: 1024 |
| **Max nodes in tree of height $h$** | $2^{h+1} - 1$ | Height 0: 1, Height 1: 3, Height 2: 7, Height 10: 2047 |
| **Min nodes in tree of height $h$** | $h + 1$ | Skewed binary tree (Degenerate tree) |
| **Max leaves in tree of height $h$** | $2^h$ | Height 0: 1, Height 1: 2, Height 2: 4, Height 3: 8 |
| **Height of Complete Tree ($N$ nodes)**| $\lfloor \log_2 N \rfloor$ | For $N = 7 \implies h = 2$; For $N = 100 \implies h = 6$ |

### 2.3 Types of Binary Trees
1. **Full (Strict / Proper) Binary Tree**:
   - Every node has **either 0 or 2 children**. No node has exactly 1 child.
2. **Complete Binary Tree**:
   - All levels are completely filled with nodes, except possibly the last level, and on the last level, all nodes are positioned **as far left as possible**.
   - Ideal for flat sequential (array) representations (e.g., binary heaps).
3. **Perfect Binary Tree**:
   - All interior nodes have 2 children, and all leaves are at the exact same level.
   - Total nodes: $N = 2^{h+1} - 1$.

---

## 3. Binary Tree Representations

### 3.1 Sequential (Array) Representation
Nodes are stored in level-order traversal inside a 1D array.

**0-Based Index Formulas**:
For a node located at array index $i$:
- **Left Child Index**:
  $$\text{Left}(i) = 2i + 1$$
- **Right Child Index**:
  $$\text{Right}(i) = 2i + 2$$
- **Parent Index**:
  $$\text{Parent}(i) = \left\lfloor \frac{i - 1}{2} \right\rfloor \quad (\text{for } i > 0)$$

**Evaluation**:
- *Advantage*: Direct $O(1)$ random access to children and parent without pointer storage overhead.
- *Disadvantage*: Wastes massive contiguous memory for unbalanced or skewed trees (empty positions must be padded with dummy/null markers).

### 3.2 Linked (Pointer-based) Representation
Each node is dynamically allocated as an independent object:
```cpp
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
```
- `nullptr` indicates that no child is connected at that branch.
- *Advantage*: Dynamically resizable, zero wasted memory for absent nodes.
- *Disadvantage*: Memory overhead of two pointers per node and non-contiguous cache layout.

---

## 4. Binary Search Trees (BST)

### 4.1 The BST Property (Ordering Invariant)
For every node $X$ in the tree:
- Every key in the **Left Subtree** is strictly **less than** $X\to\text{data}$.
  $$\forall u \in \text{LeftSubtree}(X): u\to\text{data} < X\to\text{data}$$
- Every key in the **Right Subtree** is strictly **greater than** $X\to\text{data}$.
  $$\forall v \in \text{RightSubtree}(X): v\to\text{data} > X\to\text{data}$$
- Both left and right subtrees must themselves be valid Binary Search Trees.

### 4.2 Depth-First Search (DFS) Traversals
```
          50
        /    \
       30    70
      /  \   /  \
     20  40 60  80
        /
       35
```

1. **Preorder Traversal (Root $\to$ Left $\to$ Right)**:
   - Order: `50 30 20 40 35 70 60 80`
   - Application: Used to create a clone or prefix serialization of the tree.
2. **Inorder Traversal (Left $\to$ Root $\to$ Right)**:
   - Order: `20 30 35 40 50 60 70 80`
   - **Crucial Rule**: Inorder traversal of any BST **ALWAYS yields the elements in strictly sorted ascending order**!
3. **Postorder Traversal (Left $\to$ Right $\to$ Root)**:
   - Order: `20 35 40 30 60 80 70 50`
   - Application: Used for bottom-up cleanup (deleting trees safely without dangling pointers) and mathematical expression evaluation.

### 4.3 Deletion in BST (The 3 Canonical Cases)
When deleting a node with value $K$:
- **Case 1: Node is a Leaf (0 Children)**:
  - Simply delete the node and return `nullptr` to the parent.
- **Case 2: Node has Exactly One Child**:
  - Bypass the node: link the parent directly to the single child of the deleted node, then free the deleted node.
- **Case 3: Node has Two Children**:
  - Find the **Inorder Successor** (the smallest value in the right subtree: leftmost node of `right`).
  - Copy the inorder successor's value into the target node.
  - Recursively call `deleteNode` on the right subtree to remove the duplicate successor node.
  - *(Alternatively, Inorder Predecessor: maximum value in left subtree can be used).*

---

## 5. Viva & Conceptual Interview Questions

| Question | Answer & Explanation |
| :--- | :--- |
| **Q1: What is the left child of index 3 in 0-based array?** | $2 \times 3 + 1 = 7$. |
| **Q2: Which tree representation is preferred for Complete Trees?** | **Sequential (Array)** representation because nodes fill contiguous array slots without holes. |
| **Q3: What traversal of a BST gives sorted output?** | **Inorder Traversal** (Left, Root, Right). |
| **Q4: What is the worst-case time complexity of BST Search?** | $O(N)$ when the tree degenerates into a skewed line (like a linked list). |
| **Q5: How many moves are required for 4-disk Tower of Hanoi?** | $2^4 - 1 = 15$ moves. |

---

## 6. Directory File Index & Compilation Guide

| Source File | Primary Topics Covered |
| :--- | :--- |
| `recursiong1.cpp` | Reverse print, alternating print, in-place shift odd removal, Fibonacci, Binary Search, Tower of Hanoi |
| `treeg2.cpp` | Group 2 recursion variants: $O(N)$ two-pointer swap odd removal, 0-indexed Fibonacci |
| `tree.cpp` | Tree terminology, mathematical formulas, array (0-based) and linked representation, viva MCQs |
| `BSTg1.cpp` | BST node insertion, array builder, DFS traversals (pre/in/post), all 3 deletion cases |

### Build & Run Commands:
```bash
# 1. Compile & run Recursion Group 1
clang++ -std=c++17 -Wall -Wextra recursiong1.cpp -o recursiong1 && ./recursiong1

# 2. Compile & run Recursion Group 2
clang++ -std=c++17 -Wall -Wextra treeg2.cpp -o treeg2 && ./treeg2

# 3. Compile & run Tree Terminology & Representations
clang++ -std=c++17 -Wall -Wextra tree.cpp -o tree && ./tree

# 4. Compile & run Binary Search Tree (BST)
clang++ -std=c++17 -Wall -Wextra BSTg1.cpp -o BSTg1 && ./BSTg1
```

