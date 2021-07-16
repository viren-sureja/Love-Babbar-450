/*
    link: https://practice.geeksforgeeks.org/problems/max-rectangle/1#

    sol: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

    video(watch just for the animation from here): https://youtu.be/hGl8Boeb7S4?t=70
*/



// ----------------------------------------------------------------------------------------------------------------------- //
#include <bits/stdc++.h>
using namespace std;

// Finds the maximum area under
// the histogram represented
// by histogram. See below article for details.
class Solution {
    public:
    int mhist(int row[], int m1) {
        // Create an empty stack.
        // The stack holds indexes of
        // hist[] array/ The bars stored
        // in stack are always
        // in increasing order of their heights.
        stack<int> result;

        int top_val;  // Top of stack

        int max_area = 0;  // Initialize max area in current

        int area = 0; // Initialize area with current top

        int i = 0;

        // Run through all bars of given histogram (or row)
        for (i = 0; i < m1;) {
            // If this bar is higher than the bar on top stack,
            // push it to stack
            if (result.empty() || row[result.top()] <= row[i])
                result.push(i++);

            else {
                // If this bar is lower than top of stack, then
                // calculate area of rectangle with stack top as
                // the smallest (or minimum height) bar. 'i' is
                // 'right index' for the top and element before
                // top in stack is 'left index'
                top_val = row[result.top()];
                result.pop();

                // this will be understood after watching the video
                area = row[top_val] * (result.empty() ? i : i - result.top() - 1);

                max_area = max(area, max_area);
            }
        }

        // Now pop the remaining bars from stack and calculate
        // area with every popped bar as the smallest bar
        while (!result.empty()) {
            top_val = row[result.top()];
            result.pop();

            area = row[top_val] * (result.empty() ? i : i - result.top() - 1);

            max_area = max(area, max_area);
        }
        return max_area;
    }


    // Returns area of the largest rectangle with all 1s in
    // A[][]
    int kewl(int M[MAX][MAX], int n, int m) {
        // Calculate area for first row and initialize it as
        // result
        int res = mhist(M[0], m);

        // iterate over row to find maximum rectangular area
        // considering each row as histogram
        for (int i = 1; i < n; i++) {

            // just to update the current row
            for (int j = 0; j < m; j++) {
                // if it's 1 then add the prev value to current else leave it
                if (M[i][j]) M[i][j] += M[i - 1][j];
            }

            // Update result if area with current row (as last
            // row) of rectangle) is more
            res = max(res, mhist(M[i], m));
        }
        return res;
    }


    // main function
    int maxArea(int M[MAX][MAX], int n, int m) {
        return kewl(M, n, m);
    }
};
