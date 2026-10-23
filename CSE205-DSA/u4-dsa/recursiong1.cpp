/**
 * ==============================================================================================
 *                         CSE205: DATA STRUCTURES & ALGORITHMS (DSA)
 *                          UNIT 4: RECURSION ESSENTIALS (GROUP 1)
 * ==============================================================================================
 * 
 * TOPICS COVERED:
 * ----------------
 * 1. Introduction to Recursion & The Call Stack
 * 2. Anatomy of a Recursive Function (Base Case & Recursive Step)
 * 3. Array Processing via Recursion:
 *    - Printing an Array in Reverse Order
 *    - Printing Array Elements in Extreme-to-Center Alternating Order [0, n-1, 1, n-2, ...]
 *    - In-Place Removal of Odd Numbers (No extra space)
 * 4. Mathematical Recursion:
 *    - Computing the N-th Fibonacci Number
 * 5. Divide and Conquer Recursion:
 *    - Recursive Binary Search on a Sorted Array
 * 6. Classical Recursive Puzzle:
 *    - Tower of Hanoi (Movement traces and recurrence)
 * 7. Comprehensive Demonstration in main()
 * 
 * ==============================================================================================
 * THEORY & EXAM NOTES: RECURSION
 * ==============================================================================================
 * 
 * 1. WHAT IS RECURSION?
 *    - A programming technique where a function calls itself directly or indirectly to solve a 
 *      smaller sub-instance of the same problem.
 *    - Every recursive algorithm requires TWO essential components:
 *        a) BASE CASE (Termination Condition): The simplest instance that can be solved directly 
 *           without further recursion. Without a base case, recursion leads to Stack Overflow.
 *        b) RECURSIVE STEP (Inductive Step): The logic that breaks the problem into one or more 
 *           smaller subproblems, moving closer to the base case.
 * 
 * 2. MEMORY MANAGEMENT (CALL STACK):
 *    - Each recursive call creates a new Activation Record (Stack Frame) on the runtime call stack.
 *    - The stack frame preserves local variables, parameters, and the return address.
 *    - Auxiliary Space Complexity of recursion is proportional to the maximum recursion depth: O(depth).
 * 
 * 3. SUMMARY OF ALGORITHMS IN THIS FILE:
 *    -------------------------------------------------------------------------------------------
 *    Algorithm              | Strategy             | Time Complexity | Space (Call Stack)
 *    -------------------------------------------------------------------------------------------
 *    Reverse Array Print    | Head / Tail Print    | O(N)            | O(N)
 *    Alternating Print      | Two-Pointer Recursion| O(N)            | O(N)
 *    Remove Odds In-Place   | Left Shift on Match  | O(N^2) worst    | O(N)
 *    Fibonacci (Naive)      | Binary Branching     | O(2^N)          | O(N)
 *    Binary Search          | Divide and Conquer   | O(log N)        | O(log N)
 *    Tower of Hanoi         | 3-Step Decomposition | O(2^N)          | O(N)
 *    -------------------------------------------------------------------------------------------
 * ==============================================================================================
 */

#include <iostream>
using namespace std;

// ==============================================================================================
// 1. RECURSIVE ARRAY PRINTING (REVERSE ORDER)
// ==============================================================================================
/**
 * Problem: Given an array of integers, recursively print its elements in reverse order.
 * 
 * Logic:
 * - Base Case: If n == 0, the array has no elements left to process; return.
 * - Processing: Print the last element arr[n-1].
 * - Recursive Call: Call printReverseArray(arr, n-1) to print the remaining prefix.
 * 
 * Time: O(N) | Space: O(N) stack frames
 */
void printReverseArray(int arr[], int n) {
    if (n == 0) return; // Base case
    cout << arr[n - 1] << " ";
    printReverseArray(arr, n - 1); // Recursive step
}

