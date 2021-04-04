/*
    link: https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/

    variation of kadanes algo

    refer: problem no. 35...
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int maxSubarraySum(int arr[], int n) {
    int dp[n];

    dp[0] = max(0, arr[0]);
    int omin = dp[0];
    for (int i = 1;i < n;i++) {
        // choosing either to keep the subarray continue or break and initialize with current ele.
        dp[i] = min(dp[i - 1] + arr[i], arr[i]);
        // also keeping track of highest sum achieved during the journey.
        omin = min(dp[i], omin);
    }
    return omin;
}

// ----------------------------------------------------------------------------------------------------------------------- //