/*
    link: https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

    sol: https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/

    both way are correct,
    as in first code, whole first row is pushed and then each elem. of col. is pushed
    as in second code, whole first col is pushed and then each elem. of row is pushed
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    kth largest element in a 2d array sorted row-wise and column-wise

    Time Complexity: The above solution involves following steps.
        1. Building a min-heap which takes O(n) time
        2. Heapify k times which takes O(k Logn) time.
    Space Complexity: O(R), where R is the length of a row, as the Min-Heap stores one row at a time.
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}
// } Driver Code Ends

// A structure to store an entry of heap.  The entry contains
// a value from 2D array, row and column numbers of the value
struct HeapNode {
    int val;  // value to be stored
    int r;    // Row number of value in 2D array
    int c;    // Column number of value in 2D array
};

// A utility function to swap two HeapNode items.
void swap(HeapNode* x, HeapNode* y) {
    HeapNode z = *x;
    *x = *y;
    *y = z;
}

// A utility function to minheapify the node harr[i] of a heap
// stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int smallest = i;
    if (l < heap_size && harr[l].val < harr[i].val)
        smallest = l;
    if (r < heap_size && harr[r].val < harr[smallest].val)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(harr, smallest, heap_size);
    }
}

// A utility function to convert harr[] to a min heap
void buildHeap(HeapNode harr[], int n)
{
    // last parent node (ofc it is not leaf node)
    int i = (n - 1) / 2;
    while (i >= 0)
    {
        minHeapify(harr, i, n);
        i--;
    }
}



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // k must be greater than 0 and smaller than n*n
    if (k <= 0 || k > n * n)
        return INT_MAX;

     // Create a min heap of elements from first row of 2D array
    HeapNode harr[n];
    for (int i = 0; i < n; i++)
        harr[i] = { mat[0][i], 0, i };
    buildHeap(harr, n);

    HeapNode hr;
    for (int i = 0; i < k; i++)
    {
       // Get current heap root
        hr = harr[0];

        // Get next value from column of root's value. If the
        // value stored at root was last value in its column,
        // then assign INFINITE as next value
        int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c] : INT_MAX;

        // Update heap root with next value
        harr[0] = { nextval, (hr.r) + 1, hr.c };

        // Heapify root
        minHeapify(harr, 0, n);
    }

    // Return the value at last extracted root
    return hr.val;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using in-built priority-queue
*/
// kth largest element in a 2d array sorted row-wise and
// column-wise
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int mat[4][4], int n, int k)
{
    // USING LAMBDA FUNCTION
    // [=] IN LAMBDA FUNCTION IS FOR CAPTURING VARIABLES WHICH
    // ARE OUT OF SCOPE i.e. mat[r]
    // NOW, IT'LL COMPARE ELEMENTS OF HEAP BY ELEMENTS AT mat[first][second]
    auto cmp = [=](pair<int, int> a, pair<int, int> b) {
        return mat[a.first][a.second] > mat[b.first][b.second];
    };

    //DECLARING priority_queue AND PUSHING FIRST ROW IN IT
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++) {
        pq.push({ i,0 });
    }

    //RUNNING LOOP FOR (k-1) TIMES
    for (int i = 1; i < k; i++) {
        auto p = pq.top();
        pq.pop();

        //AFTER POPPING, WE'LL PUSH NEXT ELEMENT OF THE ROW IN THE HEAP
        if (p.second + 1 < n) pq.push({ p.first,p.second + 1 });
    }
    // ON THE k'th ITERATION, pq.top() will be our answer.
    return mat[pq.top().first][pq.top().second];
}

// driver program to test above function
int main()
{
    int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    cout << "7th smallest element is "
        << kthSmallest(mat, 4, 7);
    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using binary-search

    TC: O(N logN)
    SC: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

// This returns count of elements in matrix less than of equal to num
int getElementsGreaterThanOrEqual(int num, int n, int mat[4][4]) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        // if num is less than the first element then no more element in matrix
        // further are less than or equal to num
        if (mat[i][0] > num) {
            return ans;
        }
        // if num is greater than last element, it is greater than all elements
        // in that row
        if (mat[i][n - 1] <= num) {
            ans += n;
            continue;
        }
        // This contain the col index of last element in matrix less than of equal
        // to num
        int greaterThan = 0;
        for (int jump = n / 2; jump >= 1; jump /= 2) {
            while (greaterThan + jump < n &&
                mat[i][greaterThan + jump] <= num) {
                greaterThan += jump;
            }
        }

        ans += greaterThan + 1;
    }
    return ans;
}

// reuturs kth smallest index in the matrix
int kthSmallest(int mat[4][4], int n, int k) {
    // We know the answer lies between the first and the last element
    // So do a binary search on answer based on the number of elements
    // our current element is greater than the elements in the matrix
    int l = mat[0][0], r = mat[n - 1][n - 1];

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);

        if (greaterThanOrEqualMid >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main() {
    int n = 4;
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50},
    };
    cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}
