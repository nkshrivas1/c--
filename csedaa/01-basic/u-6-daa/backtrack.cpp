#include<iostream>
using namespace std;

/*
    Backtracking is a general algorithmic technique that considers searching
     every possible combination in order to solve a computational problem. 
     Backtracking is often implemented using recursion. 
     It is used to solve constraint satisfaction problems, such as puzzles,
      crosswords, and combinatorial optimization problems.
*/

void printSubsets(vector<int>& nums, vector<int>& subset, int index) {
    if (index == nums.size()) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // Include the current element
    subset.push_back(nums[index]);
    printSubsets(nums, subset, index + 1);

    // Exclude the current element
    subset.pop_back();
    printSubsets(nums, subset, index + 1);
}

void printSubsetsSum(vector<int>& nums, vector<int>& current, int index,int currSum, int targetSum) {
    if (currSum == targetSum) {
        for (int num : current) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    if (index == nums.size() || currSum > targetSum) {
        return;
    }

    // Include the current element
    current.push_back(nums[index]);
    printSubsetsSum(nums, current, index + 1, currSum + nums[index], targetSum);

    // Exclude the current element
    current.pop_back();
    printSubsetsSum(nums, current, index + 1, currSum, targetSum);
}
int isSafe(vector<vector<int>>& board, int row, int col) {
    int n = board.size();
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}
void NQueensRec(vector<vector<int>>& board,vector<vector<vector<int>>>& solutions, int row) {
    int n = board.size();
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            NQueensRec(board, solutions, row + 1);
            board[row][col] = 0; // Backtrack
        }
    }
}

/*
Hamiltonian circuit cycle is a cycle in a graph that visits every vertex exactly
 once and returns to the starting vertex.
The Hamiltonian cycle problem is to determine whether such a cycle exists in a given graph.
Algorithm:
1.Initialize a path array to store the Hamiltonian cycle.
2. Recursive Exploration:
   - Start from the first vertex and mark it as visited.
   - For each unvisited vertex, check if it can be added to the path.
   - If it can be added, mark it as visited and recursively explore further.
   - If a valid Hamiltonian cycle is found, return true.
   - If not, backtrack by unmarking the vertex and trying the next one.
3. Base Case:
   - If all vertices are visited and there is an edge from the last vertex to the first
    vertex, a Hamiltonian cycle is found.
4. If no Hamiltonian cycle is found after exploring all possibilities, return false.

*/

