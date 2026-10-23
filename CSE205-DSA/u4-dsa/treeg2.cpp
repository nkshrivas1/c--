/**
 * ==============================================================================================
 *                         CSE205: DATA STRUCTURES & ALGORITHMS (DSA)
 *                     UNIT 4: RECURSION & ARRAY TECHNIQUES (GROUP 2)
 * ==============================================================================================
 * 
 * TOPICS COVERED:
 * ----------------
 * 1. Recursive Array Processing:
 *    - Reverse Order Printing
 *    - Alternating Front-and-Back Printing [0, n-1, 1, n-2, ...]
 * 2. Optimized Two-Pointer In-Place Odd Removal:
 *    - O(N) Swap-with-End Technique (vs. O(N^2) Shift Technique)
 * 3. 0-Indexed Fibonacci Series Computation (0, 1, 1, 2, 3, 5, 8...)
 * 4. Recursive Binary Search with Index Bounds
 * 5. Comprehensive Demonstration in main()
 * 
 * ==============================================================================================
 * THEORY & EXAM NOTES: GROUP 2 RECURSION VARIANTS
 * ==============================================================================================
 * 
 * 1. REMOVING ELEMENTS IN-PLACE: O(N) TWO-POINTER SWAP vs. O(N^2) SHIFTING
 *    - In Group 1, removing an odd number shifted all remaining elements left by 1 position,
 *      resulting in O(N^2) time complexity.
 *    - In Group 2, an OPTIMIZED TWO-POINTER APPROACH is used:
 *        * Left pointer 'i', right pointer 'j'.
 *        * If arr[i] is odd, replace arr[i] with arr[j], decrement j, and decrement array size n.
 *        * Check position 'i' again (as the swapped element might also be odd).
 *        * If arr[i] is even, advance i (i + 1).
 *        * Time Complexity: O(N) linear time! (Order of elements is not preserved, but in-place).
 * 
 * 2. 0-INDEXED FIBONACCI NUMBER:
 *    - Standard 0-indexed series:
 *        Index (n): 0  1  2  3  4  5  6  7   8
 *        Value:     0  1  1  2  3  5  8  13  21
 *    - Base cases:
 *        F(0) = 0
 *        F(1) = 1
 *        F(n) = F(n-1) + F(n-2) for n >= 2
 * ==============================================================================================
 */

#include <iostream>
using namespace std;

// ==============================================================================================
// 1. RECURSIVE REVERSE PRINTING
// ==============================================================================================
/**
 * Recursively prints elements from index (n-1) down to 0.
 * Time: O(N) | Space: O(N)
 */
void printReverseArray(int arr[], int n) {
    if (n == 0) return; // Base case
    cout << arr[n - 1] << " ";
    printReverseArray(arr, n - 1);
}

// ==============================================================================================
// 2. ALTERNATING EXTREME-TO-CENTER PRINTING
// ==============================================================================================
/**
 * Recursively prints: arr[0], arr[n-1], arr[1], arr[n-2]...
 * Example: {1, 2, 3, 5, 6} -> 1 6 2 5 3
 * Time: O(N) | Space: O(N)
 */
void printArray(int arr[], int i, int j) {
    if (i > j) return; // Base case
    cout << arr[i] << " ";
    if (i != j) {
        cout << arr[j] << " ";
    }
    printArray(arr, i + 1, j - 1);
}

// ==============================================================================================
// 3. OPTIMIZED IN-PLACE REMOVAL OF ODD INTEGERS: TWO-POINTER SWAP
// ==============================================================================================
/**
 * Problem: Remove odd numbers from an array in-place without extra space in O(N) time.
 * Note: Does not preserve relative order of elements.
 * 
 * Logic:
 * - Base Case: When i > j, all elements have been examined.
 * - If arr[i] is odd:
 *     Overwrite arr[i] with the element at the right end arr[j].
 *     Decrement right pointer j and array size n.
 *     Recurse with the SAME index i: removeOdd(arr, n, i, j).
 * - If arr[i] is even:
 *     Element is valid; advance left pointer: removeOdd(arr, n, i + 1, j).
 * 
 * Time: O(N) | Space: O(N) call stack
 */
