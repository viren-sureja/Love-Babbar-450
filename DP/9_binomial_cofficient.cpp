/*
    link: https://practice.geeksforgeeks.org/problems/ncr1019/1#

    n C r= (n-1 C r) + (n-1 C r-1)
    thread to understand above equation: https://discuss.codechef.com/t/need-some-explanation-on-the-combinatorics-formula-ncr-n-1cr-n-1cr-1/13834
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// recursion
// let's assume if n is the whole class and r is to select few student
int recur(int n, int r) {
    // base condition
    if (r == 0 || r == n) return 1;
    if (n < r) return 0;

    return recur(n - 1, r - 1) + recur(n - 1, r);
     /*
        recur(n-1, r-1): it says select favourite student hence total-1 and student_still_left_to_select - 1 ;
        recur(n-1, r): it means reject that favourite student hence total-1 and student_still_left_to_select remains same.
    */
}
int nCr(int n, int r) {
    return recur(n, r);
}

// ----------------------------------------------------------------------------------------------------------------------- //

// memoization
long long memo[1001][1001];
const long long mod = 1e9 + 7;
int recur(int n, int r) {
    // base condition
    if (r == 0 || r == n) return 1;
    if (n < r) return 0;
    if (memo[n][r] != -1) return memo[n][r];

    return memo[n][r] = ((recur(n - 1, r - 1) % mod) + (recur(n - 1, r) % mod) % mod);
}
int nCr(int n, int r) {
    memset(memo, -1, sizeof(memo));
    return recur(n, r) % mod;
}


// ----------------------------------------------------------------------------------------------------------------------- //

// tabulation 
const long long mod = 1e9 + 7;
int memo[1001][1001];
int nCr(int n, int r) {
    if (n < r) return 0;

    // base condition

    for (int j = 0;j < r + 1;j++) {
        memo[0][j] = 0;
    }
    for (int i = 0;i < n + 1;i++) {
        memo[i][0] = 1;
    }

    for (int i = 1;i < n + 1;i++) {
        for (int j = 1;j <= min(i, r);j++) {
            memo[i][j] = (memo[i - 1][j - 1] % mod + memo[i - 1][j] % mod) % mod;
        }
    }
    return memo[n][r] % mod;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// another tabulation (bit confusing so u can avoid it..)
long long nCr(int n, int r) {
        // code here
    const long long mod = 1e9 + 7;
    vector<long long> v(r + 1, 0);
    v[0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = min(r, i); j > 0;j--) {
            v[j] = (v[j] + v[j - 1]) % mod;
        }
    }
    return v[r];
}

// ----------------------------------------------------------------------------------------------------------------------- //

// MOST OPTIMIZED VERSION
// TC: O(N)

/*
    use pen paper and put value like 5C2 to understand
     nCk =  [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
*/
long long nCr(int n, int r) {
    long long int ans = 1;

    if (r > n - r) r = n - r;

    for (int i = 0;i < r;i++) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //