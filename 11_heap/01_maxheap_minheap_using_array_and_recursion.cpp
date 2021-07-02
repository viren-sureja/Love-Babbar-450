/*
    link: https://www.geeksforgeeks.org/building-heap-from-array/

    Time Complexity: Heapify a single node takes O(log N) [as every jump will be to child]
     time complexity where N is the total number of Nodes. Therefore, building the entire Heap
    will take N heapify operations and the total time complexity will be O(N*logN).

    In reality, building a heap takes O(n) time depending on the implementation which can be seen here.
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program for building Heap from Array

#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}



/*

to build min Heap

void heapify(int arr[], int i)
{
    int smallest = i; // The node which will be heapified
    int l = 2 * i + 1; // left child node
    int r = 2 * i + 2; // right child node

    // Check if left child is smaller than its parent
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    // Check if right child is smaller than smallest
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    // If smallest is not parent
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, smallest);
    }
}

*/


// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node  [parent of last leaf node]
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}


// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver Code
int main()
{
    // Binary Tree Representation
    // of input array
    // 1
    //		 /	 \
	// 3		 5
    //	 / \	 / \
	// 4	 6 13 10
    // / \ / \
	// 9 8 15 17
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);

    printHeap(arr, n);
    // Final Heap:
    // 17
    //		 /	 \
	// 15		 13
    //	 / \	 / \
	// 9	 6 5 10
    //	 / \ / \
	// 4 8 3 1

    return 0;
}
