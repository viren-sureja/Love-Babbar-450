/*
    link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    A Simple Merge based solution to find median of two sorted arrays

    Time Complexity: O(m + n).
*/
int getMedian(int ar1[], int ar2[], int n, int m)
{
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;
    int m1 = -1, m2 = -1;

    // Since there are (n+m) elements,
    // There are following two cases
    // if n+m is odd then the middle
    //index is median i.e. (m+n)/2
    if ((m + n) % 2 == 1)
    {
        for (count = 0; count <= (n + m) / 2; count++)
        {
            if (i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if (i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return m1;
    }

    // median will be average of elements
    // at index ((m+n)/2 - 1) and (m+n)/2
    // in the array obtained after merging ar1 and ar2
    else
    {
        for (count = 0; count <= (n + m) / 2; count++)
        {
            m2 = m1;
            if (i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if (i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return (m1 + m2) / 2;
    }
}
/* Driver code */
int main()
{
    int ar1[] = { 900 };
    int ar2[] = { 5, 8, 10, 20 };

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    cout << getMedian(ar1, ar2, n1, n2);
    return 0;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    divide and conquer approach

    Time Complexity: O(min(log m, log n)).
*/
// A utility function to find median of two integers
float MO2(int a, int b)
{
    return (a + b) / 2.0;
}

// A utility function to find median of three integers
float MO3(int a, int b, int c)
{
    return a + b + c - max(a, max(b, c))
        - min(a, min(b, c));
}

// A utility function to find a median of four integers
float MO4(int a, int b, int c, int d)
{
    int Max = max(a, max(b, max(c, d)));
    int Min = min(a, min(b, min(c, d)));
    return (a + b + c + d - Max - Min) / 2.0;
}

// Utility function to find median of single array
float medianSingle(int arr[], int n)
{
    if (n == 0)
        return -1;
    if (n % 2 == 0)
        return (double)(arr[n / 2] + arr[n / 2 - 1]) / 2;
    return arr[n / 2];
}

// This function assumes that N is smaller than or equal to M
// This function returns -1 if both arrays are empty
float findMedianUtil(int A[], int N, int B[], int M)
{
    // If smaller array is empty, return median from second array
    if (N == 0)
        return medianSingle(B, M);

        // If the smaller array has only one element
    if (N == 1)
    {
        // Case 1: If the larger array also has one element,
        // simply call MO2()
        if (M == 1)
            return MO2(A[0], B[0]);

        // Case 2: If the larger array has odd number of elements,
        // then consider the middle 3 elements of larger array and
        // the only element of smaller array. Take few examples
        // like following
        // A = {9}, B[] = {5, 8, 10, 20, 30} and
        // A[] = {1}, B[] = {5, 8, 10, 20, 30}
        if (M & 1)
            return MO2(B[M / 2], MO3(A[0], B[M / 2 - 1], B[M / 2 + 1]));

        // Case 3: If the larger array has even number of element,
        // then median will be one of the following 3 elements
        // ... The middle two elements of larger array
        // ... The only element of smaller array
        return MO3(B[M / 2], B[M / 2 - 1], A[0]);
    }

    // If the smaller array has two elements
    else if (N == 2)
    {
        // Case 4: If the larger array also has two elements,
        // simply call MO4()
        if (M == 2)
            return MO4(A[0], A[1], B[0], B[1]);

        // Case 5: If the larger array has odd number of elements,
        // then median will be one of the following 3 elements
        // 1. Middle element of larger array
        // 2. Max of first element of smaller array and element
        // just before the middle in bigger array
        // 3. Min of second element of smaller array and element
        // just after the middle in bigger array
        if (M & 1)
            return MO3(B[M / 2],
                max(A[0], B[M / 2 - 1]),
                min(A[1], B[M / 2 + 1])
            );

// Case 6: If the larger array has even number of elements,
// then median will be one of the following 4 elements
// 1) & 2) The middle two elements of larger array
// 3) Max of first element of smaller array and element
// just before the first middle element in bigger array
// 4. Min of second element of smaller array and element
// just after the second middle in bigger array
        return MO4(B[M / 2],
            B[M / 2 - 1],
            max(A[0], B[M / 2 - 2]),
            min(A[1], B[M / 2 + 1])
        );
    }

    int idxA = (N - 1) / 2;
    int idxB = (M - 1) / 2;

    /* if A[idxA] <= B[idxB], then median must exist in
        A[idxA....] and B[....idxB] */
    if (A[idxA] <= B[idxB])
        return findMedianUtil(A + idxA, N / 2 + 1, B, M - idxA);

        /* if A[idxA] > B[idxB], then median must exist in
        A[...idxA] and B[idxB....] */
    return findMedianUtil(A, N / 2 + 1, B + idxA, M - idxA);
}

// A wrapper function around findMedianUtil(). This function
// makes sure that smaller array is passed as first argument
// to findMedianUtil
float findMedian(int A[], int N, int B[], int M)
{
    if (N > M)
        return findMedianUtil(B, M, A, N);

    return findMedianUtil(A, N, B, M);
}

// Driver program to test above functions
int main()
{
    int A[] = { 900 };
    int B[] = { 5, 8, 10, 20 };

    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);

    printf("%f", findMedian(A, N, B, M));
    return 0;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simple but costly solution

    Time Complexity: O(n Log n)
    Space Complexity: O(i+j)
*/
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int Solution(int arr[], int n)
{

    // If length of array is even
    if (n % 2 == 0)
    {
        int z = n / 2;
        int e = arr[z];
        int q = arr[z - 1];
        int ans = (e + q) / 2;
        return ans;
    }

    // If length if array is odd
    else
    {
        int z = round(n / 2);
        return arr[z];
    }
}

// Driver Code
int main() {

        // TODO Auto-generated method stub
    int arr1[] = { -5, 3, 6, 12, 15 };
    int arr2[] = { -12, -10, -6, -3, 4, 10 };

    int i = sizeof(arr1) / sizeof(arr1[0]);
    int j = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[i + j];
    int l = i + j;
    // Merge two array into one array
    for (int k = 0;k < i;k++)
    {
        arr3[k] = arr1[k];
    }

    for (int k = i;k < l;k++)
    {
        arr3[k] = arr2[k];
    }

    // Sort the merged array
    sort(arr3, arr3 + l);

    // calling the method
    cout << "Median = " << Solution(arr3, l);
}
