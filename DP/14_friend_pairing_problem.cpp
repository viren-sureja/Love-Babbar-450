/*
    link: https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1

    variation of 1/0 knapsack.

*/

// ----------------------------------------------------------------------------------------------------------------------- //

// memoization
const long long mod = 1e9 + 7;
vector<long long> dp;
long long recur(long long n) {

    if (dp[n] != -1) return dp[n];


    // if nth person pairs with someone then have (n-1) choices hence (n-1)*f(n-2)
    // why n-2 as nth person has already paired with 1 out of (n-1) so now pair with other n-2.
    if (n > 2) return dp[n] = (recur(n - 1) % mod) + ((n - 1) * (recur(n - 2) % mod) % mod);
    else return dp[n] = n;
}
long long countFriendsPairings(long long n)
{
    // memset(dp, -1, sizeof(dp));
    dp = vector<long long>(n + 1, -1);
    return recur(n) % mod;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// tabulation
int countFriendsPairings(int n) {
    long long dp[n + 1];
    memset(dp, -1, sizeof(dp));
    for (int i = 1;i < n + 1;i++) {
        if (i <= 2) dp[i] = i;
        else dp[i] = (dp[i - 1] + ((i - 1) * dp[i - 2]) % mod) % mod;
    }
    return dp[n];
}

// ----------------------------------------------------------------------------------------------------------------------- //