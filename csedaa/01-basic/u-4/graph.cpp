


// a graph is a non-linear data structure consisting of nodes and edges.
//  The nodes are sometimes also referred to as vertices 
// and the edges are lines or arcs that connect any two nodes in the graph.
//  The following are some of the important terms related to graphs:

// 1. Vertex: A vertex is a fundamental part of a graph. It is also 
// called a node. A vertex is a point where two or more edges meet.
// 2. Edge: An edge is a line that connects two vertices in a graph.
// 3. Degree: The degree of a vertex is the number of edges incident to it
// 4. Path: A path is a sequence of edges that connect a sequence of vertices
// 5. Cycle: A cycle is a path that starts and ends at the same vertex\
// 6. Adjacent vertices: Two vertices are said to be adjacent 
//      if they are connected by an edge
// G= (V,E) where V is a set of vertices and E is a set of edges

// Types of Graphs:
// 1. Directed Graph: A directed graph is a graph in which the edges have a
// direction. 
// 2. Undirected Graph: An undirected graph is a graph in which the edges do not have a direction.
// 3. Weighted Graph: A weighted graph is a graph in which each edge has a weight or cost associated with it.
// 4. Unweighted Graph: An unweighted graph is a graph in which the edges do not have any weight or cost associated with them.
// 5. Cyclic Graph: A cyclic graph is a graph that contains at least one cycle.
// 6. Acyclic Graph: An acyclic graph is a graph that does not contain any cycles.
// 7. Connected Graph: A connected graph is a graph in which there is 
// a path between every pair of vertices.
// 8. Disconnected Graph: A disconnected graph is a graph in which there is 
// at least one pair of vertices that are not connected by a path.
// 9. Complete Graph: A complete graph is a graph in which 
//      there is an edge between every pair of vertices.

// Representation of Graphs:
// 1. Edge List: An edge list is a list of all the edges in a graph.
// V={0,1,2,3,4} , E={(0,1),(0,2),(1,2),(1,3),(2,4)}
// 2. Adjacency Matrix: An adjacency matrix is a 2D array of size V x V
//    where V is the number of vertices in a graph. 
//    The value of the cell at row i and column j is 1 
 //    if there is an edge from vertex i to vertex j, and 0 otherwise.
// 3. Adjacency List: An adjacency list is an array of lists.
//  The size of the array is equal to the number of vertices in a graph
//  Each element of the array is a list that contains all the vertices
//  that are adjacent to the vertex represented by that element of the array.   
// Example:
// 0 -> 1 -> 2
// 1 -> 0 -> 2 -> 3
// 2 -> 0 -> 1 -> 4
// 3 -> 1 -> 4
// 4 -> 2 -> 3

// Graph Traversal:
// Breadth First Search (BFS): BFS is a graph traversal algorithm that starts at a given vertex and explores all the vertices at the present depth level before moving on to the vertices at the next depth level. It uses a queue data structure to keep track of the vertices to be explored.
// Depth First Search (DFS): DFS is a graph traversal algorithm that starts at a given vertex