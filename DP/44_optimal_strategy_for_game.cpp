/*
    link: https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

    video: https://www.youtube.com/watch?v=ww4V7vRIzSk

    when we aim to make opponent fail greedy will work
    but when to aim for make opponent fail + optimally win we use DP.


    video will be more helpful in this problem.

    here we are filling in diagonal manner

    why?
    as we want gap (length between 0, n-1) at a time constant but increasing 1 at a time
    also we want i and j to increase by 1 both at a time as both us and opponent will be making choices.

*/

// ----------------------------------------------------------------------------------------------------------------------- //

long long maximumAmount(int arr[], int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));


    for (int gap = 0;gap < n;gap++) {
        for (int i = 0, j = gap;j < n;j++, i++) {
            if (gap == 0) dp[i][j] = arr[i];
            else if (gap == 1) dp[i][j] = max(arr[i], arr[j]);
            else {
                int a = arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
                int b = arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
                dp[i][j] = max(a, b);
            }
        }
    }
    return dp[0][n - 1];
}

// ----------------------------------------------------------------------------------------------------------------------- //