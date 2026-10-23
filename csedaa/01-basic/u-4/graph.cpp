/**
 * ==============================================================================================
 *                UNIT 4: GRAPH ALGORITHMS, NETWORK OPTIMIZATION & GREEDY TECHNIQUES
 *                               Comprehensive Course Notes & Code
 * ==============================================================================================
 * 
 * SYLLABUS COVERAGE:
 * -------------------
 * PART 1: GRAPH ALGORITHMS & NETWORK OPTIMIZATION
 *   1. Introduction to Graphs (Definitions, Representations, Handshaking Lemma)
 *   2. Breadth-First Search (BFS) Traversal
 *   3. Depth-First Search (DFS) Traversal
 *   4. Topological Sort (DFS Stack & Kahn's BFS Algorithm)
 * 
 * PART 2: GREEDY TECHNIQUE
 *   5. Introduction to Greedy Approach (Greedy Choice Property, Optimal Substructure)
 *   6. Fractional Knapsack Problem (Greedy by Value-to-Weight Ratio)
 *   7. Minimum Spanning Trees (MST Theory, Cut & Cycle Properties)
 *   8. Prim’s Algorithm (Vertex-Centric Greedy via Min-Heap)
 *   9. Kruskal’s Algorithm (Edge-Centric Greedy via Disjoint Set Union)
 * 
 * PART 3: SHORTEST PATH ALGORITHMS
 *   10. Single-Source Shortest Paths (SSSP):
 *       - Dijkstra’s Algorithm (Greedy, Non-Negative Weights)
 *       - Bellman-Ford Algorithm (Dynamic Programming, Negative Weights & Cycle Detection)
 *   11. All-Pairs Shortest Paths (APSP):
 *       - Floyd-Warshall Algorithm (Dynamic Programming, O(V^3))
 * 
 * ==============================================================================================
 * 1. THEORY & EXAM NOTES: GRAPH FUNDAMENTALS
 * ==============================================================================================
 * - A Graph G = (V, E) consists of:
 *     * V: A finite set of vertices (nodes).
 *     * E: A set of edges (links connecting pairs of vertices).
 * 
 * - HANDSHAKING LEMMA (Standard Exam Theorem):
 *     In any undirected graph:
 *         Sum of degrees of all vertices = 2 * (Number of edges)
 *         Σ deg(v) = 2 * |E|
 *     Corollary: In any undirected graph, the number of vertices with odd degree is always EVEN.
 * 
 * - MAXIMUM NUMBER OF EDGES:
 *     * Simple Undirected Graph: V * (V - 1) / 2 = O(V^2)
 *     * Simple Directed Graph:   V * (V - 1)     = O(V^2)
 * 
 * - REPRESENTATION COMPARISON:
 *     * Adjacency Matrix: 2D array V x V. Space O(V^2). Edge lookup O(1). Best for dense graphs.
 *     * Adjacency List: Array of lists of size V. Space O(V + E). Edge lookup O(deg(u)). Best for sparse graphs.
 * 
 * ==============================================================================================
 * 2. THEORY & EXAM NOTES: GREEDY TECHNIQUE
 * ==============================================================================================
 * - What is a Greedy Algorithm?
 *     An algorithmic paradigm that builds up a solution piece by piece, always choosing the 
 *     next piece that offers the most immediate (locally optimal) benefit, hoping it leads 
 *     to a globally optimal solution.
 * 
 * - TWO ESSENTIAL PROPERTIES FOR GREEDY TO WORK:
 *     1. Greedy-Choice Property:
 *        A global optimum can be arrived at by selecting a local optimum without reconsidering earlier choices.
 *     2. Optimal Substructure:
 *        An optimal solution to the problem contains optimal solutions to subproblems.
 * 
 * - GREEDY VS. DYNAMIC PROGRAMMING (Comparison Table):
 *     Property                 | Greedy Technique              | Dynamic Programming
 *     -------------------------|-------------------------------|-----------------------------
 *     Choice Decision          | Locally optimal choice made   | Evaluates all subproblems
 *                              | at each step without revision | before committing
 *     Backtracking             | Never backtracks              | Reconsiders via memoization/tables
 *     Optimality Guarantee     | Only if greedy choice property| Guaranteed if optimal substructure
 *                              | holds (e.g., Fractional Knap) | holds (e.g., 0/1 Knapsack)
 *     Efficiency               | Usually faster O(N log N)     | Usually polynomial O(N * W), pseudo-poly
 * 
 * ==============================================================================================
 * 3. THEORY & EXAM NOTES: SHORTEST PATHS COMPARISON
 * ==============================================================================================
 * Algorithm          | Type            | Edge Weights             | Time Complexity | Space
 * -------------------|-----------------|--------------------------|-----------------|--------
 * BFS                | Single-Source   | Unweighted (Unit weight) | O(V + E)        | O(V)
 * Dijkstra           | Single-Source   | Non-negative only (w>=0) | O((V + E) log V)| O(V)
 * Bellman-Ford       | Single-Source   | Any (Negative allowed)   | O(V * E)        | O(V)
 * Floyd-Warshall     | All-Pairs       | Any (Detects neg cycles) | O(V^3)          | O(V^2)
 * ==============================================================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <string>

using namespace std;

const int INF = 1e8; // Infinity representation for shortest path problems

// ==============================================================================================
// PART 1: GRAPH REPRESENTATIONS
// ==============================================================================================

/**
 * Creates an Adjacency Matrix representation.
 */
