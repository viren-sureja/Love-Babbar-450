/*
    link: https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

    how many dimension or which factor to include in dp array?
    ans: include those which are changing at every moment/decision or while doing recursion.
    for eg. if my 2 variables are changing every time hence for sure my dp array will be 2-d
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// for any K
// TC: K*N
// SC: (K+1)(N+1)
class Solution {
public:
    int maxProfit(int K, int N, int A[]) {
        // table to store results of subproblems profit[t][i] stores maximum
        // profit using atmost t transactions up to day i (including day i)
        int profit[K + 1][N + 1];

        // For day 0, you can't earn money irrespective of how many times you
        // trade
        for (int i = 0; i <= K; i++) profit[i][0] = 0;

        // profit is 0 if we don't do any transation (i.e. k =0)
        for (int j = 0; j <= N; j++) profit[0][j] = 0;

        // fill the table in bottom-up fashion
        for (int i = 1; i <= K; i++) {
            int prevDiff = INT_MIN;
            for (int j = 1; j < N; j++) {
                /*
                    profit[i-1][j-1] means 1 transaction less and excluding current_ele
                    A[j-1] subtracting as we r buying that jth item (j-1 for 0 based array)

                    profit[i][j - 1] means we r continuing with prev profit hence no decre/incre in transaction(here i) and hence no buying/selling at current pos;
                    A[j] + prevDiff we r selling our stock gaining profit of (A[j] - A[j-1]) here A[j-1] we already did while purchasing.
                */
                prevDiff = max(prevDiff, profit[i - 1][j - 1] - A[j - 1]);
                /*
                    why max in above expre. ?
                    to max means to max profit[i - 1][j - 1] - A[j - 1]
                    which means to minimize A[j - 1] cost while buying
                    to expecting prev profit higher (profit[i - 1][j - 1]).
                */
                profit[i][j] = max(profit[i][j - 1], A[j] + prevDiff);
            }
        }

        return profit[K][N - 1];
    }
};

// ----------------------------------------------------------------------------------------------------------------------- //

// link: https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
// for atmost 2 transaction
#include <bits/stdc++.h>
using namespace std;

// Returns maximum profit with
// two transactions on a given
// list of stock prices, price[0..n-1]
int maxProfit(int price[], int n)
{
    // Create profit array and
    // initialize it as 0
    int* profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    /* Get the maximum profit with
    only one transaction
    allowed. After this loop,
    profit[i] contains maximum
    profit from price[i..n-1]
    using at most one trans. */
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        // max_price has maximum
        // of price[i..n-1]
        if (price[i] > max_price)
            max_price = price[i];

        // we can get profit[i] by taking maximum of:
        // a) previous maximum, i.e., profit[i+1]
        // b) profit by buying at price[i] and selling at
        // max_price
        profit[i]
            = max(profit[i + 1], max_price - price[i]);
    }

    /* Get the maximum profit with two transactions allowed
    After this loop, profit[n-1] contains the result */
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        // min_price is minimum price in price[0..i]
        if (price[i] < min_price)
            min_price = price[i];

        // Maximum profit is maximum of:
        // a) previous maximum, i.e., profit[i-1]
        // b) (Buy, Sell) at (min_price, price[i]) and add
        // profit of other trans. stored in profit[i]
        profit[i] = max(profit[i - 1],
            profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];

    delete[] profit; // To avoid memory leak

    return result;
}

// Driver code
int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //