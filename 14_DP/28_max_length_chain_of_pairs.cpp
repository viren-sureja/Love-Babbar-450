/*
    link: https://practice.geeksforgeeks.org/problems/max-length-chain/1#
    sol: https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/

    variation of LIS.

    refer: DP_tut/6_LIS/4_maxi...

    note: generally we dont require to sort the pair but to pass the sol. in gfg we have to sort according to first value of every pair.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

bool compare(struct val a, struct val b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int maxChainLen(struct val arr[], int n)
{
    sort(arr, arr + n, compare);
    int dp[n];
    dp[0] = 1;
    int omax = 1;
    for (int i = 1;i < n;i++) {
        dp[i] = 1;
        for (int j = 0;j < i;j++) {
            // simple LIS but with Pair
            if (arr[i].first > arr[j].second) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        omax = max(dp[i], omax);
    }
    return omax;
}

// ----------------------------------------------------------------------------------------------------------------------- //