vector<vector<int>> createAdjacencyMatrix(int V, const vector<pair<int, int>>& edges, bool isDirected = false) {
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        matrix[u][v] = 1;
        if (!isDirected) matrix[v][u] = 1;
    }
    return matrix;
}

void printAdjacencyMatrix(const vector<vector<int>>& matrix) {
    int V = matrix.size();
    cout << "\n--- Adjacency Matrix (" << V << " x " << V << ") ---\n   ";
    for (int j = 0; j < V; j++) cout << j << " ";
    cout << "\n  " << string(2 * V + 1, '-') << "\n";
    for (int i = 0; i < V; i++) {
        cout << i << "| ";
        for (int j = 0; j < V; j++) cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

/**
 * Creates an Adjacency List representation.
 */
vector<vector<int>> createAdjacencyList(int V, const vector<pair<int, int>>& edges, bool isDirected = false) {
    vector<vector<int>> adj(V);
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        if (!isDirected) adj[v].push_back(u);
    }
    return adj;
}

void printAdjacencyList(const vector<vector<int>>& adj) {
    cout << "\n--- Adjacency List ---\n";
    for (size_t i = 0; i < adj.size(); i++) {
        cout << "Vertex [" << i << "] -> ";
        if (adj[i].empty()) {
            cout << "None";
        } else {
            for (size_t j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << (j + 1 < adj[i].size() ? " -> " : "");
            }
        }
        cout << "\n";
    }
}


// ==============================================================================================
// PART 2: GRAPH TRAVERSALS (BFS & DFS)
// ==============================================================================================

/**
 * ALGORITHM: BREADTH-FIRST SEARCH (BFS)
 * -------------------------------------
 * Intuition: Explores vertices level-by-level using a FIFO Queue.
 * 
 * SUMMARIZED STEPS:
 * 1. Initialize `visited` array to false and create an empty `queue`.
 * 2. Push `startNode`, mark `visited[startNode] = true`.
 * 3. While queue is not empty:
 *      a. Dequeue vertex `u`, record in traversal.
 *      b. For each neighbor `v` of `u`:
 *          If `v` is unvisited: mark `visited[v] = true` and enqueue `v`.
 * 4. Return traversal order.
 * 
 * Time: O(V + E) | Space: O(V)
 */
vector<int> bfs(int V, const vector<vector<int>>& adj, int startNode) {
    vector<bool> visited(V, false);
    vector<int> traversalOrder;
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        traversalOrder.push_back(u);

        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return traversalOrder;
}

/**
 * ALGORITHM: DEPTH-FIRST SEARCH (DFS)
 * -----------------------------------
 * Intuition: Plunges deep down each branch, backtracks using System Call Stack (Recursion).
 * 
 * SUMMARIZED STEPS:
 * 1. Mark current node `u` as visited: `visited[u] = true`.
 * 2. Record / process `u`.
 * 3. For each neighbor `v` of `u`:
 *      If `v` is unvisited, recursively invoke DFS on `v`.
 * 4. Return traversal order.
 * 
 * Time: O(V + E) | Space: O(V)
 */
void dfsRecursive(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& traversalOrder) {
    visited[u] = true;
    traversalOrder.push_back(u);

    for (int neighbor : adj[u]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited, traversalOrder);
        }
    }
}

