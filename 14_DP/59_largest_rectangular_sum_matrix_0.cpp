/*
    link: https://www.geeksforgeeks.org/largest-rectangular-sub-matrix-whose-sum-0/

    video: https://www.youtube.com/watch?v=eXA3F2WN3d0

    variation of 40_max_sum_rectangle_2d_matrix
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// easiest solution 
#include <bits/stdc++.h>
using namespace std;

int subsum(vector<int>& col_sum, int c) {
    int mx = 1;
    int curr_sum = 0;
    unordered_map<int, int> m;

    for (int i = 0;i < c;i++) {
        curr_sum += col_sum[i];
        if (curr_sum == 0) {
            mx = max(mx, i + 1);
        }
        else if (m[curr_sum]) {
            mx = max(mx, i - m[curr_sum] + 1);
        }
        else m[curr_sum] = i + 1;
    }
    return mx;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        int arr[r][c];
        memset(arr, 0, sizeof(arr));

        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                cin >> arr[i][j];
            }
        }

        int mx = INT_MIN;
        for (int row_lim = 0;row_lim < r;row_lim++) {
            vector<int> col_sum(c, 0);
            for (int row_curr = row_lim;row_curr < r;row_curr++) {
                for (int col = 0;col < c;col++) {
                    col_sum[col] += arr[row_curr][col];
                }
                mx = max(mx, subsum(col_sum, c) * (row_curr - row_lim + 1));
            }
        }
        cout << mx << endl;
    }
}

// ----------------------------------------------------------------------------------------------------------------------- //

// A C++ program to find Largest rectangular
// sub-matrix whose sum is 0
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// This function basically finds largest 0
// sum aubarray in temp[0..n-1]. If 0 sum
// does't exist, then it returns false. Else
// it returns true and sets starting and
// ending indexes as starti and endj.
bool sumZero(int temp[], int* starti,
    int* endj, int n)
{
    // Map to store the previous sums
    map<int, int> presum;
    int sum = 0; // Initialize sum of elements

    // Initialize length of sub-array with sum 0
    int max_length = 0;

    // Traverse through the given array
    for (int i = 0; i < n; i++)
    {
        // Add current element to sum
        sum += temp[i];

        if (temp[i] == 0 && max_length == 0)
        {
            *starti = i;
            *endj = i;
            max_length = 1;
        }
        if (sum == 0)
        {
            if (max_length < i + 1)
            {
                *starti = 0;
                *endj = i;
            }
            max_length = i + 1;
        }

        // Look for this sum in Hash table
        if (presum.find(sum) != presum.end())
        {
            // store previous max_length so
            // that we can check max_length
            // is updated or not
            int old = max_length;

            // If this sum is seen before,
            // then update max_len
            max_length = max(max_length, i - presum[sum]);

            if (old < max_length)
            {
                // If max_length is updated then
                // enter and update start and end
                // point of array
                *endj = i;
                *starti = presum[sum] + 1;
            }
        }
        else

            // Else insert this sum with
            // index in hash table
            presum[sum] = i;
    }

    // Return true if max_length is non-zero
    return (max_length != 0);
}

// The main function that finds Largest rectangle
// sub-matrix in a[][] whose sum is 0.
void sumZeroMatrix(int a[][MAX], int row, int col)
{
    int temp[row];

    // Variables to store the final output
    int fup = 0, fdown = 0, fleft = 0, fright = 0;
    int sum;
    int up, down;
    int maxl = INT_MIN;

    // Set the left column
    for (int left = 0; left < col; left++)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column
        // set by outer loop
        for (int right = left; right < col; right++)
        {
            // Calculate sum between current left
            // and right for every row 'i'
            for (int i = 0; i < row; i++)
                temp[i] += a[i][right];

            // Find largest subarray with 0 sum in
            // temp[]. The sumZero() function also
            // sets values of start and finish. So
            // 'sum' is sum of rectangle between (start,
            // left) and (finish, right) which is
            // boundary columns strictly as left and right.
            bool sum = sumZero(temp, &up, &down, row);
            int ele = (down - up + 1) * (right - left + 1);

            // Compare no. of elements with previous
            // no. of elements in sub-Matrix.
            // If new sub-matrix has more elements
            // then update maxl and final boundaries
            // like fup, fdown, fleft, fright
            if (sum && ele > maxl)
            {
                fup = up;
                fdown = down;
                fleft = left;
                fright = right;
                maxl = ele;
            }
        }
    }

    // If there is no change in boundaries
    // than check if a[0][0] is 0
    // If it not zero then print
    // that no such zero-sum sub-matrix exists
    if (fup == 0 && fdown == 0 && fleft == 0 &&
        fright == 0 && a[0][0] != 0) {
        cout << "No zero-sum sub-matrix exists";
        return;
    }

    // Print final values
    for (int j = fup; j <= fdown; j++)
    {
        for (int i = fleft; i <= fright; i++)
            cout << a[j][i] << " ";
        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    int a[][MAX] = { { 9, 7, 16, 5 }, { 1, -6, -7, 3 },
                    { 1, 8, 7, 9 }, { 7, -2, 0, 10 } };

    int row = 4, col = 4;
    sumZeroMatrix(a, row, col);
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //