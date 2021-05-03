/*
    link: https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0

    video: https://www.youtube.com/watch?v=UagRoA3C5VQ&ab_channel=Pepcoding
*/

// ----------------------------------------------------------------------------------------------------------------------- //

class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        /* if 1st col. and 1st row put as it is as they won't be able to make square */
        for (int i = 0;i < n;i++) {
            dp[i][0] = mat[i][0];
        }
        for (int j = 0;j < m;j++) {
            dp[0][j] = mat[0][j];
        }
        int mx = INT_MIN;
        for (int i = 1;i < n;i++) {
            for (int j = 1;j < m;j++) {

                /* here if any of the neighbour is 0 then size will be 1(itself) as we have to find matrix with all 1.
                    hence for that reason we have to take min of all the neighbour square in mat.
                 */
                if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                }
                // if current ele is 0 then it's any sub-square matrix won't counted.
                else dp[i][j] = 0;
                mx = max(mx, dp[i][j]);
            }
        }
        return (mx == INT_MIN) ? 1 : mx;
    }
};

// ----------------------------------------------------------------------------------------------------------------------- //