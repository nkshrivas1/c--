/**
 * ============================================================================
 *                         GRAPH DATA STRUCTURE & ALGORITHMS
 * ============================================================================
 * 
 * 1. WHAT IS A GRAPH?
 *    A graph G = (V, E) is a non-linear data structure consisting of:
 *    - Vertices (V): Fundamental points/nodes in the graph.
 *    - Edges (E): Links or arcs connecting pairs of vertices.
 * 
 * 2. IMPORTANT GRAPH TERMINOLOGY:
 *    - Vertex (Node): An individual data point in the graph.
 *    - Edge: Connection between two vertices. Can be directed or undirected.
 *    - Degree: 
 *        * Undirected Graph: Number of edges incident to a vertex.
 *        * Directed Graph:
 *            - In-degree: Number of incoming edges to a vertex.
 *            - Out-degree: Number of outgoing edges from a vertex.
 *    - Path: A sequence of consecutive vertices connected by edges.
 *    - Cycle: A path that starts and ends at the exact same vertex.
 *    - Adjacent Vertices: Two vertices connected directly by an edge.
 *    - Connected Graph: A path exists between every pair of vertices.
 *    - Disconnected Graph: At least one pair of vertices has no connecting path.
 *    - Complete Graph: An edge exists between every pair of vertices.
 *    - DAG (Directed Acyclic Graph): A directed graph with NO directed cycles.
 * 
 * 3. GRAPH REPRESENTATIONS:
 *    a) Adjacency Matrix:
 *       - 2D array of size V x V.
 *       - matrix[u][v] = 1 (or weight) if edge (u -> v) exists, else 0.
 *       - Space Complexity: O(V^2)
 *       - Edge Lookup: O(1)
 *       - Best for: Dense graphs (many edges).
 * 
 *    b) Adjacency List:
 *       - Array / vector of lists of size V.
 *       - adj[u] contains all neighboring vertices directly reachable from u.
 *       - Space Complexity: O(V + E)
 *       - Edge Lookup: O(degree(u))
 *       - Best for: Sparse graphs (few edges, standard in most interviews/exams).
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

// ============================================================================
// SECTION 1: GRAPH REPRESENTATION BUILDERS & PRINTERS
// ============================================================================

/**
 * Creates an Adjacency Matrix from an edge list.
 * @param V Number of vertices (0 to V-1)
 * @param edges Vector of pairs representing edges {u, v}
 * @param isDirected Boolean flag indicating if graph is directed
 */
vector<vector<int>> createAdjacencyMatrix(int V, const vector<pair<int, int>>& edges, bool isDirected = false) {
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        matrix[u][v] = 1;
        if (!isDirected) {
            matrix[v][u] = 1; // Symmetric for undirected graph
        }
    }
    return matrix;
}

/**
 * Prints the Adjacency Matrix in a formatted grid.
 */
