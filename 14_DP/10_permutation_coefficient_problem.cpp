/*
    link: https://www.geeksforgeeks.org/permutation-coefficient/

    logic is same as 9_binomial_cofficient but here it is permutation
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// recursion
// let's assume if n is the no. of balls and r is to position to fill
int recur(int n, int r) {
    // base condition
    if (n < r) return 0;
    if (n == 0 || r == 0) return 1;

    return recur(n - 1, r) + (r * recur(n - 1, r - 1));
    /*  recur(n-1, r-1): it says select fixed ball hence total-1 and ball_left_to_select - 1 and now also there are r pos to permute that fixed ball.
        recur(n-1, r): it means reject that fixed ball hence total-1 and ball_left_to_select remains same.
    */
}

// do memoization and tabulation by self.

// ----------------------------------------------------------------------------------------------------------------------- //