void removeOdd(int arr[], int &n, int i, int j) {
    if (i > j) return; // Base case

    if (arr[i] % 2 != 0) {
        arr[i] = arr[j]; // Swap/overwrite with last element
        j--;
        n--;
        removeOdd(arr, n, i, j); // Re-examine position i
    } else {
        removeOdd(arr, n, i + 1, j); // Element is even, move forward
    }
}

// ==============================================================================================
// 4. 0-INDEXED FIBONACCI NUMBER
// ==============================================================================================
/**
 * Returns the n-th Fibonacci number (0-indexed: F(0)=0, F(1)=1).
 * Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...
 * Time: O(2^N) | Space: O(N)
 */
int fibonacci(int n) {
    if (n <= 1) return n; // Base case: F(0) = 0, F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// ==============================================================================================
// 5. RECURSIVE BINARY SEARCH
// ==============================================================================================
/**
 * Recursively searches for 'key' in a sorted array within index range [i, j].
 * Returns the index of 'key' if found, or -1 if not found.
 * Time: O(log N) | Space: O(log N)
 */
int binarySearch(int arr[], int n, int key, int i, int j) {
    // Unused parameter 'n' kept for signature compatibility
    (void)n;
    if (i > j) return -1; // Base case: not found

    int mid = i + (j - i) / 2;

    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] > key) {
        return binarySearch(arr, n, key, i, mid - 1);
    } else {
        return binarySearch(arr, n, key, mid + 1, j);
    }
}

// ==============================================================================================
// 6. MAIN FUNCTION & DEMONSTRATION
// ==============================================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "         CSE205: RECURSION (GROUP 2) DEMO                " << endl;
    cout << "=========================================================" << endl;

    // 1. Reverse Array Printing
    cout << "\n--- 1. Print Array in Reverse Order ---" << endl;
    int arr1[] = {1, 2, 3, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original array: 1 2 3 5 6" << endl;
    cout << "Reversed: ";
    printReverseArray(arr1, n1);
    cout << endl;

    // 2. Alternating Print
    cout << "\n--- 2. Alternating Extreme-to-Center Print ---" << endl;
    cout << "Alternating order: ";
    printArray(arr1, 0, n1 - 1);
    cout << endl;

    // 3. Two-Pointer In-Place Odd Removal
    cout << "\n--- 3. Two-Pointer In-Place Remove Odds ---" << endl;
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Before removal: ";
    for (int k = 0; k < n2; k++) cout << arr2[k] << " ";
    cout << " (size = " << n2 << ")" << endl;

    removeOdd(arr2, n2, 0, n2 - 1);

    cout << "After removal:  ";
    for (int k = 0; k < n2; k++) cout << arr2[k] << " ";
    cout << " (new size = " << n2 << ")" << endl;

    // 4. Fibonacci Calculation
    cout << "\n--- 4. 0-Indexed Fibonacci ---" << endl;
    for (int term = 0; term <= 7; term++) {
        cout << "F(" << term << ") = " << fibonacci(term) << "  ";
    }
    cout << endl;

    // 5. Binary Search
    cout << "\n--- 5. Recursive Binary Search ---" << endl;
    int sortedArr[] = {10, 20, 30, 40, 50, 60};
    int nSorted = sizeof(sortedArr) / sizeof(sortedArr[0]);
    int key = 40;
    int foundIndex = binarySearch(sortedArr, nSorted, key, 0, nSorted - 1);
    cout << "Searching for " << key << " in {10, 20, 30, 40, 50, 60}: Found at index " << foundIndex << endl;

    cout << "\n=========================================================" << endl;
    return 0;
}