void printAdjacencyMatrix(const vector<vector<int>>& matrix) {
    int V = matrix.size();
    cout << "\nAdjacency Matrix (" << V << " x " << V << "):\n   ";
    for (int j = 0; j < V; j++) cout << j << " ";
    cout << "\n  " << string(2 * V + 1, '-') << "\n";
    for (int i = 0; i < V; i++) {
        cout << i << "| ";
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

/**
 * Creates an Adjacency List from an edge list.
 * @param V Number of vertices (0 to V-1)
 * @param edges Vector of pairs representing edges {u, v}
 * @param isDirected Boolean flag indicating if graph is directed
 */
vector<vector<int>> createAdjacencyList(int V, const vector<pair<int, int>>& edges, bool isDirected = false) {
    vector<vector<int>> adj(V);
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        if (!isDirected) {
            adj[v].push_back(u); // Add reverse edge for undirected graph
        }
    }
    return adj;
}

/**
 * Prints the Adjacency List for each vertex.
 */
void printAdjacencyList(const vector<vector<int>>& adj) {
    cout << "\nAdjacency List:\n";
    for (size_t i = 0; i < adj.size(); i++) {
        cout << "Vertex " << i << " -> ";
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


// ============================================================================
// SECTION 2: BREADTH-FIRST SEARCH (BFS)
// ============================================================================
/**
 * ALGORITHM: Breadth First Search (BFS)
 * -------------------------------------
 * Intuition: Explores vertices level-by-level (like wave ripples in water).
 * Uses a Queue (FIFO - First In, First Out).
 * 
 * SUMMARIZED STEPS:
 * 1. Initialize a `visited` boolean array of size V to false.
 * 2. Create an empty `queue` and push the `startNode`. Mark `startNode` as visited.
 * 3. While queue is not empty:
 *      a. Pop front element `u` from queue.
 *      b. Add `u` to traversal result (or process it).
 *      c. For each adjacent unvisited neighbor `v` of `u`:
 *            i. Mark `v` as visited.
 *           ii. Push `v` into the queue.
 * 4. Return traversal result.
 * 
 * Time Complexity:  O(V + E)  [Each vertex is visited once, all edges explored]
 * Space Complexity: O(V)      [Queue + Visited array]
 * Applications:     Shortest path in unweighted graphs, level order traversal, GPS navigation.
 */
vector<int> bfs(int V, const vector<vector<int>>& adj, int startNode) {
    vector<bool> visited(V, false);
    vector<int> traversalOrder;
    queue<int> q;

    // Step 1: Start from the source node
    visited[startNode] = true;
    q.push(startNode);

    // Step 2: Explore level by level
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        traversalOrder.push_back(curr);

        // Step 3: Visit all unvisited neighbors
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark visited upon queuing to avoid duplicates
                q.push(neighbor);
            }
        }
    }

    return traversalOrder;
}


// ============================================================================
// SECTION 3: DEPTH-FIRST SEARCH (DFS)
// ============================================================================
/**
 * ALGORITHM: Depth First Search (DFS)
 * -----------------------------------
 * Intuition: Explores as deep as possible along each branch before backtracking.
 * Uses Recursion (System Call Stack) or an explicit Stack (LIFO).
 * 
 * SUMMARIZED STEPS:
 * 1. Mark the current vertex `u` as visited.
 * 2. Process / print the current vertex `u`.
 * 3. For each neighbor `v` of `u`:
 *      a. If `v` is unvisited:
 *            Recursively call DFS for `v`.
 * 4. Backtrack automatically when no unvisited neighbors remain.
 * 
 * Time Complexity:  O(V + E)  [Each vertex and edge visited]
 * Space Complexity: O(V)      [Recursion stack in worst case (skewed graph) + visited array]
 * Applications:     Cycle detection, topological sort, finding connected components, maze solving.
 */
void dfsRecursive(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& traversalOrder) {
    // Step 1: Mark current vertex as visited
    visited[u] = true;
    traversalOrder.push_back(u);

    // Step 2: Recursively visit unvisited neighbors
    for (int neighbor : adj[u]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited, traversalOrder);
        }
    }
}

/**
 * Driver function for DFS traversal starting from `startNode`.
 */
vector<int> dfs(int V, const vector<vector<int>>& adj, int startNode) {
    vector<bool> visited(V, false);
    vector<int> traversalOrder;
    dfsRecursive(startNode, adj, visited, traversalOrder);
    return traversalOrder;
}


// ============================================================================
// SECTION 4: CYCLE DETECTION IN UNDIRECTED GRAPH
// ============================================================================
/**
 * ALGORITHM: Cycle Detection in Undirected Graph (DFS)
 * ----------------------------------------------------
 * Intuition: In an undirected graph, if we visit an adjacent node that is ALREADY
 * visited, and it is NOT the parent (node we directly arrived from), then a cycle exists.
 * 
 * SUMMARIZED STEPS:
 * 1. Keep track of `parent` for every node during DFS traversal.
 * 2. Mark current node `u` as visited.
 * 3. For each neighbor `v` of `u`:
 *      a. If `v` is unvisited:
 *            Recursively check if subtree contains a cycle: dfsCycleUndirected(v, u).
 *            If yes -> return true.
 *      b. Else if `v` is already visited AND `v != parent`:
 *            A cycle is detected! -> return true.
 * 4. If all neighbors explored without finding a back-edge, return false.
 * 
 * Time Complexity:  O(V + E)
 * Space Complexity: O(V)
 */
