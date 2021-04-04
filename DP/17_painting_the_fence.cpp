/*
    link: https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
    video: https://www.youtube.com/watch?v=ju8vrEAsa3Q

    variation of fibonacci

*/

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(N)
int const mod = 1e9 + 7;
int countWays(int n, int k) {
    if (n == 1) return k;

    // storing data for n==2
    // let assume last 2 are same as we can have only 2 same color in whole fence
    long long same = (k * 1) % mod;
    long long diff = (k * (k - 1)) % mod;
    long long total = (same + diff) % mod;

    for (int i = 3;i <= n;i++) {
        // take different of prev as they will have same color repeated at the end.
        same = diff % mod;
        // take total of prev as they have mixture but wont matter 
        // eg. if prev: gg then add new => ggb, if prev: gb then add new gbg
        diff = (total * (k - 1)) % mod;

        total = (same + diff) % mod;
    }
    return total;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// tabulation
long long const mod = 1e9 + 7;
long long countWays(int n, int k) {
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    // base condition
    dp[1] = k;
    dp[2] = (k + ((k - 1) * k) % mod) % mod;

    for (int i = 3;i <= n;i++) {
        dp[i] = ((k - 1) * ((dp[i - 1] + dp[i - 2]) % mod)) % mod;
    }
    return dp[n];
}

// ----------------------------------------------------------------------------------------------------------------------- //