vector<int> dfs(int V, const vector<vector<int>>& adj, int startNode) {
    vector<bool> visited(V, false);
    vector<int> traversalOrder;
    dfsRecursive(startNode, adj, visited, traversalOrder);
    return traversalOrder;
}


// ==============================================================================================
// PART 3: TOPOLOGICAL SORT (For DAGs)
// ==============================================================================================
/**
 * DEFINITION:
 * Linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every 
 * directed edge u -> v, vertex u appears before vertex v.
 * 
 * METHOD 1: DFS-BASED (POST-ORDER STACK)
 * SUMMARIZED STEPS:
 * 1. For each unvisited vertex, run DFS.
 * 2. In DFS: recursively visit all unvisited neighbors.
 * 3. After visiting all descendants (post-order), push current vertex to stack.
 * 4. Pop all elements from stack to get topological order.
 * 
 * Time: O(V + E) | Space: O(V)
 */
void dfsTopoHelper(int u, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int neighbor : adj[u]) {
        if (!visited[neighbor]) {
            dfsTopoHelper(neighbor, adj, visited, st);
        }
    }
    st.push(u); // Push only after all descendants are processed
}

vector<int> topologicalSortDFS(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsTopoHelper(i, adj, visited, st);
        }
    }

    vector<int> topoOrder;
    while (!st.empty()) {
        topoOrder.push_back(st.top());
        st.pop();
    }
    return topoOrder;
}

/**
 * METHOD 2: KAHN'S ALGORITHM (BFS USING IN-DEGREES)
 * SUMMARIZED STEPS:
 * 1. Compute in-degree for every vertex.
 * 2. Push vertices with in-degree 0 into a queue.
 * 3. While queue is not empty:
 *      a. Dequeue vertex `u`, append to `topoOrder`.
 *      b. For each neighbor `v` of `u`: decrement `inDegree[v]`.
 *         If `inDegree[v] == 0`, enqueue `v`.
 * 4. If `topoOrder.size() < V`, graph contains a cycle!
 * 
 * Time: O(V + E) | Space: O(V)
 */
vector<int> topologicalSortKahn(int V, const vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int neighbor : adj[u]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) q.push(neighbor);
        }
    }

    if ((int)topoOrder.size() != V) {
        cout << "[Notice]: Cycle detected in directed graph! Topological sort does not exist.\n";
        return {};
    }
    return topoOrder;
}


