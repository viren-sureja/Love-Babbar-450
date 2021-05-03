/*
    link: https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

    variation of unbound knapsack.

    how it is different than rop cutting problem?
    ans : In rope cutting we were aiming to return max length while here we want distict pairs

*/

// ----------------------------------------------------------------------------------------------------------------------- //

// correct sol.
// here total ways will be return (distinct).
long long int count(long long int n)
{
    long long int table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;                 // If 0 sum is required number of ways is 1.
    for (i = 3;i <= n;i++)
        table[i] += table[i - 3];   // For every points (3,5,10) you need to add the number of ways to reach that sum 
    for (i = 5;i <= n;i++)           // before adding these points.
        table[i] += table[i - 5];
    for (i = 10;i <= n;i++)
        table[i] += table[i - 10];
    return table[n];
}

// ----------------------------------------------------------------------------------------------------------------------- //

// this won't work as here it will not return distict pairs..
long long int count(long long int n)
{
    long long int table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;                 // If 0 sum is required number of ways is 1(by not picking any path, direct winner).

    // Your code here
    // here it is given fix that score possible are 3,5,10.
    for (i = 1;i < n + 1;i++) {
        for (int j = 1;j < n + 1;j++) {
            if (j >= 3) {
                table[i] += table[j - 3];
            }
            if (j >= 5) {
                table[i] = table[j - 5];
            }
            if (j >= 10) {
                table[i] += table[j - 10];
            }
        }
    }

    return table[n];
}

// ----------------------------------------------------------------------------------------------------------------------- //