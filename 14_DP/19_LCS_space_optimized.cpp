/*
    link: https://www.geeksforgeeks.org/space-optimized-solution-lcs/

    here we can optimize the space complexity. how?
    ans: If we observe in our LCS previous code (dp_tut/3_LCS/1_imp...) we only require i-1's value while calculating the
    current value hence we can do this the same in array having 2 row.

*/

// ----------------------------------------------------------------------------------------------------------------------- //

int lcs(string& X, string& Y)
{

    // Find lengths of two strings 
    int m = X.length(), n = Y.length();

    int L[2][n + 1];

    // Binary index, used to 
    // index current row and 
    // previous row. 
    bool bi;

    for (int i = 0; i <= m; i++)
    {

        // Compute current 
        // binary index 
        bi = i & 1; // or we can use i%2 everywhere both are same.

        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[bi][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[bi][j] = L[1 - bi][j - 1] + 1;

            else
                L[bi][j] = max(L[1 - bi][j],
                    L[bi][j - 1]);
        }
    }

    return L[bi][n];
}

// ----------------------------------------------------------------------------------------------------------------------- //