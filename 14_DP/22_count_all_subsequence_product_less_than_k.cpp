/*
    link: https://www.geeksforgeeks.org/count-subsequences-product-less-k/
    video: https://www.youtube.com/watch?v=OBLvQwkhej0

    variation of 0/1 knapsack.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int LIS_product(int arr[], int n, int k) {
    int dp[k + 1][n + 1];
    for (int j = 0;j < n + 1;j++) dp[0][j] = 0;
    // k=0 then no element can make this product as n>=1;
    for (int i = 0;i < k + 1;i++) dp[i][0] = 0;
    // n=0 there exist no element to compare


    for (int i = 1;i < k + 1;i++) {
        for (int j = 1;j < n + 1;j++) {
            dp[i][j] = dp[i][j - 1];
            // add the prev total count.

            if (arr[j - 1] <= i) {
                dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1;
                /*
                    here as we know current_element(arr[j-1]) is less than product_required(i)
                    now we will find such existing_product whose ans is less, but how much? ans: i/arr[j-1] atleast current_element times.
                    why +1: as after finding above no. we have to add 1 for current pair it will make.
                */
            }
        }
    }
    dp[k][n];
}

// ----------------------------------------------------------------------------------------------------------------------- //