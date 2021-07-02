/*
    link: https://practice.geeksforgeeks.org/problems/coin-change2448/1

    variation of unbounded_knapsack for more refer to DP_tut/unbounded_knapsack/3_coin....
*/

// ----------------------------------------------------------------------------------------------------------------------- //

long long int count(int coins[], int n, int sum)
{
    vector<vector<long long int>> memo(n + 1, vector<long long int>(sum + 1));
    for (int j = 0;j < sum + 1;j++) memo[0][j] = 0;
    for (int i = 1;i < n + 1;i++) memo[i][0] = 1;

    for (int i = 1;i < n + 1;i++) {
        for (int j = 1;j < sum + 1;j++) {
            if (coins[i - 1] <= j) {
                memo[i][j] = memo[i][j - coins[i - 1]] + memo[i - 1][j];
            }
            else memo[i][j] = memo[i - 1][j];
        }
    }
    return memo[n][sum];
}

// ----------------------------------------------------------------------------------------------------------------------- //