/*
    link: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

    variation of LCS.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

class Solution {
    int memo[1001][1001];
public:
    int LCS(string s1, string s2, int n, int m)
    {
        for (int i = 0;i < n + 1;i++) memo[i][0] = 0;
        for (int j = 0;j < m + 1;j++) memo[0][j] = 0;

        for (int i = 1;i < n + 1;i++) {
            for (int j = 1;j < m + 1;j++) {
                if (s1[i - 1] == s2[j - 1] && i != j) {             // crux: add only if position are not same and char is same.
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                }
                else {
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                }
            }
        }
        return memo[n][m];
    }
    int LongestRepeatingSubsequence(string str) {
        // Code here
        return LCS(str, str, str.length(), str.length());
    }

};

// ----------------------------------------------------------------------------------------------------------------------- //