// ==============================================================================================
// PART 4: GREEDY TECHNIQUE - FRACTIONAL KNAPSACK PROBLEM
// ==============================================================================================
/**
 * ----------------------------------------------------------------------------------------------
 * PROBLEM: FRACTIONAL KNAPSACK PROBLEM
 * ----------------------------------------------------------------------------------------------
 * Given weights and values of N items, we need to put these items in a knapsack of capacity W 
 * to get the MAXIMUM total value in the knapsack.
 * In Fractional Knapsack, items CAN be broken into smaller fractions (unlike 0/1 Knapsack).
 * 
 * GREEDY STRATEGY:
 * Calculate the value-to-weight ratio (value / weight) for every item.
 * Greedily pick items with the HIGHEST ratio first!
 * 
 * SUMMARIZED STEPS:
 * 1. Calculate ratio = value / weight for each item.
 * 2. Sort all items in descending order of ratio.
 * 3. Initialize `totalValue = 0.0` and `remainingCapacity = W`.
 * 4. Iterate through sorted items:
 *      a. If `item.weight <= remainingCapacity`:
 *            Take the entire item:
 *            `totalValue += item.value`
 *            `remainingCapacity -= item.weight`
 *      b. Else:
 *            Take a fraction of the item:
 *            `fraction = remainingCapacity / item.weight`
 *            `totalValue += item.value * fraction`
 *            `remainingCapacity = 0`
 *            Break (knapsack is full).
 * 5. Return `totalValue`.
 * 
 * CRUCIAL EXAM NOTE:
 * Why does Greedy work for Fractional Knapsack but FAILS for 0/1 Knapsack?
 * - In Fractional Knapsack, the knapsack can always be completely filled by taking a fraction 
 *   of the most valuable item per unit weight (Greedy Choice Property holds).
 * - In 0/1 Knapsack, taking the highest ratio item might leave empty space that cannot be filled, 
 *   leading to suboptimal total value (Greedy Choice Property fails; requires Dynamic Programming).
 * 
 * Time Complexity:  O(N log N) [Due to sorting items by ratio]
 * Space Complexity: O(1) auxiliary
 */
struct KnapsackItem {
    int id;
    double value;
    double weight;
};

// Comparator to sort items by value-to-weight ratio in descending order
bool compareKnapsack(const KnapsackItem& a, const KnapsackItem& b) {
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(double capacity, vector<KnapsackItem>& items) {
    // Step 1 & 2: Sort items by descending ratio
    sort(items.begin(), items.end(), compareKnapsack);

    double totalValue = 0.0;
    double remainingCapacity = capacity;

    cout << "\n--- Fractional Knapsack Item Selection Log ---\n";
    cout << "Item ID | Value | Weight | Ratio (v/w) | Taken Fraction | Value Added\n";
    cout << "---------------------------------------------------------------------\n";

    for (const auto& item : items) {
        if (remainingCapacity <= 0) break;

        if (item.weight <= remainingCapacity) {
            // Take 100% of the item
            totalValue += item.value;
            remainingCapacity -= item.weight;
            cout << setw(7) << item.id << " | "
                 << setw(5) << item.value << " | "
                 << setw(6) << item.weight << " | "
                 << setw(11) << fixed << setprecision(2) << (item.value / item.weight) << " | "
                 << setw(14) << "100% (Full)" << " | "
                 << setw(10) << item.value << "\n";
        } else {
            // Take fractional part
            double fraction = remainingCapacity / item.weight;
            double valueAdded = item.value * fraction;
            totalValue += valueAdded;
            cout << setw(7) << item.id << " | "
                 << setw(5) << item.value << " | "
                 << setw(6) << item.weight << " | "
                 << setw(11) << fixed << setprecision(2) << (item.value / item.weight) << " | "
                 << setw(13) << (fraction * 100.0) << "%" << " | "
                 << setw(10) << valueAdded << "\n";
            remainingCapacity = 0; // Knapsack full
            break;
        }
    }
    return totalValue;
}


// ==============================================================================================
// PART 5: MINIMUM SPANNING TREES (MST) - PRIM'S & KRUSKAL'S ALGORITHMS
// ==============================================================================================
/**
 * ----------------------------------------------------------------------------------------------
 * WHAT IS A MINIMUM SPANNING TREE (MST)?
 *   For a connected, undirected, weighted graph:
 *   - A Spanning Tree connects all V vertices using exactly (V - 1) edges with NO cycles.
 *   - A Minimum Spanning Tree (MST) minimizes the sum of all chosen edge weights.
 * 
 * CUT PROPERTY OF MST:
 *   For any cut (partition of vertices into two sets S and V-S), the minimum weight edge 
 *   crossing the cut belongs to the MST.
 * 
 * ----------------------------------------------------------------------------------------------
 * KRUSKAL'S ALGORITHM (EDGE-CENTRIC GREEDY USING DISJOINT SET UNION - DSU)
 * ----------------------------------------------------------------------------------------------
 * SUMMARIZED STEPS:
 * 1. Sort all edges in non-decreasing order of weights.
 * 2. Initialize DSU (each vertex is its own parent).
 * 3. For each edge (u, v, weight) in sorted order:
 *      - If `findParent(u) != findParent(v)`:
 *          * Add edge to MST and add weight to total cost.
 *          * Union sets: `unionByRank(u, v)`.
 *      - Else: Skip edge (would create a cycle).
 * 4. Stop when (V - 1) edges are included.
 * 
 * Time: O(E log E) or O(E log V) | Space: O(V + E) | Best for: Sparse Graphs
 */
struct DisjointSet {
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    bool unionByRank(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV) return false;

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootV] < rank[rootU]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

pair<int, vector<Edge>> kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DisjointSet dsu(V);
    int totalCost = 0;
    vector<Edge> mstEdges;

    for (const auto& edge : edges) {
        if (dsu.unionByRank(edge.u, edge.v)) {
            totalCost += edge.weight;
            mstEdges.push_back(edge);
            if ((int)mstEdges.size() == V - 1) break;
        }
    }
    return {totalCost, mstEdges};
}

