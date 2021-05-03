/*
    link: https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/

    video: https://www.youtube.com/watch?v=WMmx6kDxaDQ

    source code is there in link.
    to understand recursion relation watch video.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// dp sol. 
// TC: O(N), SC: O(N)
#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
    // Create an array to store
    // counts for subproblems
    int der[n + 1] = { 0 };

    // Base cases
    der[1] = 0;
    der[2] = 1;

    // Fill der[0..n] in bottom up manner
    // using above recursive formula
    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] +
            der[i - 2]);

// Return result for n
    return der[n];
}
int main()
{
    int n = 4;
    cout << "Count of Derangements is "
        << countDer(n);
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(N), SC: O(1)
#include <iostream>
using namespace std;

int countDer(int n)
{

    // base case
    if (n == 1 or n == 2) {
        return n - 1;
    }

    // Variable for just storing
    // previous values
    int a = 0;
    int b = 1;

    // using above recursive formula
    for (int i = 3; i <= n; ++i) {
        int cur = (i - 1) * (a + b);
        a = b;
        b = cur;
    }

    // Return result for n
    return b;
}

// Driver Code
int main()
{
    cout << "Count of Dearrangements is " << countDer(4);
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //