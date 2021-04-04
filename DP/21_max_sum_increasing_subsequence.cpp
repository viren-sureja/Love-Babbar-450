/*
    link: https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

    variation of LIS but here we have to return value's sum and not count...
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int maxSumIS(int arr[], int n)
{
    int dp[n];
    dp[0] = arr[0];
    int omax = arr[0];
    for (int i = 1;i < n;i++) {
        dp[i] = arr[i];
        for (int j = 0;j < i;j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], arr[i] + dp[j]); // this time we adding value of current value + prev highest value sum.
            }
        }
        omax = max(omax, dp[i]);
    }
    return omax;
}

// ----------------------------------------------------------------------------------------------------------------------- //