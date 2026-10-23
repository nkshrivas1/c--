# Unit 4: Graph Algorithms, Network Optimization & Greedy Techniques
## Comprehensive Student Study Notes (DAA / DSA)

---

## Syllabus Roadmap

```
Unit 4
 ├── 1. Graph Algorithms and Network Optimization
 │    ├── Introduction to Graphs (V, E, Types, Handshaking Lemma)
 │    ├── Graph Representations (Adjacency Matrix vs. Adjacency List)
 │    ├── Breadth-First Search (BFS)
 │    ├── Depth-First Search (DFS)
 │    └── Topological Sort (DFS Stack & Kahn's Algorithm)
 ├── 2. Greedy Technique
 │    ├── Introduction to Greedy Approach (Greedy Choice, Optimal Substructure)
 │    ├── Fractional Knapsack Problem (Ratio Strategy vs. 0/1 Knapsack)
 │    ├── Minimum Spanning Trees (MST, Cut Property)
 │    ├── Prim’s Algorithm (Vertex-Centric, Min-Heap)
 │    └── Kruskal’s Algorithm (Edge-Centric, Disjoint Set Union)
 └── 3. Shortest Path Algorithms
      ├── Single-Source Shortest Paths (Dijkstra's & Bellman-Ford)
      └── All-Pairs Shortest Paths (Floyd-Warshall)
```

---

## 1. Graph Fundamentals & Network Optimization

### Mathematical Formulations
- **Graph Definition**: $G = (V, E)$
- **Handshaking Lemma**:
  $$\sum_{v \in V} \text{deg}(v) = 2|E|$$
  - *Corollary*: The number of vertices with an **odd degree** is always **EVEN**.
- **Maximum Edges in Simple Graphs**:
  - Undirected: $\frac{V(V - 1)}{2} = O(V^2)$
  - Directed: $V(V - 1) = O(V^2)$

### Representations Comparison Table
| Feature | Adjacency Matrix | Adjacency List |
| :--- | :--- | :--- |
| **Space** | $O(V^2)$ | $O(V + E)$ |
| **Check Edge $(u, v)$** | $O(1)$ | $O(\text{deg}(u))$ |
| **Find All Neighbors** | $O(V)$ | $O(\text{deg}(u))$ |
| **Add Edge** | $O(1)$ | $O(1)$ |
| **Ideal Usage** | Dense graphs ($E \approx V^2$) | Sparse graphs ($E \ll V^2$) |

---

## 2. Graph Traversals & Topological Sort

### Breadth-First Search (BFS)
- **Data Structure**: `std::queue` (FIFO)
- **Time**: $O(V + E)$ | **Space**: $O(V)$
- **Steps**:
  1. Push starting vertex into queue, mark visited.
  2. While queue is not empty: pop front $u$, add to result.
  3. For every unvisited neighbor $v$: mark visited and push into queue.
- **Application**: Guaranteed shortest path in unweighted networks.

### Depth-First Search (DFS)
- **Data Structure**: System Call Stack (Recursion)
- **Time**: $O(V + E)$ | **Space**: $O(V)$
- **Steps**:
  1. Mark current vertex $u$ as visited.
  2. For each unvisited neighbor $v$: recursively call `DFS(v)`.
- **Application**: Cycle detection, connected components, maze solving.

### Topological Sort (DAGs Only)
Linear ordering where for every directed edge $u \to v$, $u$ appears before $v$.
- **Method 1 (DFS + Stack)**:
  - Run DFS; push $u$ to stack **after** all its outgoing paths are explored (post-order).
  - Pop stack to get topological order.
- **Method 2 (Kahn's Algorithm - BFS via In-Degrees)**:
  - Calculate in-degree for all vertices.
  - Enqueue all nodes with `inDegree == 0`.
  - Pop $u$, decrement neighbors' in-degree. When neighbor's in-degree hits 0, enqueue it.
  - If output count $< V$, **a cycle exists**!

---

## 3. Greedy Technique

### Introduction & Foundations
- **Core Strategy**: At each step, make the locally optimal choice that looks best at the moment, without backtracking.
- **Two Essential Conditions for Greedy**:
  1. **Greedy-Choice Property**: Globally optimal solution can be reached by making a locally optimal choice.
  2. **Optimal Substructure**: An optimal solution to the problem contains optimal solutions to subproblems.

### Greedy vs. Dynamic Programming
| Feature | Greedy Approach | Dynamic Programming |
| :--- | :--- | :--- |
| **Choice** | Commits to local optimum greedily | Evaluates all subproblems before deciding |
| **Backtracking** | Never backtracks | Solves overlapping subproblems via tables |
| **Subproblem Dependency**| Solves top-down one by one | Solves bottom-up or memoized |
| **Knapsack Problem** | Works for **Fractional Knapsack** | Required for **0/1 Knapsack** |

### Fractional Knapsack Problem
- **Greedy Strategy**: Calculate ratio $r_i = \frac{\text{value}_i}{\text{weight}_i}$. Sort descending by ratio.
- **Steps**:
  1. Sort items by ratio descending.
  2. For each item:
     - If knapsack capacity $\ge$ item weight: take 100% of the item.
     - Else: take fraction $\frac{\text{remainingCapacity}}{\text{item.weight}}$, fill knapsack, and stop.
- **Time**: $O(N \log N)$ | **Space**: $O(1)$ auxiliary.

---

## 4. Minimum Spanning Trees (MST)

For an undirected, connected, weighted graph $G = (V, E)$, an MST connects all $V$ vertices using exactly $V - 1$ edges with minimum total weight.

### Cut Property
For any cut (partition) of vertices into sets $S$ and $V - S$, the lightest edge crossing the cut must belong to the MST.

### Prim’s vs. Kruskal’s Algorithm
| Feature | Kruskal's Algorithm | Prim's Algorithm |
| :--- | :--- | :--- |
| **Approach** | **Edge-centric** (sorts edges) | **Vertex-centric** (grows a tree) |
| **Core Structure** | Disjoint Set Union (DSU / Union-Find) | Min-Heap Priority Queue |
| **Time Complexity**| $O(E \log E)$ or $O(E \log V)$ | $O((V + E) \log V)$ |
| **Best Suited For**| **Sparse Graphs** ($E \ll V^2$) | **Dense Graphs** ($E \approx V^2$) |

---

## 5. Shortest Path Algorithms

### Comparison Matrix
| Algorithm | Scope | Edge Weights | Strategy | Negative Cycle Detection | Time | Space |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Dijkstra** | Single-Source | Non-negative ($w \ge 0$) | Greedy (Min-Heap) | ❌ Cannot handle | $O((V+E)\log V)$ | $O(V)$ |
| **Bellman-Ford**| Single-Source | Any (Negative allowed) | Dynamic Programming |  Detects & reports | $O(V \cdot E)$ | $O(V)$ |
| **Floyd-Warshall**| All-Pairs | Any (No negative cycles)| Dynamic Programming |  Detects ($D[i][i] < 0$)| $O(V^3)$ | $O(V^2)$ |

### Floyd-Warshall DP Recurrence
For intermediate vertex $k \in \{0, \dots, V-1\}$:
$$D^{(k)}[i][j] = \min\left(D^{(k-1)}[i][j],\; D^{(k-1)}[i][k] + D^{(k-1)}[k][j]\right)$$

---

## 6. Compile & Run

```bash
clang++ -std=c++17 -Wall -Wextra graph.cpp -o graph
./graph
```