/**
 * ----------------------------------------------------------------------------------------------
 * PRIM'S ALGORITHM (VERTEX-CENTRIC GREEDY USING MIN-HEAP)
 * ----------------------------------------------------------------------------------------------
 * SUMMARIZED STEPS:
 * 1. Maintain `inMST` boolean array initialized to false.
 * 2. Min-Heap stores tuples: `{weight, currentVertex, parentVertex}`.
 * 3. Start at vertex 0: push `{0, 0, -1}`.
 * 4. While priority queue not empty:
 *      a. Pop minimum weight tuple `{w, u, parent}`.
 *      b. If `inMST[u] == true`, continue.
 *      c. Mark `inMST[u] = true`, add `w` to totalCost, record edge (parent, u).
 *      d. For each neighbor `{v, weight}` of `u`:
 *          If `!inMST[v]`, push `{weight, v, u}` to Min-Heap.
 * 5. Return totalCost and MST edges.
 * 
 * Time: O((V + E) log V) | Space: O(V + E) | Best for: Dense Graphs
 */
pair<int, vector<pair<int, int>>> primMST(int V, const vector<vector<pair<int, int>>>& adjWeighted) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<bool> inMST(V, false);
    int totalCost = 0;
    vector<pair<int, int>> mstEdges;

    pq.push({0, 0, -1});

    while (!pq.empty()) {
        auto [w, u, parent] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalCost += w;
        if (parent != -1) mstEdges.push_back({parent, u});

        for (const auto& neighbor : adjWeighted[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v]) {
                pq.push({weight, v, u});
            }
        }
    }
    return {totalCost, mstEdges};
}


// ==============================================================================================
// PART 6: SINGLE-SOURCE SHORTEST PATHS (SSSP) - DIJKSTRA & BELLMAN-FORD
// ==============================================================================================
/**
 * ----------------------------------------------------------------------------------------------
 * ALGORITHM: DIJKSTRA'S ALGORITHM (GREEDY SSSP FOR NON-NEGATIVE WEIGHTS)
 * ----------------------------------------------------------------------------------------------
 * SUMMARIZED STEPS:
 * 1. Initialize `dist` vector of size V with `INF`, set `dist[source] = 0`.
 * 2. Min-Heap stores `{distance, vertex}`, push `{0, source}`.
 * 3. While Min-Heap is not empty:
 *      a. Pop `{currDist, u}` with smallest distance.
 *      b. If `currDist > dist[u]`, continue.
 *      c. For each neighbor `{v, weight}` of `u`:
 *          RELAXATION: If `dist[u] + weight < dist[v]`:
 *              `dist[v] = dist[u] + weight`
 *              Push `{dist[v], v}` into Min-Heap.
 * 4. Return `dist` array.
 * 
 * Time: O((V + E) log V) | Space: O(V)
 */
