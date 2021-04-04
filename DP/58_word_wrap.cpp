/*
    link: https://practice.geeksforgeeks.org/problems/word-wrap/0

    sol: https://www.geeksforgeeks.org/word-wrap-problem-dp-19/
    sol2: https://www.geeksforgeeks.org/word-wrap-problem-space-optimized-solution/
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// greedy approach (won't work as cost will be too high)
// to know how to calculate cost refer sol.
int main() {
    //code
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0;i < n;i++) {
            cin >> arr[i];
            arr[i]++;
        }
        int k;
        cin >> k;

        for (int i = 0;i < n;) {
            cout << i + 1 << " ";
            int j = i + 1;
            int sum = arr[i];
            while (j < n && sum + arr[j] <= k) {
                sum += arr[j];
                j++;
            }
            cout << j << " ";
            i = j;
        }
        cout << endl;
    }
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(n^2)
// SC: O(n^2)

// A Dynamic programming solution for Word Wrap Problem
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

// A utility function to print the solution
int printSolution(int p[], int n);

// l[] represents lengths of different words in input sequence.
// For example, l[] = {3, 2, 2, 5} is for a sentence like
// "aaa bb cc ddddd". n is size of l[] and M is line width
// (maximum no. of characters that can fit in a line)
void solveWordWrap(int l[], int n, int M)
{
    // For simplicity, 1 extra space is used in all below arrays

    // extras[i][j] will have number of extra spaces if words from i
    // to j are put in a single line
    int extras[n + 1][n + 1];

    // lc[i][j] will have cost of a line which has words from
    // i to j
    int lc[n + 1][n + 1];

    // c[i] will have total cost of optimal arrangement of words
    // from 1 to i
    int c[n + 1];

    // p[] is used to print the solution.
    int p[n + 1];

    int i, j;

    // calculate extra spaces in a single line. The value extra[i][j]
    // indicates extra spaces if words from word number i to j are
    // placed in a single line
    for (i = 1; i <= n; i++)
    {
        extras[i][i] = M - l[i - 1];
        for (j = i + 1; j <= n; j++)
            extras[i][j] = extras[i][j - 1] - l[j - 1] - 1;
    }

    // Calculate line cost corresponding to the above calculated extra
    // spaces. The value lc[i][j] indicates cost of putting words from
    // word number i to j in a single line
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && extras[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = extras[i][j] * extras[i][j];
        }
    }

    // Calculate minimum cost and find minimum cost arrangement.
    // The value c[j] indicates optimized cost to arrange words
    // from word number 1 to j.
    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
            if (c[i - 1] != INF && lc[i][j] != INF &&
                (c[i - 1] + lc[i][j] < c[j]))
            {
                c[j] = c[i - 1] + lc[i][j];
                p[j] = i;
            }
        }
    }

    printSolution(p, n);
}

int printSolution(int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution(p, p[n] - 1) + 1;
    cout << "Line number " << k << ": From word no. " << p[n] << " to " << n << endl;
    return k;
}

// Driver program to test above functions
int main()
{
    int l[] = { 3, 2, 2, 5 };
    int n = sizeof(l) / sizeof(l[0]);
    int M = 6;
    solveWordWrap(l, n, M);
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(n^2)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

// Function to find space optimized
// solution of Word Wrap problem.
void solveWordWrap(int arr[], int n, int k)
{
    int i, j;

    // Variable to store number of
    // characters in given line.
    int currlen;

    // Variable to store possible
    // minimum cost of line.
    int cost;

    // DP table in which dp[i] represents
    // cost of line starting with word
    // arr[i].
    int dp[n];

    // Array in which ans[i] store index
    // of last word in line starting with
    // word arr[i].
    int ans[n];

    // If only one word is present then
    // only one line is required. Cost
    // of last line is zero. Hence cost
    // of this line is zero. Ending point
    // is also n-1 as single word is
    // present.
    dp[n - 1] = 0;
    ans[n - 1] = n - 1;

    // Make each word first word of line
    // by iterating over each index in arr.
    for (i = n - 2; i >= 0; i--) {
        currlen = -1;
        dp[i] = INT_MAX;

        // Keep on adding words in current
        // line by iterating from starting
        // word upto last word in arr.
        for (j = i; j < n; j++) {

            // Update number of characters
            // in current line. arr[j] is
            // number of characters in
            // current word and 1
            // represents space character
            // between two words.
            currlen += (arr[j] + 1);

            // If limit of characters
            // is violated then no more
            // words can be added to
            // current line.
            if (currlen > k)
                break;

            // If current word that is
            // added to line is last
            // word of arr then current
            // line is last line. Cost of
            // last line is 0. Else cost
            // is square of extra spaces
            // plus cost of putting line
            // breaks in rest of words
            // from j+1 to n-1.
            if (j == n - 1)
                cost = 0;
            else
                cost = (k - currlen) * (k - currlen) + dp[j + 1];

            // Check if this arrangement gives
            // minimum cost for line starting
            // with word arr[i].
            if (cost < dp[i]) {
                dp[i] = cost;
                ans[i] = j;
            }
        }
    }

    // Print starting index and ending index
    // of words present in each line.
    i = 0;
    while (i < n) {
        cout << i + 1 << " " << ans[i] + 1 << " ";
        i = ans[i] + 1;
    }
}

// Driver function
int main()
{
    int arr[] = { 3, 2, 2, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int M = 6;
    solveWordWrap(arr, n, M);
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //