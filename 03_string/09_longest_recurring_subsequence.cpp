/*
    link: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

    ref: DP/8_longest_repeated...
*/


// ----------------------------------------------------------------------------------------------------------------------- //
int memo[1002][1002];
int LongestRepeatingSubsequence(string s) {
            // Code here
    int len = s.size();

    for (int i = 0;i < len;i++) {
        memo[i][0] = 0;
        memo[0][i] = 0;
    }


    for (int i = 1;i <= len;i++) {
        for (int j = 1;j <= len;j++) {
            if (s[i - 1] == s[j - 1] && i != j) {
                // if char matches and index is not same as mentioned
                memo[i][j] = 1 + memo[i - 1][j - 1];
            }
            else {
                // if not matched then carry over the max value so far
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    return memo[len][len];
}
