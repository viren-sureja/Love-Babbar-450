/*
    link: https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive approach
    TC: O(N*K)
    SC: O(1)
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using dequeue
    TC: O(N)
    SC: O(K)
*/
// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[], int n, int k)
{
    int sum = 0; // Initialize result

    // The queue will store indexes of useful elements
    // in every window
    // In deque 'G' we maintain decreasing order of
    // values from front to rear
    // In deque 'S' we maintain increasing order of
    // values from front to rear
    deque< int > S(k), G(k);

    // Process first window of size K
    int i = 0;
    for (i = 0; i < k; i++)
    {
        // Remove all previous greater elements
        // that are useless.
        while ((!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear

        // Remove all previous smaller that are elements
        // are useless.
        while ((!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    // Process rest of the Array elements
    for (; i < n; i++)
    {
        // Element at the front of the deque 'G' & 'S'
        // is the largest and smallest
        // element of previous window respectively
        sum += arr[S.front()] + arr[G.front()];

        // Remove all elements which are out of this
        // window
        while (!S.empty() && S.front() <= i - k)
            S.pop_front();
        while (!G.empty() && G.front() <= i - k)
            G.pop_front();

        // remove all previous greater element that are
        // useless
        while ((!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear

        // remove all previous smaller that are elements
        // are useless
        while ((!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    // Sum of minimum and maximum element of last window
    sum += arr[S.front()] + arr[G.front()];

    return sum;
}

// Driver program to test above functions
int main()
{
    int arr[] = { 2, 5, -1, 7, -3, -1, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, n, k);
    return 0;
}
