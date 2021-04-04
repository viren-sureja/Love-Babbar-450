/*
    link: https://practice.geeksforgeeks.org/problems/given_egg-dropping-puzzle-1587115620/1

    refer: DP_tut/MCM/5_egg...
    refer: aditya verma video

    variation of MCM
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// recursion
int eggDrop(int given_egg, int given_floor)
{
    // base condition
    if (given_floor == 0 || given_floor == 1 || given_egg == 1) return given_floor;

    // min attempts but in worst case
    int ans = INT_MAX - 1;

    // iterate through all the given_floor 
    for (int k = 1;k <= given_floor;k++) {
        int temp = max(eggDrop(given_egg - 1, k - 1), eggDrop(given_egg, given_floor - k));

        ans = min(temp, ans);
    }
    return ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// memoization  (will give TLE)
int memo[1001][1001];
int recur(int given_egg, int given_floor) {
    // base condition
    if (given_floor == 0 || given_floor == 1 || given_egg == 1) return given_floor;

    if (memo[given_egg][given_floor] != -1) return memo[given_egg][given_floor];

    int ans = INT_MAX - 1;

    for (int k = 1;k <= given_floor;k++) {
        int temp = max(eggDrop(given_egg - 1, k - 1), eggDrop(given_egg, given_floor - k));

        ans = min(temp, ans);
    }
    return memo[given_egg][given_floor] = ans;
}

int eggDrop(int given_egg, int given_floor)
{
    memset(memo, -1, sizeof(memo));
    recur(given_egg, given_floor);
    return memo[given_egg][given_floor];
}

// ----------------------------------------------------------------------------------------------------------------------- //

// optimized memoization
int memo[1001][1001];
int recur(int given_egg, int given_floor) {

    if (given_floor == 0 || given_floor == 1 || given_egg == 1) return given_floor;

    if (memo[given_egg][given_floor] != -1) return memo[given_egg][given_floor];


    int ans = INT_MAX - 1;


    for (int k = 1;k <= given_floor;k++) {
        int below = (memo[given_egg][given_floor] == -1) ? recur(given_egg - 1, k - 1) : memo[given_egg][given_floor];
        int upper = (memo[given_egg][given_floor] == -1) ? recur(given_egg, given_floor - k) : memo[given_egg][given_floor];
        /*  why did we optimized?
            ans: here i guess we r saving stack memory
        */

        int temp = 1 + max(below, upper);

        ans = min(ans, temp);
    }
    return memo[given_egg][given_floor] = ans;
}
int eggDrop(int given_egg, int given_floor)
{
    memset(memo, -1, sizeof(memo));
    return recur(given_egg, given_floor);
}