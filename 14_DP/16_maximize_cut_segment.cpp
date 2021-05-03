/*
    link: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

    variation: unbounded DP
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// tabulation
vector<int> dp;
int recur(int n, int x, int y, int z)
{
    if (n <= 0) return 0;
    if (dp[n] != -1) return dp[n];
    int a = INT_MIN - 1, b = INT_MIN - 1, c = INT_MIN - 1;
    if (n >= x) a = recur(n - x, x, y, z);
    if (n >= y) b = recur(n - y, x, y, z);
    if (n >= z) c = recur(n - z, x, y, z);

    // note: if no length can cut the segment than return INT_MIN.
    return dp[n] = 1 + max({ a, b, c });
}
int maximizeTheCuts(int n, int x, int y, int z) {
    // memset(dp, -1, sizeof(dp));
    dp = vector<int>(n + 1, -1);
    int a = recur(n, x, y, z);
    return (a < 0) ? 0 : a;
}

// ----------------------------------------------------------------------------------------------------------------------- //