bool dfsCycleUndirected(int u, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;

    for (int neighbor : adj[u]) {
        if (!visited[neighbor]) {
            if (dfsCycleUndirected(neighbor, u, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            // Neighbor visited and is NOT the parent -> Cycle found!
            return true;
        }
    }
    return false;
}

bool hasCycleUndirected(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    // Check all components (in case graph is disconnected)
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycleUndirected(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}


// ============================================================================
// SECTION 5: CYCLE DETECTION IN DIRECTED GRAPH
// ============================================================================
/**
 * ALGORITHM: Cycle Detection in Directed Graph (DFS with Recursion Stack)
 * ----------------------------------------------------------------------
 * Intuition: In a directed graph, a cycle exists if and only if there is a 
 * "Back-Edge" pointing to an ancestor currently active in the recursion call stack.
 * 
 * SUMMARIZED STEPS:
 * 1. Maintain two boolean arrays: `visited` and `inRecursionStack`.
 * 2. For current node `u`:
 *      a. Mark `visited[u] = true` and `inRecursionStack[u] = true`.
 *      b. For each neighbor `v` of `u`:
 *            i. If `v` is not visited, recursively call DFS for `v`.
 *               If it returns true -> cycle detected!
 *           ii. Else if `inRecursionStack[v] == true` -> Back-edge found! Cycle exists!
 *      c. Backtrack: unmark `inRecursionStack[u] = false` before returning.
 * 3. Return false if no cycle found.
 * 
 * Time Complexity:  O(V + E)
 * Space Complexity: O(V)
 */
bool dfsCycleDirected(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursionStack) {
    visited[u] = true;
    inRecursionStack[u] = true;

    for (int neighbor : adj[u]) {
        if (!visited[neighbor]) {
            if (dfsCycleDirected(neighbor, adj, visited, inRecursionStack)) {
                return true;
            }
        } else if (inRecursionStack[neighbor]) {
            // Neighbor is active in the current recursion stack -> Directed cycle!
            return true;
        }
    }

    // Step 3: Backtrack when leaving vertex
    inRecursionStack[u] = false;
    return false;
}

bool hasCycleDirected(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> inRecursionStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycleDirected(i, adj, visited, inRecursionStack)) {
                return true;
            }
        }
    }
    return false;
}


// ============================================================================
// SECTION 6: TOPOLOGICAL SORT (For DAGs only)
// ============================================================================
/**
 * DEFINITION:
 * Topological sorting of a Directed Acyclic Graph (DAG) is a linear ordering of 
 * vertices such that for every directed edge u -> v, vertex u comes before v.
 * Note: Only valid on DAGs (graphs with NO cycles).
 * 
 * METHOD 1: DFS-based Topological Sort (Using Stack)
 * --------------------------------------------------
 * SUMMARIZED STEPS:
 * 1. Create a `visited` array and an empty `stack`.
 * 2. For each unvisited vertex, run DFS helper:
 *      a. Mark current vertex `u` as visited.
 *      b. Recursively visit all unvisited neighbors of `u`.
 *      c. After visiting all descendants (post-order), PUSH `u` onto the stack.
 * 3. When DFS finishes for all components, pop elements from stack to get topological order.
 * 
 * Time Complexity:  O(V + E)
 * Space Complexity: O(V) [Stack + Visited array]
 */
void dfsTopoHelper(int u, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;

    for (int neighbor : adj[u]) {
        if (!visited[neighbor]) {
            dfsTopoHelper(neighbor, adj, visited, st);
        }
    }

    // Push to stack only after all dependent vertices have been processed
    st.push(u);
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
 * METHOD 2: Kahn's Algorithm (BFS-based Topological Sort using In-Degrees)
 * -----------------------------------------------------------------------
 * SUMMARIZED STEPS:
 * 1. Compute in-degree (number of incoming edges) for every vertex.
 * 2. Push all vertices with `inDegree == 0` into a queue.
 * 3. While queue is not empty:
 *      a. Pop front vertex `u` and add it to `topoOrder`.
 *      b. For each neighbor `v` of `u`:
 *            i. Decrement `inDegree[v]` by 1 (simulating removal of edge u -> v).
 *           ii. If `inDegree[v]` becomes 0, push `v` into the queue.
 * 4. Cycle Check:
 *      - If `topoOrder.size() == V`: Valid topological ordering exists.
 *      - If `topoOrder.size() < V`: Graph contains a cycle! (Topological sort impossible).
 * 
 * Time Complexity:  O(V + E)
 * Space Complexity: O(V) [Queue + In-degree array]
 */
vector<int> topologicalSortKahn(int V, const vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);

    // Step 1: Calculate in-degree for every vertex
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 2: Enqueue all vertices with in-degree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process vertices
    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int neighbor : adj[u]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 4: Verify if DAG (Cycle check)
    if ((int)topoOrder.size() != V) {
        cout << "[Warning]: Graph contains a cycle! Topological sort is not possible.\n";
        return {};
    }

    return topoOrder;
}


