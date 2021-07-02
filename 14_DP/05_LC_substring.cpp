/*
    link: https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

    variation of DP_tut/LCS/2_LC_substring...
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int memo[1001][1001];

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    // memset(memo, -1, sizeof(memo));
    // your code here
    int result = 0;
    for (int i = 0;i < n + 1;i++) memo[i][0] = 0;
    for (int j = 0;j < m + 1;j++) memo[0][j] = 0;

    for (int i = 1;i < n + 1;i++) {
        for (int j = 1;j < m + 1;j++) {
            if (s1[i - 1] == s2[j - 1]) {
                memo[i][j] = 1 + memo[i - 1][j - 1];
                result = max(result, memo[i][j]);
            }
            else {
                memo[i][j] = 0;
            }
        }
    }
    return result;
}

// ----------------------------------------------------------------------------------------------------------------------- //