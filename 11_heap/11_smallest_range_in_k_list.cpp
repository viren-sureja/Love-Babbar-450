/*
    link: https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

    sol (refer 2nd sol. with minHeap from scratch):
    https://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    keeping pointer of every K sorted array

    Time complexity : O(n * k2),
        to find the maximum and minimum in an array of length k the time required is O(k),
        and to traverse all the k arrays of length n (in worst case), the time complexity is O(n*k),
        then the total time complexity is O(n*k2).

    Space complexity: O(k), an extra array is required of length k so the space complexity is O(k)

*/
// C++ program to finds out smallest range that includes
// elements from each of the given sorted lists.
#include <bits/stdc++.h>

using namespace std;

#define N 5

// array for storing the current index of list i
int ptr[501];

// This function takes an k sorted lists in the form of
// 2D array as an argument. It finds out smallest range
// that includes elements from each of the k lists.
void findSmallestRange(int arr[][N], int n, int k)
{
    int i, minval, maxval, minrange, minel, maxel, flag, minind;

    // initializing to 0 index;
    for (i = 0; i <= k; i++)
        ptr[i] = 0;

    minrange = INT_MAX;

    while (1) {
        // for maintaining the index of list containing the minimum element
        minind = -1;
        minval = INT_MAX;
        maxval = INT_MIN;
        flag = 0;

        // iterating over all the list
        for (i = 0; i < k; i++) {
            // if every element of list[i] is traversed then break the loop
            if (ptr[i] == n) {
                flag = 1;
                break;
            }
            // find minimum value among all the list elements pointing by the ptr[] array
            if (ptr[i] < n && arr[i][ptr[i]] < minval) {
                minind = i; // update the index of the list
                minval = arr[i][ptr[i]];
            }
            // find maximum value among all the list elements pointing by the ptr[] array
            if (ptr[i] < n && arr[i][ptr[i]] > maxval) {
                maxval = arr[i][ptr[i]];
            }
        }

        // if any list exhaust we will not get any better answer, so break the while loop
        if (flag)
            break;

        ptr[minind]++;

        // updating the minrange
        if ((maxval - minval) < minrange) {
            minel = minval;
            maxel = maxval;
            minrange = maxel - minel;
        }
    }

    printf("The smallest range is [%d, %d]\n", minel, maxel);
}

// Driver program to test above function
int main()
{
    int arr[][N] = {
        { 4, 7, 9, 12, 15 },
        { 0, 8, 10, 14, 20 },
        { 6, 12, 16, 30, 50 }
    };

    int k = sizeof(arr) / sizeof(arr[0]);

    findSmallestRange(arr, N, k);

    return 0;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using minHeap

    Time complexity : O(n * k *log k).
        To find the maximum and minimum in an Min Heap of length k the time required is O(log k),
        and to traverse all the k arrays of length n (in worst case),
        the time complexity is O(n*k), then the total time complexity is O(n * k *log k).

    Space complexity: O(k).
        The priority queue will store k elements so the space complexity os O(k)
*/
typedef pair<int, pair<int, int>> pii;

pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{
    priority_queue<pii, vector<pii>, greater<pii>> minH;

    int mx = INT_MIN, range = INT_MAX, minEle, maxEle;

    for (int i = 0;i < k;i++) {
        minH.push({ arr[i][0], {i, 0} });
        if (mx < arr[i][0]) {
            mx = arr[i][0];
        }
    }

    while (!minH.empty()) {
        pii curr = minH.top();

        minH.pop();

        if (range > mx - curr.first) {
            range = mx - curr.first;
            maxEle = mx;
            minEle = curr.first;
        }

        int row = curr.second.first;
        int col = curr.second.second;

        if (col < n) {
            mx = max(arr[row][col + 1], mx);
            minH.push({ arr[row][col + 1], {row, col + 1} });
        }
        else break;
    }

    return { minEle, maxEle };
}