// ==============================================================================================
// 2. ALTERNATING EXTREME-TO-CENTER ARRAY PRINTING
// ==============================================================================================
/**
 * Problem: Print an array in alternating front-and-back order:
 *          arr[0], arr[n-1], arr[1], arr[n-2], arr[2], arr[n-3] ...
 * Example: arr[] = {1, 2, 3, 5, 6} -> Output: 1 6 2 5 3
 * 
 * Logic:
 * - Uses two pointers: 'i' (left boundary) and 'j' (right boundary).
 * - Base Case: If i > j, all elements have been printed; return.
 * - Processing: Print arr[i]. If i != j (to avoid duplicate on middle element for odd length), print arr[j].
 * - Recursive Call: Advance inward -> printArray(arr, i + 1, j - 1).
 * 
 * Time: O(N) | Space: O(N) stack frames
 */
void printArray(int arr[], int i, int j) {
    if (i > j) return; // Base case
    cout << arr[i] << " ";
    if (i != j) {
        cout << arr[j] << " ";
    }
    printArray(arr, i + 1, j - 1); // Recursive step
}

// ==============================================================================================
// 3. IN-PLACE REMOVAL OF ODD INTEGERS FROM ARRAY
// ==============================================================================================
/**
 * Problem: Recursively remove all odd integers from an array in-place without extra space.
 * Example: arr[] = {1, 2, 3, 4, 5, 6}, n = 6 -> Result: {2, 4, 6}, new size = 3
 * 
 * Logic:
 * - Base Case: If index >= n, entire array has been inspected; return current size n.
 * - If arr[index] is odd:
 *     Shift all subsequent elements one position left (arr[k] = arr[k+1]).
 *     Decrement n by 1.
 *     Re-check the SAME index in the next call: removeOdds(arr, n - 1, index).
 * - If arr[index] is even:
 *     Element is kept; advance to next index: removeOdds(arr, n, index + 1).
 * 
 * Time: O(N^2) in worst case (due to shifts) | Space: O(N) stack frames
 */
int removeOdds(int arr[], int n, int index) {
    if (index >= n) return n; // Base case: inspected all remaining elements

    if (arr[index] % 2 != 0) {
        // Shift elements to the left to overwrite the odd number
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        // Do not increment index because the newly shifted element must be inspected
        return removeOdds(arr, n - 1, index);
    }

    // Current element is even, proceed to next index
    return removeOdds(arr, n, index + 1);
}

// ==============================================================================================
// 4. N-TH FIBONACCI NUMBER
// ==============================================================================================
/**
 * Problem: Compute the n-th Fibonacci number where F(1) = 1, F(2) = 1.
 * Series: 1, 1, 2, 3, 5, 8, 13, 21, 34 ...
 * 
 * Recurrence Relation:
 *   F(n) = 1                   for n <= 2 (Base Case)
 *   F(n) = F(n-1) + F(n-2)     for n > 2  (Recursive Case)
 * 
 * Time: O(2^N) exponential branching | Space: O(N) maximum call stack depth
 */
