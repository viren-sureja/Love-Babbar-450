/*
    link: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

    video: https://www.youtube.com/watch?v=NdpolO4sM3k
    video: https://www.youtube.com/watch?v=YHSjvswCXC8

    very useful source: https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/

*/

// ----------------------------------------------------------------------------------------------------------------------- //

const long long mod = 1e9 + 7;
long long dp[1002][1002];
int helper(string& s, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j] % mod;
    }
    if (s[i] == s[j]) {
        /* why still i+1,j and i,j-1?
            ans: to understand this go to: https://media.geeksforgeeks.org/wp-content/uploads/20190804162927/00011.jpg
        */

        dp[i][j] = (1 + helper(s, i + 1, j) % mod + helper(s, i, j - 1) % mod) % mod;
    }
    else {
        /*
            while here - (i+1, j-1) as..
            here let's take abc then
            a b and b c hence b is repeating twice which is irrelavant hence deduct that.s
        */
        dp[i][j] = (helper(s, i, j - 1) % mod + helper(s, i + 1, j) % mod - helper(s, i + 1, j - 1) % mod) % mod;
    }
    return dp[i][j] % mod;
}
long long int  countPS(string str)
{
   //Your code here
    memset(dp, -1, sizeof(dp));
    return helper(str, 0, str.size() - 1) % mod;
}

// ----------------------------------------------------------------------------------------------------------------------- //