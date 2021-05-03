/*
    link: https://www.geeksforgeeks.org/program-nth-catalan-number/

    other variations:
    1. Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
    2. Count the number of possible Binary Search Trees with n keys (See this)
    3. Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
    4. Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.


    recursive C(0)=1 C(n+1)=iteration{0 to n}C(i)C(n-i);

    most optimized use at last: C(n) = (1/n+1) (2n C n)
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// recursive formula
int nth_catalan(int n) {
    if (n <= 1) return 1;

    int ans = 0;
    int m = n - 1;
    for (int i = 0;i < n;i++) {
        ans += nth_catalan(i) * nth_catalan(m - i);
    }
    return ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// memoization
int memo[1001];
int nth_catalan(int n) {
    if (n <= 1) return 1;

    if (memo[n] != -1) return memo[n];

    int ans = 0;
    int m = n - 1;
    for (int i = 0;i < n;i++) {
        ans += nth_catalan(i) * nth_catalan(m - i);
    }
    return memo[n] = ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// memoization optimization
int memo[1001];
int nth_catalan(int n) {
    if (n <= 1) return 1;

    if (memo[n] != -1) return memo[n];

    int ans = 0;
    int m = n - 1;
    for (int i = 0;i < n;i++) {

        int a = (memo[i] == -1) ? nth_catalan(i) : memo[i];         // checking before passing to save stack value.
        int b = (memo[m - i] == -1) ? nth_catalan(m - i) : memo[m - i];
        ans += a * b;
    }
    return memo[n] = ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// tabulation
// TC: O(N^2)
int memo[1001];
int nth_catalan(int n) {
    // base condition
    memo[0] = memo[1] = 1;

    for (int i = 2;i <= n;i++) {
        memo[i] = 0;
        for (int j = 0;j < i;j++) {
            memo[i] += memo[j] * memo[i - 1 - j];
        }
    }
    return memo[n];
}

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(N)
// most optimized : C(n) = (1 / n + 1) (2n C n)
long long nCr(int n, int r) {
    long long int ans = 1;

    if (r > n - r) r = n - r;

    for (int i = 0;i < r;i++) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}
int catalan(int n) {
    int two_n_C_n = nCr(2 * n, n);
    return (1 / (n + 1)) * two_n_C_n;
}

// ----------------------------------------------------------------------------------------------------------------------- //