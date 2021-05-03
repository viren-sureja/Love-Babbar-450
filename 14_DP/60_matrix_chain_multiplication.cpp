/*
    link: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
    sol: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

    refer: DP_tut/4_MCM/1_implem....
*/

// ----------------------------------------------------------------------------------------------------------------------- //

class Solution {
public:
    int memo[1001][1001];
    int MCM(int arr[], int i, int j) {
        if (i >= j) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        int mn = INT_MAX;
        for (int k = i;k < j;k++) {
            int temp = MCM(arr, i, k) + MCM(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            mn = min(mn, temp);
        }
        return memo[i][j] = mn;
    }

    int matrixMultiplication(int n, int arr[])
    {
        // code here
        memset(memo, -1, sizeof(memo));
        return MCM(arr, 1, n - 1);
    }
};

// ----------------------------------------------------------------------------------------------------------------------- //