/*
    link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
int maxSubarraySum(int arr[], int n) {
    int dp[n];
    dp[0] = max(INT_MIN, arr[0]);
    int omax = dp[0];

    for (int i = 1;i < n;i++) {

        dp[i] = max(arr[i] + dp[i - 1], arr[i]);

        omax = max(dp[i], omax);
    }
    return omax;
}