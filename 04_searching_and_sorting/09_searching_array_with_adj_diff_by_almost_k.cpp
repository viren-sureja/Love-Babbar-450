/*
    link: https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program to search an element in an array
// where difference between all elements is 1
#include<bits/stdc++.h>
using namespace std;

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    // Traverse the given array starting from
    // leftmost element
    int i = 0;
    while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;

        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i] - x) / k);
    }

    cout << "number is not present!";
    return -1;
}

// Driver program to test above function
int main()
{
    int arr[] = { 2, 4, 5, 7, 7, 6 };
    int x = 6;
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Element " << x << " is present at index "
        << search(arr, n, x, k);
    return 0;
}
