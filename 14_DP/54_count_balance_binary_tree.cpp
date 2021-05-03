/*
    link: https://www.geeksforgeeks.org/count-balanced-binary-trees-height-h/

    all solution in link.

    logic:
    here as per 3 condition

                root
                /   \
    left sub tree    right sub tree
    (h-2)            (h-1)
    (h-1)            (h-2)
    (h-1)            (h-1)

    so
   count(h) = count(h-1) * count(h-2) + count(h-2) * count(h-1) + count(h-1) * count(h-1)
            = 2 * count(h-1) * count(h-2) + count(h-1) * count(h-1)
            = count(h-1) * (2*count(h - 2) + count(h - 1))

    why multiply?
    bcoz for each sub tree with (h-2) it can be pair with all different (h-1) and vice-verca.

    why vice-verca ?
    bcoz it will be counted as unique if
    (h-2) height trees on left side and (h-1) on right side
    (h-1) height trees on left side and (h-2) on right side
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// C++ program to count number of balanced
// binary trees of height h.
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long int countBT(int h) {

    long long int dp[h + 1];
    //base cases
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= h; i++) {
        dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) % mod + dp[i - 1]) % mod) % mod;
    }
    return dp[h];
}
// Driver program
int main()
{
    int h = 3;
    cout << "No. of balanced binary trees"
        " of height h is: "
        << countBT(h) << endl;
}

// ----------------------------------------------------------------------------------------------------------------------- //