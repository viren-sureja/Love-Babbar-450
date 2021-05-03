/*
    link: https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0#

    video: https://www.youtube.com/watch?v=kKEX4P53MyY
*/

// ----------------------------------------------------------------------------------------------------------------------- //

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& col_sum, int c) {
    int mx = INT_MIN;
    int curr_sum = 0;
    for (int i = 0;i < c;i++) {
        curr_sum += col_sum[i];
        mx = max(mx, curr_sum);
        if (curr_sum < 0) curr_sum = 0;
    }
    return mx;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long r, c;
        cin >> r >> c;
        long long arr[r][c];
        memset(arr, 0, sizeof(arr));

        for (long long i = 0;i < r;i++) {
            for (long long j = 0;j < c;j++) {
                cin >> arr[i][j];
            }
        }

        int mx = INT_MIN;
        for (long long row_lim = 0;row_lim < r;row_lim++) {
            vector<int> col_sum(c, 0);
            for (long long row_curr = row_lim;row_curr < r;row_curr++) {
                for (long long col = 0;col < c;col++) {
                    col_sum[col] += arr[row_curr][col];
                }
                mx = max(mx, kadane(col_sum, c));
            }
        }
        cout << mx << endl;
    }
}

// ----------------------------------------------------------------------------------------------------------------------- //

// Program to find maximum sum subarray
// in a given 2D array
#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

// Implementation of Kadane's algorithm for
// 1D array. The function returns the maximum
// sum and stores starting and ending indexes
// of the maximum sum subarray at addresses
// pointed by start and finish pointers
// respectively.
int kadane(int* arr, int* start, int* finish, int n)
{
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check
    // for all negative values case
    *finish = -1;

    // local variable
    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    // There is at-least one
    // non-negative number
    if (*finish != -1)
        return maxSum;

    // Special Case: When all numbers
    // in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

// The main function that finds
// maximum sum rectangle in M[][]
void findMaxSum(int M[][COL])
{
    // Variables to store the final output
    int maxSum = INT_MIN,
        finalLeft,
        finalRight,
        finalTop,
        finalBottom;

    int left, right, i;
    int temp[ROW], sum, start, finish;

    // Set the left column
    for (left = 0; left < COL; ++left) {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left
        // column set by outer loop
        for (right = left; right < COL; ++right) {

            // Calculate sum between current left
            // and right for every row 'i'
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            // Find the maximum sum subarray in temp[].
            // The kadane() function also sets values
            // of start and finish. So 'sum' is sum of
            // rectangle between (start, left) and
            // (finish, right) which is the maximum sum
            // with boundary columns strictly as left
            // and right.
            sum = kadane(temp, &start, &finish, ROW);

            // Compare sum with maximum sum so far.
            // If sum is more, then update maxSum and
            // other output values
            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    // Print final values
    cout << "(Top, Left) ("
        << finalTop << ", "
        << finalLeft
        << ")" << endl;
    cout << "(Bottom, Right) ("
        << finalBottom << ", "
        << finalRight << ")" << endl;
    cout << "Max sum is: " << maxSum << endl;
}

// Driver Code
int main()
{
    int M[ROW][COL] = { { 1, 2, -1, -4, -20 },
                        { -8, -3, 4, 2, 1 },
                        { 3, 8, 10, 1, 3 },
                        { -4, -1, 1, 7, -6 } };

    // Function call
    findMaxSum(M);

    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //