/*
    link: https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1

    sol: https://www.geeksforgeeks.org/sort-array-according-count-set-bits/
    sol2: https://www.geeksforgeeks.org/sort-an-array-according-to-count-of-set-bits-set-2/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*

*/
// C++ program to implement simple approach to sort
// an array according to count of set bits.
#include <iostream>

using namespace std;

// a utility function that returns total set bits
// count in an integer
int countBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}

// Function to simultaneously sort both arrays
// using insertion sort
// ( http://quiz.geeksforgeeks.org/insertion-sort/ )
void insertionSort(int arr[], int aux[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // use 2 keys because we need to sort both
        // arrays simultaneously
        int key1 = aux[i];
        int key2 = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1] and aux[0..i-1],
        such that elements of aux[0..i-1] are
        greater than key1, to one position ahead
        of their current position */
        while (j >= 0 && aux[j] < key1)
        {
            aux[j + 1] = aux[j];
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        aux[j + 1] = key1;
        arr[j + 1] = key2;
    }
}

// Function to sort according to bit count using
// an auxiliary array
void sortBySetBitCount(int arr[], int n)
{
    // Create an array and store count of
    // set bits in it.
    int aux[n];
    for (int i = 0; i < n; i++)
        aux[i] = countBits(arr[i]);

    // Sort arr[] according to values in aux[]
    insertionSort(arr, aux, n);
}

// Utility function to print an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*

*/
// C++ program to sort an array according to
// count of set bits using std::sort()
#include <bits/stdc++.h>

using namespace std;

// a utility function that returns total set bits
// count in an integer
int countBits(int a)
{
    int count = 0;
    while (a) {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}

// custom comparator of std::sort
int cmp(int a, int b)
{
    int count1 = countBits(a);
    int count2 = countBits(b);

    // this takes care of the stability of
    // sorting algorithm too
    if (count1 <= count2)
        return false;
    return true;
}

// Function to sort according to bit count using
// std::sort
void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr + n, cmp);
}

// Utility function to print an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*

*/
// C++ program to sort an array according to
// count of set bits using std::sort()
#include <bits/stdc++.h>
using namespace std;

// a utility function that returns total set bits
// count in an integer
int countBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}

// Function to sort according to bit count
// This function assumes that there are 32
// bits in an integer.
void sortBySetBitCount(int arr[], int n)
{
    vector<vector<int> > count(32);
    int setbitcount = 0;
    for (int i = 0; i < n; i++)
    {
        setbitcount = countBits(arr[i]);
        count[setbitcount].push_back(arr[i]);
    }

    int j = 0; // Used as an index in final sorted array

    // Traverse through all bit counts (Note that we
    // sort array in decreasing order)
    for (int i = 31; i >= 0; i--)
    {
        vector<int> v1 = count[i];
        for (int i = 0; i < v1.size(); i++)
            arr[j++] = v1[i];
    }
}

// Utility function to print an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time complexity: O(n log n)
    Auxiliary Space: O(n)
*/
// C++ program to implement
// simple approach to sort
// an array according to
// count of set bits.
#include<bits/stdc++.h>
using namespace std;

// Function to count setbits
int setBitCount(int num) {
    int count = 0;
    while (num)
    {
        if (num & 1)
            count++;
        num >>= 1;
    }
    return count;
}

// Function to sort By SetBitCount
void sortBySetBitCount(int arr[], int n)
{
    multimap< int, int > count;

    // Iterate over all values and
    // insert into multimap
    for (int i = 0; i < n; ++i)
    {
        count.insert({ (-1) *
            setBitCount(arr[i]), arr[i] });
    }

    for (auto i : count)
        cout << i.second << " ";
    cout << "\n";
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*

*/
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// function to sort the array according
// to the number of set bits in elements
void sortArr(int arr[], int n)
{
    multimap<int, int> map;

    for (int i = 0; i < n; i++) {
        int count = 0;
        int k = arr[i];

        // Counting no of setBits in arr[i]
        while (k) {
            k = k & k - 1;
            count++;
        }

        // The count is subtracted from 32
        // because the result needs
        // to be in descending order
        map.insert(make_pair(32 - count, arr[i]));
    }

    // Printing the numbers in descending
    // order of set bit count
    for (auto it = map.begin(); it != map.end(); it++) {
        cout << (*it).second << " ";
    }
}

// Driver code
int main()
{
    int arr[] = { 5, 2, 3, 9, 4, 6, 7, 15, 32 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArr(arr, n);

    return 0;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using inbuilt lib
*/

static bool comp(int a, int b) {
    return __builtin_popcount(a) > __builtin_popcount(b);
}
void sortBySetBitCount(int arr[], int n) {
    stable_sort(arr, arr + n, comp);
}
