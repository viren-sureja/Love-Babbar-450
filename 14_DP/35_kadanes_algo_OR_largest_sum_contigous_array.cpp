/*
    link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

    variation of LIS but here not subsequence but subarray in contigous manner.
    also variation of 1/0 knapsack.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// arr: input array
// n: size of array
//Function to find the sum of contiguous subarray with maximum sum.

// TC: O(N)
int maxSubarraySum(int arr[], int n) {
    int dp[n];

    dp[0] = max(0, arr[0]);
    int omax = dp[0];
    for (int i = 1;i < n;i++) {
        // choosing either to keep the subarray continue or break and initialize with current ele.
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        // also keeping track of highest sum achieved during the journey.
        omax = max(dp[i], omax);
    }
    return omax;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// simple algo..
// TC: O(N)
class Solution {
public:
//Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int a[], int n) {

        long long maxh = 0, maxf = INT_MIN;

        //Iterating over the array.
        for (int i = 0;i < n;i++)
        {
            //Updating max sum till current index.
            maxh += a[i];
            //Storing max sum so far by choosing maximum between max 
            //sum so far and max till current index.
            maxf = max(maxh, maxf);

            //If max sum at current index is negative, we do not need to add
            //it to result so we update it to zero.
            if (maxh < 0)
                maxh = 0;

        }
        //returning the result.
        return maxf;

    }
};

// ----------------------------------------------------------------------------------------------------------------------- //