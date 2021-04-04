/*
    link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// memoization with global
int static memo[1001][1001];
int recur(int w, int wt[], int val[], int n) {
    if (n == 0 || w == 0) return 0;
    if (memo[n][w] != -1) return memo[n][w];
    if (wt[n - 1] <= w) {
        return memo[n][w] = max(val[n - 1] + recur(w - wt[n - 1], wt, val, n - 1), recur(w, wt, val, n - 1));
    }
    else if (wt[n - 1] > w) {
        return memo[n][w] = recur(w, wt, val, n - 1);
    }
}
int knapSack(int w, int wt[], int val[], int n)
{
    memset(memo, -1, sizeof(memo));
    recur(w, wt, val, n);
    return memo[n][w];
}

// ----------------------------------------------------------------------------------------------------------------------- //

// memoization with global (another way, code is just same as above)
vector<vector<int>> memo;
int recur(int w, int wt[], int val[], int n) {
    if (n == 0 || w == 0) return 0;
    if (memo[n][w] != -1) return memo[n][w];
    if (wt[n - 1] <= w) {
        return memo[n][w] = max(val[n - 1] + recur(w - wt[n - 1], wt, val, n - 1), recur(w, wt, val, n - 1));
    }
    else if (wt[n - 1] > w) {
        return memo[n][w] = recur(w, wt, val, n - 1);
    }
}
int knapSack(int w, int wt[], int val[], int n)
{
    memo = vector<vector<int>>(n + 1, vector<int>(w + 1, -1));

    return recur(w, wt, val, n);
}

// ----------------------------------------------------------------------------------------------------------------------- //

// memoization (another way, code is just same as above)
int recur(int w, int wt[], int val[], int n, vector<vector<int>>& memo) {
    if (n == 0 || w == 0) return 0;
    if (memo[n][w] != -1) return memo[n][w];
    if (wt[n - 1] <= w) {
        return memo[n][w] = max(val[n - 1] + recur(w - wt[n - 1], wt, val, n - 1, memo), recur(w, wt, val, n - 1, memo));
    }
    else if (wt[n - 1] > w) {
        return memo[n][w] = recur(w, wt, val, n - 1, memo);
    }
}
int knapSack(int w, int wt[], int val[], int n)
{
    vector<vector<int>> memo;
    memo.resize(n + 1, vector<int>(w + 1, -1));

    return recur(w, wt, val, n, memo);
}

// ----------------------------------------------------------------------------------------------------------------------- //

// tabulation
int knapSack(int w, int wt[], int val[], int n)
{
    vector<vector<int>> memo;
    memo.resize(n + 1, vector<int>(w + 1, -1));
    for (int i = 0;i < n + 1;i++) {
        memo[i][0] = 0;
    }
    for (int j = 0;j < w + 1;j++) {
        memo[0][j] = 0;
    }

    for (int i = 1;i < n + 1;i++) {
        for (int j = 1;j < w + 1;j++) {
            if (wt[i - 1] <= j) {
                memo[i][j] = max(val[i - 1] + memo[i - 1][j - wt[i - 1]], memo[i - 1][j]);
            }
            else {
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
    return memo[n][w];
}

// ----------------------------------------------------------------------------------------------------------------------- //