/*
    link: https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int LCSof3(string a, string b, string c, int n, int m, int o)
{
    // base cond.
    int memo[n + 1][m + 1][o + 1];
    memset(memo, -1, sizeof(memo));
    for (int i = 0;i < n + 1;i++) {
        for (int j = 0;j < m + 1;j++) {
            for (int k = 0;k < o + 1;k++) {
                if (i == 0 || k == 0 || j == 0) {
                    memo[i][j][k] = 0;
                }
            }
        }
    }

    for (int i = 1;i < n + 1;i++) {
        for (int j = 1;j < m + 1;j++) {
            for (int k = 1;k < o + 1;k++) {
                if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
                    memo[i][j][k] = 1 + memo[i - 1][j - 1][k - 1];
                }
                else {
                    memo[i][j][k] = max({ memo[i - 1][j][k], memo[i][j - 1][k], memo[i][j][k - 1] });
                }
            }
        }
    }
    return memo[n][m][o];
}

// ----------------------------------------------------------------------------------------------------------------------- //