/*
    link: https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1

    variation of LIS.

    note: it's asked longest not total.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int longestSubsequence(int n, int arr[])
{
    int dp[n];
    dp[0] = 1;
    int omax = 1;
    for (int i = 1;i < n;i++) {
        dp[i] = 1;
        for (int j = 0;j < i;j++) {
            if (abs(arr[i] - arr[j]) == 1) {
                // this time just check if element's diff with current_ele is 1 
                // and hence add 1 more to that count.
                // but why max? : as sometimes it might happen current ele is part of many chain
                // hence choose the longest.
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        omax = max(dp[i], omax);
    }
    return omax;
}

// ----------------------------------------------------------------------------------------------------------------------- //