vector<int> dijkstra(int V, const vector<vector<pair<int, int>>>& adjWeighted, int source) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currDist > dist[u]) continue;

        for (const auto& edge : adjWeighted[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

/**
 * ----------------------------------------------------------------------------------------------
 * ALGORITHM: BELLMAN-FORD ALGORITHM (DP SSSP WITH NEGATIVE WEIGHTS & CYCLE DETECTION)
 * ----------------------------------------------------------------------------------------------
 * SUMMARIZED STEPS:
 * 1. Initialize `dist` vector of size V with `INF`, set `dist[source] = 0`.
 * 2. Relax all E edges (V - 1) times:
 *      For each edge (u, v, weight):
 *          If `dist[u] != INF` and `dist[u] + weight < dist[v]`:
 *              `dist[v] = dist[u] + weight`
 * 3. Negative Cycle Detection (V-th relaxation check):
 *      For each edge (u, v, weight):
 *          If `dist[u] != INF` and `dist[u] + weight < dist[v]`:
 *              Report negative cycle! Return empty vector.
 * 4. Return `dist` array.
 * 
 * Time: O(V * E) | Space: O(V)
 */
vector<int> bellmanFord(int V, const vector<Edge>& edges, int source) {
    vector<int> dist(V, INF);
    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.weight;
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int wt = edge.weight;
        if (dist[u] != INF && dist[u] + wt < dist[v]) {
            cout << "[Warning]: Graph contains a Negative Weight Cycle! Distances cannot be determined.\n";
            return {};
        }
    }
    return dist;
}


// ==============================================================================================
// PART 7: ALL-PAIRS SHORTEST PATHS (APSP) - FLOYD-WARSHALL ALGORITHM
// ==============================================================================================
/**
 * ----------------------------------------------------------------------------------------------
 * ALGORITHM: FLOYD-WARSHALL ALGORITHM (ALL-PAIRS SHORTEST PATHS)
 * ----------------------------------------------------------------------------------------------
 * Intuition:
 *   Computes the shortest distances between EVERY pair of vertices (u, v) in a directed or 
 *   undirected weighted graph. Uses Dynamic Programming.
 * 
 * DP RECURRENCE RELATION:
 *   Let dist[i][j] be the shortest distance from vertex i to j using intermediate vertices from {0, 1, ..., k}.
 *   At step k, we check whether passing through vertex k gives a shorter path from i to j:
 * 
 *       dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
 * 
 * SUMMARIZED STEPS:
 * 1. Initialize 2D distance matrix `dist[V][V]`:
 *      - `dist[i][i] = 0` (distance to self is 0)
 *      - `dist[i][j] = weight(i, j)` if direct edge exists
 *      - `dist[i][j] = INF` if no direct edge exists
 * 2. Three nested loops:
 *      For k from 0 to V - 1 (Intermediate vertex):
 *          For i from 0 to V - 1 (Source vertex):
 *              For j from 0 to V - 1 (Destination vertex):
 *                  If `dist[i][k] != INF` and `dist[k][j] != INF`:
 *                      `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
 * 3. Negative Cycle Detection:
 *      If `dist[i][i] < 0` for any vertex `i`, then a negative weight cycle exists!
 * 4. Return `dist` matrix.
 * 
 * Time Complexity:  O(V^3)  [Three simple nested loops from 0 to V-1]
 * Space Complexity: O(V^2)  [V x V distance matrix]
 */
vector<vector<int>> floydWarshall(int V, const vector<vector<int>>& graphMatrix) {
    vector<vector<int>> dist = graphMatrix;

    // k is the intermediate vertex
    for (int k = 0; k < V; k++) {
        // i is the source vertex
        for (int i = 0; i < V; i++) {
            // j is the destination vertex
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "[Warning]: Negative weight cycle detected in graph via Floyd-Warshall!\n";
            return {};
        }
    }
    return dist;
}

void printDistanceMatrix(const vector<vector<int>>& dist) {
    int V = dist.size();
    cout << "\n--- All-Pairs Shortest Path Matrix (Floyd-Warshall) ---\n     ";
    for (int j = 0; j < V; j++) cout << "To " << j << "   ";
    cout << "\n   " << string(V * 8, '-') << "\n";
    for (int i = 0; i < V; i++) {
        cout << "From " << i << " | ";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << setw(5) << "INF" << "  ";
            } else {
                cout << setw(5) << dist[i][j] << "  ";
            }
        }
        cout << "\n";
    }
}


