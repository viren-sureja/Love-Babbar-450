/*
    link: https://www.geeksforgeeks.org/coin-game-winner-every-player-three-choices/
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// CPP program to find winner of game
// if player can pick 1, x, y coins
#include <bits/stdc++.h>
using namespace std;

// To find winner of game
bool findWinner(int x, int y, int n)
{
    // To store results
    int dp[n + 1];

    // Initial values
    dp[0] = false;
    dp[1] = true;

    // Computing other values.
    for (int i = 2; i <= n; i++) {

        // If A losses any of i-1 or i-x
        // or i-y game then he will
        // definitely win game i

        /* now in order to win, A has to loose previous one hence won by B and now check if
            i-1, i-x, i-y >=0 as well as A has loose the previous one so that A can win this one
         */
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;

        // if A is not able to fulfill all the criteria then A loses game.
        else
            dp[i] = false;
    }

    // If dp[n] is true then A will
    // game otherwise he losses
    return dp[n];
}

// Driver program to test findWinner();
int main()
{
    int x = 3, y = 4, n = 5;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';

    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //