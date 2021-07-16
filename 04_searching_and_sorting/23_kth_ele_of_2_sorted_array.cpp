/*
    link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(n)
    Auxiliary Space : O(m + n)
*/
int kth(int arr1[], int arr2[], int m, int n, int k)
{
    int sorted1[m + n];
    int i = 0, j = 0, d = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            sorted1[d++] = arr1[i++];
        else
            sorted1[d++] = arr2[j++];
    }
    while (i < m)
        sorted1[d++] = arr1[i++];
    while (j < n)
        sorted1[d++] = arr2[j++];
    return sorted1[k - 1];
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(k)
    Auxiliary Space: O(1)
*/
int find(int A[], int B[], int m, int n, int k_req)
{
    int k = 0, i = 0, j = 0;

    // Keep taking smaller of the current
    // elements of two sorted arrays and
    // keep incrementing k
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            k++;
            if (k == k_req) return A[i];
            i++;
        }
        else
        {
            k++;
            if (k == k_req) return B[j];
            j++;
        }
    }

    // If array B[] is completely traversed
    while (i < m)
    {
        k++;
        if (k == k_req) return A[i];
        i++;
    }

    // If array A[] is completely traversed
    while (j < n)
    {
        k++;
        if (k == k_req) return B[j];
        j++;
    }
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(log n + log m)
    SC: O(1)
*/
int kth(int* arr1, int* arr2, int* end1, int* end2, int k)
{
    if (arr1 == end1)
        return arr2[k];
    if (arr2 == end2)
        return arr1[k];
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if (mid1 + mid2 < k)
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2 + mid2 + 1, end1, end2,
                k - mid2 - 1);
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2,
                k - mid1 - 1);
    }
    else
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k);
    }
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(log k)
*/
int kth(int arr1[], int arr2[], int m, int n, int k,
    int st1 = 0, int st2 = 0)
{
    // In case we have reached end of array 1
    if (st1 == m)
        return arr2[st2 + k - 1];

    // In case we have reached end of array 2
    if (st2 == n)
        return arr1[st1 + k - 1];

    // k should never reach 0 or exceed sizes
    // of arrays
    if (k == 0 || k > (m - st1) + (n - st2))
        return -1;

    // Compare first elements of arrays and return
    if (k == 1)
        return (arr1[st1] < arr2[st2]) ?
        arr1[st1] : arr2[st2];
    int curr = k / 2;

    // Size of array 1 is less than k / 2
    if (curr - 1 >= m - st1)
    {
        // Last element of array 1 is not kth
        // We can directly return the (k - m)th
        // element in array 2
        if (arr1[m - 1] < arr2[st2 + curr - 1])
            return arr2[st2 + (k - (m - st1) - 1)];
        else
            return kth(arr1, arr2, m, n, k - curr,
                st1, st2 + curr);
    }

    // Size of array 2 is less than k / 2
    if (curr - 1 >= n - st2)
    {
        if (arr2[n - 1] < arr1[st1 + curr - 1])
            return arr1[st1 + (k - (n - st2) - 1)];
        else
            return kth(arr1, arr2, m, n, k - curr,
                st1 + curr, st2);
    }
    else
    {
        // Normal comparison, move starting index
        // of one array k / 2 to the right
        if (arr1[curr + st1 - 1] < arr2[curr + st2 - 1])
            return kth(arr1, arr2, m, n, k - curr,
                st1 + curr, st2);
        else
            return kth(arr1, arr2, m, n, k - curr,
                st1, st2 + curr);
    }
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using min-heap
    Time Complexity: O(NlogN)
    Space Complexity: O(m+n)
*/
int kth(int* a, int* b, int n, int m, int k)
{
    // Declaring a min heap
    priority_queue<int, vector<int>, greater<int> > pq;

// Pushing elements for
// array a to min-heap
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    // Pushing elements for
    // array b to min-heap
    for (int i = 0; i < m; i++) {
        pq.push(b[i]);
    }

    // Poping-out K-1 elements
    while (k-- > 1) {
        pq.pop();
    }
    return pq.top();
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using max-heap
    Time Complexity: O(N logK)
    Space Complexity: O(K)
*/
int kth(int* a, int* b, int n, int m, int k)
{
    // Declaring a max heap
    priority_queue<int> pq;

    // Pushing elements in max heap so to remove un-necessary max ele from top.
    while (i < n && j < m) {
        pq.push(a[i++]);
        if (pq.size() > k) pq.pop();

        pq.push(b[j++]);
        if (pq.size() > k) pq.pop();
    }

    return pq.top();
}