int fibonacci(int n) {
    if (n <= 2) return 1; // Base case: 1st and 2nd Fibonacci numbers are 1
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// ==============================================================================================
// 5. RECURSIVE BINARY SEARCH
// ==============================================================================================
/**
 * Problem: Search for 'key' in a sorted array using Divide and Conquer recursion.
 * 
 * Logic:
 * - Base Case: If i > j, the search window is invalid (key does not exist); return -1.
 * - Calculate mid = i + (j - i) / 2 (avoids integer overflow).
 * - If arr[mid] == key: Target found, return mid.
 * - If arr[mid] > key: Target lies in left half -> recurse on [i, mid - 1].
 * - If arr[mid] < key: Target lies in right half -> recurse on [mid + 1, j].
 * 
 * Time: O(log N) | Space: O(log N) stack frames
 */
int binarySearch(int arr[], int key, int i, int j) {
    if (i > j) return -1; // Base case: key not found

    int mid = i + (j - i) / 2;

    if (arr[mid] == key) {
        return mid; // Key found at index mid
    } else if (arr[mid] > key) {
        return binarySearch(arr, key, i, mid - 1); // Search left half
    } else {
        return binarySearch(arr, key, mid + 1, j); // Search right half
    }
}

// ==============================================================================================
// 6. TOWER OF HANOI PUZZLE
// ==============================================================================================
/**
 * Problem: Move n disks from 'source' to 'destination' peg using 'helper' peg.
 * Rules:
 *   1. Only one disk can be moved at a time.
 *   2. A larger disk can never be placed on top of a smaller disk.
 * 
 * Divide & Conquer Strategy for n disks:
 *   Step 1: Move top (n - 1) disks from source to helper peg using destination peg.
 *   Step 2: Move the n-th (largest) disk directly from source to destination peg.
 *   Step 3: Move the (n - 1) disks from helper to destination peg using source peg.
 * 
 * Total Moves: 2^n - 1
 * Time: O(2^N) | Space: O(N) stack frames
 */
void towerOfHanoi(int n, char source, char destination, char helper) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    // Step 1: Move (n-1) disks from source to helper using destination
    towerOfHanoi(n - 1, source, helper, destination);

    // Step 2: Move largest disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Step 3: Move (n-1) disks from helper to destination using source
    towerOfHanoi(n - 1, helper, destination, source);
}

// ==============================================================================================
// 7. MAIN FUNCTION & DEMONSTRATION
// ==============================================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "         CSE205: RECURSION (GROUP 1) DEMO                " << endl;
    cout << "=========================================================" << endl;

    // 1. Reverse Array Printing
    cout << "\n--- 1. Print Array in Reverse Order ---" << endl;
    int arr1[] = {10, 20, 30, 40, 50};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original array: 10 20 30 40 50" << endl;
    cout << "Reversed output: ";
    printReverseArray(arr1, n1);
    cout << endl;

    // 2. Alternating Extreme-to-Center Printing
    cout << "\n--- 2. Alternating Extreme-to-Center Print ---" << endl;
    int arr2[] = {1, 2, 3, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Original array: 1 2 3 5 6" << endl;
    cout << "Alternating order: ";
    printArray(arr2, 0, n2 - 1);
    cout << endl;

    // 3. In-Place Odd Removal
    cout << "\n--- 3. In-Place Remove Odds from Array ---" << endl;
    int arr3[] = {1, 2, 3, 4, 5, 6};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Original array: ";
    for (int k = 0; k < n3; k++) cout << arr3[k] << " ";
    cout << " (size = " << n3 << ")" << endl;

    int newSize = removeOdds(arr3, n3, 0);
    cout << "Array after removeOdds: ";
    for (int k = 0; k < newSize; k++) cout << arr3[k] << " ";
    cout << " (new size = " << newSize << ")" << endl;

    // 4. Fibonacci Number
    cout << "\n--- 4. N-th Fibonacci Number ---" << endl;
    int fibTerm = 7;
    cout << "Fibonacci term " << fibTerm << " is: " << fibonacci(fibTerm) << endl;

    // 5. Binary Search
    cout << "\n--- 5. Recursive Binary Search ---" << endl;
    int sortedArr[] = {11, 22, 33, 44, 55, 66, 77};
    int nSorted = sizeof(sortedArr) / sizeof(sortedArr[0]);
    int key1 = 44, key2 = 99;
    cout << "Searching for " << key1 << ": Found at index " 
         << binarySearch(sortedArr, key1, 0, nSorted - 1) << endl;
    cout << "Searching for " << key2 << ": Found at index " 
         << binarySearch(sortedArr, key2, 0, nSorted - 1) << endl;

    // 6. Tower of Hanoi
    cout << "\n--- 6. Tower of Hanoi (3 Disks: S -> D using H) ---" << endl;
    towerOfHanoi(3, 'S', 'D', 'H');

    cout << "\n=========================================================" << endl;
    return 0;
}