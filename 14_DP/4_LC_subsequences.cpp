/*
    link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

    refer DP_tut/LCS/implementation
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// function to find longest common subsequence
int static memo[1001][1001];
int lcs(int n, int m, string s1, string s2) {

    // your code here
    for (int i = 0;i < n + 1;i++) {
        memo[i][0] = 0;
    }
    for (int j = 0;j < m + 1;j++) {
        memo[0][j] = 0;
    }
    for (int i = 1;i < n + 1;i++) {
        for (int j = 1;j < m + 1;j++) {
            if (s1[i - 1] == s2[j - 1]) {
                memo[i][j] = 1 + memo[i - 1][j - 1];
            }
            else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    return memo[n][m];
}

// ----------------------------------------------------------------------------------------------------------------------- //