// ============================================================================
// SECTION 7: DIJKSTRA'S ALGORITHM (Single Source Shortest Path for Weighted Graphs)
// ============================================================================
/**
 * ALGORITHM: Dijkstra's Algorithm
 * --------------------------------
 * Intuition: Finds the shortest distance from a single source vertex to all other 
 * vertices in a non-negative weighted graph using a Greedy approach with a Min-Heap.
 * 
 * SUMMARIZED STEPS:
 * 1. Initialize `dist` vector of size V with infinity (INT_MAX), set `dist[source] = 0`.
 * 2. Create a min-priority queue storing pairs: {distance, vertex}.
 * 3. Push `{0, source}` into priority queue.
 * 4. While priority queue is not empty:
 *      a. Pop pair `{d, u}` with smallest distance.
 *      b. If `d > dist[u]`, continue (outdated entry).
 *      c. For each neighbor `{v, weight}` of `u`:
 *            If `dist[u] + weight < dist[v]`:
 *                `dist[v] = dist[u] + weight`
 *                Push `{dist[v], v}` to priority queue.
 * 5. Return `dist` array.
 * 
 * Time Complexity:  O((V + E) * log V) using Min-Heap
 * Space Complexity: O(V)
 */
vector<int> dijkstra(int V, const vector<vector<pair<int, int>>>& adjWeighted, int source) {
    vector<int> dist(V, INT_MAX);
    // Min-heap priority queue: stores {distance, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip if a shorter path to u was already processed
        if (currDist > dist[u]) continue;

        for (const auto& edge : adjWeighted[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


// ============================================================================
// SECTION 8: MAIN FUNCTION - COMPLETE DEMONSTRATION
// ============================================================================
int main() {
    cout << "========================================================\n";
    cout << "             GRAPH ALGORITHMS DEMONSTRATION             \n";
    cout << "========================================================\n";

    // ----------------------------------------------------
    // DEMO 1: Graph Representations (Adjacency Matrix & List)
    // ----------------------------------------------------
    int V = 5;
    vector<pair<int, int>> undirectedEdges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}
    };

    cout << "\n>>> 1. GRAPH REPRESENTATIONS <<<\n";
    cout << "Number of Vertices: " << V << "\n";
    cout << "Edges: (0-1), (0-2), (1-2), (1-3), (2-4)\n";

    // Build & print Adjacency Matrix
    vector<vector<int>> adjMatrix = createAdjacencyMatrix(V, undirectedEdges, false);
    printAdjacencyMatrix(adjMatrix);

    // Build & print Adjacency List
    vector<vector<int>> adjList = createAdjacencyList(V, undirectedEdges, false);
    printAdjacencyList(adjList);


    // ----------------------------------------------------
    // DEMO 2: Breadth-First Search (BFS)
    // ----------------------------------------------------
    cout << "\n>>> 2. BREADTH FIRST SEARCH (BFS) <<<\n";
    int startNode = 0;
    vector<int> bfsOrder = bfs(V, adjList, startNode);
    cout << "BFS Traversal starting from vertex " << startNode << ": ";
    for (int node : bfsOrder) {
        cout << node << " ";
    }
    cout << "\n";


    // ----------------------------------------------------
    // DEMO 3: Depth-First Search (DFS)
    // ----------------------------------------------------
    cout << "\n>>> 3. DEPTH FIRST SEARCH (DFS) <<<\n";
    vector<int> dfsOrder = dfs(V, adjList, startNode);
    cout << "DFS Traversal starting from vertex " << startNode << ": ";
    for (int node : dfsOrder) {
        cout << node << " ";
    }
    cout << "\n";


    // ----------------------------------------------------
    // DEMO 4: Cycle Detection in Undirected Graph
    // ----------------------------------------------------
    cout << "\n>>> 4. CYCLE DETECTION (UNDIRECTED GRAPH) <<<\n";
    bool cycleUndirected = hasCycleUndirected(V, adjList);
    cout << "Graph contains cycle? " << (cycleUndirected ? "YES (Cycle exists: 0-1-2-0)" : "NO") << "\n";


    // ----------------------------------------------------
    // DEMO 5: Topological Sort on a DAG (Directed Acyclic Graph)
    // ----------------------------------------------------
    cout << "\n>>> 5. TOPOLOGICAL SORT (ON DAG) <<<\n";
    int V_dag = 6;
    // Directed edges for a sample task scheduling DAG:
    // 5 -> 0, 5 -> 2, 4 -> 0, 4 -> 1, 2 -> 3, 3 -> 1
    vector<pair<int, int>> dagEdges = {
        {5, 0}, {5, 2}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };
    vector<vector<int>> dagAdj = createAdjacencyList(V_dag, dagEdges, true); // true = directed

    cout << "Directed Graph Edges: (5->0), (5->2), (4->0), (4->1), (2->3), (3->1)\n";
    printAdjacencyList(dagAdj);

    // Method A: DFS-based Topological Sort
    vector<int> topoDFS = topologicalSortDFS(V_dag, dagAdj);
    cout << "Topological Sort (DFS Method):   ";
    for (int node : topoDFS) cout << node << " ";
    cout << "\n";

    // Method B: Kahn's Algorithm (BFS-based)
    vector<int> topoKahn = topologicalSortKahn(V_dag, dagAdj);
    cout << "Topological Sort (Kahn's Algo):  ";
    for (int node : topoKahn) cout << node << " ";
    cout << "\n";


    // ----------------------------------------------------
    // DEMO 6: Cycle Detection in Directed Graph
    // ----------------------------------------------------
    cout << "\n>>> 6. CYCLE DETECTION (DIRECTED GRAPH) <<<\n";
    cout << "Testing DAG: Contains cycle? " << (hasCycleDirected(V_dag, dagAdj) ? "YES" : "NO") << "\n";

    // Add a cycle back edge: 1 -> 5
    dagEdges.push_back({1, 5});
    vector<vector<int>> cyclicDirectedAdj = createAdjacencyList(V_dag, dagEdges, true);
    cout << "After adding edge (1 -> 5): Contains cycle? " 
         << (hasCycleDirected(V_dag, cyclicDirectedAdj) ? "YES (Cycle detected!)" : "NO") << "\n";


    // ----------------------------------------------------
    // DEMO 7: Dijkstra's Algorithm (Shortest Path)
    // ----------------------------------------------------
    cout << "\n>>> 7. DIJKSTRA'S SHORTEST PATH ALGORITHM <<<\n";
    int V_weighted = 5;
    // Weighted graph representation: adjWeighted[u] = list of {v, weight}
    vector<vector<pair<int, int>>> adjWeighted(V_weighted);
    auto addWeightedEdge = [&](int u, int v, int w) {
        adjWeighted[u].push_back({v, w});
        adjWeighted[v].push_back({u, w}); // Undirected weighted edge
    };

    addWeightedEdge(0, 1, 4);
    addWeightedEdge(0, 2, 1);
    addWeightedEdge(2, 1, 2);
    addWeightedEdge(1, 3, 1);
    addWeightedEdge(2, 3, 5);
    addWeightedEdge(3, 4, 3);

    int src = 0;
    vector<int> shortestDistances = dijkstra(V_weighted, adjWeighted, src);

    cout << "Shortest distances from Source Vertex " << src << ":\n";
    for (int i = 0; i < V_weighted; i++) {
        cout << "  Distance to Vertex " << i << " = " << shortestDistances[i] << "\n";
    }

    cout << "\n========================================================\n";
    cout << "               ALL DEMOS COMPLETED SUCCESSFULLY         \n";
    cout << "========================================================\n";

    return 0;
}