// ==============================================================================================
// PART 8: MAIN FUNCTION - COMPLETE STUDENT DEMONSTRATION & TEST SUITE
// ==============================================================================================
int main() {
    cout << "==============================================================================\n";
    cout << "   UNIT 4: GRAPH ALGORITHMS, NETWORK OPTIMIZATION & GREEDY TECHNIQUES DEMO    \n";
    cout << "==============================================================================\n";

    // --------------------------------------------------------------------------
    // 1. Introduction to Graphs (Matrix & List)
    // --------------------------------------------------------------------------
    cout << "\n>>> 1. INTRODUCTION TO GRAPHS & REPRESENTATIONS <<<\n";
    int V1 = 5;
    vector<pair<int, int>> sampleEdges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}};
    cout << "Undirected Graph (5 Vertices): (0-1), (0-2), (1-2), (1-3), (2-4)\n";

    vector<vector<int>> matrix = createAdjacencyMatrix(V1, sampleEdges, false);
    printAdjacencyMatrix(matrix);

    vector<vector<int>> adjList = createAdjacencyList(V1, sampleEdges, false);
    printAdjacencyList(adjList);

    // --------------------------------------------------------------------------
    // 2. Graph Traversals (BFS & DFS)
    // --------------------------------------------------------------------------
    cout << "\n>>> 2. GRAPH TRAVERSALS (BFS & DFS) <<<\n";
    vector<int> bfsRes = bfs(V1, adjList, 0);
    cout << "BFS Traversal (starting at 0): ";
    for (int node : bfsRes) cout << node << " ";
    cout << "\n";

    vector<int> dfsRes = dfs(V1, adjList, 0);
    cout << "DFS Traversal (starting at 0): ";
    for (int node : dfsRes) cout << node << " ";
    cout << "\n";

    // --------------------------------------------------------------------------
    // 3. Topological Sort (DAG)
    // --------------------------------------------------------------------------
    cout << "\n>>> 3. TOPOLOGICAL SORT (ON DAG) <<<\n";
    int V_topo = 6;
    vector<pair<int, int>> topoEdges = {{5, 0}, {5, 2}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    vector<vector<int>> topoAdj = createAdjacencyList(V_topo, topoEdges, true);

    cout << "DAG Edges: 5->0, 5->2, 4->0, 4->1, 2->3, 3->1\n";
    vector<int> topoDFS = topologicalSortDFS(V_topo, topoAdj);
    cout << "Topological Sort (DFS Stack Method):  ";
    for (int node : topoDFS) cout << node << " ";
    cout << "\n";

    vector<int> topoKahn = topologicalSortKahn(V_topo, topoAdj);
    cout << "Topological Sort (Kahn's BFS Method): ";
    for (int node : topoKahn) cout << node << " ";
    cout << "\n";

    // --------------------------------------------------------------------------
    // 4. Greedy Technique: Fractional Knapsack Problem
    // --------------------------------------------------------------------------
    cout << "\n>>> 4. GREEDY TECHNIQUE: FRACTIONAL KNAPSACK PROBLEM <<<\n";
    double knapsackCapacity = 50.0;
    vector<KnapsackItem> items = {
        {1, 60.0, 10.0},  // Item 1: value=60,  weight=10 (ratio = 6.0)
        {2, 100.0, 20.0}, // Item 2: value=100, weight=20 (ratio = 5.0)
        {3, 120.0, 30.0}  // Item 3: value=120, weight=30 (ratio = 4.0)
    };
    cout << "Knapsack Capacity = " << knapsackCapacity << "\n";
    double maxKnapsackValue = fractionalKnapsack(knapsackCapacity, items);
    cout << "Maximum Value Achieved in Fractional Knapsack = " << fixed << setprecision(2) << maxKnapsackValue << "\n";

    // --------------------------------------------------------------------------
    // 5. Minimum Spanning Trees (Kruskal's & Prim's)
    // --------------------------------------------------------------------------
    cout << "\n>>> 5. MINIMUM SPANNING TREES (MST) <<<\n";
    int V_mst = 4;
    vector<Edge> mstEdgeList = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    cout << "Weighted Edges: (0-1: 10), (0-2: 6), (0-3: 5), (1-3: 15), (2-3: 4)\n";

    // Kruskal's
    auto [kruskalCost, kruskalEdges] = kruskalMST(V_mst, mstEdgeList);
    cout << "Kruskal's MST Cost = " << kruskalCost << " | Edges: ";
    for (const auto& e : kruskalEdges) cout << "(" << e.u << "-" << e.v << " wt:" << e.weight << ") ";
    cout << "\n";

    // Prim's
    vector<vector<pair<int, int>>> primAdj(V_mst);
    for (const auto& e : mstEdgeList) {
        primAdj[e.u].push_back({e.v, e.weight});
        primAdj[e.v].push_back({e.u, e.weight});
    }
    auto [primCost, primEdges] = primMST(V_mst, primAdj);
    cout << "Prim's MST Cost    = " << primCost << " | Edges: ";
    for (const auto& e : primEdges) cout << "(" << e.first << "-" << e.second << ") ";
    cout << "\n";

    // --------------------------------------------------------------------------
    // 6. Single-Source Shortest Paths (Dijkstra & Bellman-Ford)
    // --------------------------------------------------------------------------
    cout << "\n>>> 6. SINGLE-SOURCE SHORTEST PATHS (SSSP) <<<\n";
    int V_sp = 5;
    vector<vector<pair<int, int>>> spAdj(V_sp);
    vector<Edge> spEdgeList;

    auto addEdge = [&](int u, int v, int w) {
        spAdj[u].push_back({v, w});
        spEdgeList.push_back({u, v, w});
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(2, 1, 2);
    addEdge(1, 3, 1);
    addEdge(2, 3, 5);
    addEdge(3, 4, 3);

    int src = 0;
    vector<int> dijkDist = dijkstra(V_sp, spAdj, src);
    cout << "Dijkstra Distances from Source " << src << ":\n";
    for (int i = 0; i < V_sp; i++) cout << "  Node " << i << ": " << dijkDist[i] << "\n";

    vector<int> bfDist = bellmanFord(V_sp, spEdgeList, src);
    cout << "Bellman-Ford Distances from Source " << src << ":\n";
    for (int i = 0; i < V_sp; i++) cout << "  Node " << i << ": " << bfDist[i] << "\n";

    // --------------------------------------------------------------------------
    // 7. All-Pairs Shortest Paths (Floyd-Warshall)
    // --------------------------------------------------------------------------
    cout << "\n>>> 7. ALL-PAIRS SHORTEST PATHS (FLOYD-WARSHALL) <<<\n";
    int V_apsp = 4;
    // Graph weight matrix representation (INF means no edge)
    vector<vector<int>> graphMatrix = {
        {0,   3,   INF, 5},
        {2,   0,   INF, 4},
        {INF, 1,   0,   INF},
        {INF, INF, 2,   0}
    };

    cout << "Initial Weight Matrix (INF denotes no direct edge):\n";
    printDistanceMatrix(graphMatrix);

    vector<vector<int>> allPairsDist = floydWarshall(V_apsp, graphMatrix);
    printDistanceMatrix(allPairsDist);

    cout << "\n==============================================================================\n";
    cout << "                 ALL SYLLABUS TOPICS COMPLETED SUCCESSFULLY                   \n";
    cout << "==============================================================================\n";

    return 0;
}