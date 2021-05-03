/*
    link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

    refer: DP_tut/0-1_knapsack/3_equal...
*/

// ----------------------------------------------------------------------------------------------------------------------- //

bool subsetSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0;i < n;i++) {
        sum += arr[i];
    }
    if (sum % 2) return 0;
    sum /= 2;
    vector<vector<bool>> tabu(n + 1, vector<bool>(sum + 1));
    for (int i = 0;i < n + 1;i++) {
        tabu[i][0] = true;
    }
    for (int j = 1;j < sum + 1;j++) {
        tabu[0][j] = false;
    }

    for (int i = 1;i < n + 1;i++) {
        for (int j = 1;j < sum + 1;j++) {
            if (arr[i - 1] <= j) {
                tabu[i][j] = tabu[i - 1][j - arr[i - 1]] || tabu[i - 1][j];
            }
            else tabu[i][j] = tabu[i - 1][j];
        }
    }
    return tabu[n][sum];
}
int equalPartition(int N, int arr[])
{
    // code here
    return subsetSum(arr, N);
}

// ----------------------------------------------------------------------------------------------------------------------- //