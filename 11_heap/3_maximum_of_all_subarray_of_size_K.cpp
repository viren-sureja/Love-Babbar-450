/*
    link: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

    note: there are 4 method given in the link

    1. naive (using loop for sliding window): TC: O(N * K), SC: O(1)
    2. self-balancing BST: TC: O(N * logN), SC: O(K)
    3. Deque: TC: O(N), SC: O(K)
    4. modified queue imple. using 2 stack: TC: O(N), SC: O(K)
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using maxHeap

    TC: O(N)
    SC: O(K)
*/

// Method to find the maximum for each
// and every contiguous subarray of size k.
void printMax(int arr[], int n, int k) {
    priority_queue<int> maxHeap;

    // push all the elem. of first window
    for (int i = 0;i < k;i++) maxHeap.push(arr[i]);


    for (int i = k;i < n;i++) {
        cout << maxHeap.top() << endl;
        maxHeap.pop();
        maxHeap.push(arr[i]);
    }
}

// Driver code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}