/*
    link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

    video (recommended to save time): https://youtu.be/kQ1mJlwW-c0

    condition here is convertion counts if (arr[i]>arr[j] && i<j) <-- keep this in mind everytime
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(n^2),
    Two nested loops are needed to traverse the array from start to end, so the Time complexity is O(n^2)
    Space Complexity:O(1), No extra space is required.
*/
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long ans = 0LL;
    for (int i = 0;i < N;i++) {
        for (int j = i + 1;j < N;j++) {
            if (arr[j] < arr[i]) ans++;
        }
    }
    return ans;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(n log n),
        The algorithm used is divide and conquer, So in each level,
        one full array traversal is needed, and there are log n levels,
        so the time complexity is O(n log n).
    Space Complexity: O(n), Temporary array.

    just trace it and it will be easy to understand
*/


// This func merges two sorted arrays and returns inversion count in the arrays.
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            /* this is tricky -- see above explanation/diagram for merge()*/
            inv_count += mid - i;
        }
    }

    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
    (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}


/* An auxiliary recursive function that sorts the input array and returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and call _mergeSortAndCountInv() for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of inversions in left-part, right-part and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// Driver code
int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int ans = _mergeSort(arr, temp, 0, n - 1);
    cout << " Number of inversions are " << ans;
    return 0;
}
