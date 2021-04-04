/*
    link: https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    // Your code goes here 
    sort(arr, arr + n);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;  // doesn't exist
    dp[1] = 0;  // single can't be counted

    for (int i = 2;i < n + 1;i++) {
        /*
            checking if to continue the prev sum ignoring the element for pair OR
            making pair with prev ele and adding to the prev's prev sum dp[i-2] and then take out max.
        */
        if (arr[i - 1] - arr[i - 2] < k) {
            dp[i] = max(dp[i - 1], arr[i - 1] + arr[i - 2] + dp[i - 2]);
        }
        /* as above condition is not met we r forced to continue with prev sum */
        else dp[i] = dp[i - 1];
    }
    return dp[n];
}

// ----------------------------------------------------------------------------------------------------------------------- //