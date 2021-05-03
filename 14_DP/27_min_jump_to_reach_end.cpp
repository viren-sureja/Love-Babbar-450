/*
    link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
    sol.: https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/#comment-3321908697
    for O(N) sol.: https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(n^2), TLE
int minJumps(int arr[], int n) {
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1;i < n;i++) {
        dp[i] = 1e6;
        for (int j = 0;j < i;j++) {
            if (arr[j] >= i - j && dp[j] != 1e6) {
                // here value of arr[j] (capacity jump range) to reach i-j distnce and also is not 0.
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    return (dp[n - 1] == 1e6) ? -1 : dp[n - 1];
}

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(n^2) 
// note: logic is same as above but here it starts from end.
int minJumps(int arr[], int n)
{
    // jumps[0] will hold the result
    int* jumps = new int[n];
    int min;

    // Minimum number of jumps needed
    // to reach last element from last
    // elements itself is always 0
    jumps[n - 1] = 0;

    // Start from the second element,
    // move from right to left and
    // construct the jumps[] array where
    // jumps[i] represents minimum number
    // of jumps needed to reach
    // arr[m-1] from arr[i]
    for (int i = n - 2; i >= 0; i--) {
        // If arr[i] is 0 then arr[n-1]
        // can't be reached from here
        if (arr[i] == 0)
            jumps[i] = INT_MAX;

        // If we can direcly reach to
        // the end point from here then
        // jumps[i] is 1
        else if (arr[i] >= n - i - 1)
            jumps[i] = 1;

        // Otherwise, to find out the minimum
        // number of jumps needed to reach
        // arr[n-1], check all the points
        // reachable from here and jumps[]
        // value for those points
        else {
            // initialize min value
            min = INT_MAX;

            // following loop checks with all
            // reachable points and takes
            // the minimum
            for (int j = i + 1; j < n && j <= arr[i] + i; j++) {
                if (min > jumps[j])
                    min = jumps[j];
            }

            // Handle overflow
            if (min != INT_MAX)
                jumps[i] = min + 1;
            else
                jumps[i] = min; // or INT_MAX
        }
    }

    return jumps[0];
}

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(N)
int minJumps(int arr[], int n) {

    // base condition
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;

    for (int i = 1;i < n;i++) {
        if (i == n - 1) return jump;

        maxReach = max(maxReach, arr[i] + i);

        step--;

        if (step == 0) {
            jump++;

            if (i >= maxReach) return -1;

            step = maxReach - i;
        }
    }
    return -1;
}

// ----------------------------------------------------------------------------------------------------------------------- //