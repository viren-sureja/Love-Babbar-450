/*
    link: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#
*/

// ----------------------------------------------------------------------------------------------------------------------- //

class Solution {
public:
    int dp[201][201][2];
    const int inf = 1003;
    int paranthezitaion(string s, int i, int j, bool isTrue) {
        // Base Condition
        if (i > j)
            return false;
        if (i == j) {
            if (isTrue == 1)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        long long ans = 0;
        for (int k = i + 1
            ; k <= j - 1; k = k + 2)
        {
            int leftF, leftT, rightT, rightF;
            if (dp[i][k - 1][1] == -1)
            {
                leftT = paranthezitaion(s, i, k - 1, 1);
            } // Count no. of T in left partition
            else {
                leftT = dp[i][k - 1][1];
            }

            if (dp[k + 1][j][1] == -1)
            {
                rightT = paranthezitaion(s, k + 1, j, 1);
            } // Count no. of T in right partition
            else
            {
                rightT = dp[k + 1][j][1];
            }

            if (dp[i][k - 1][0] == -1)
            {
                // Count no. of F in left partition
                leftF = paranthezitaion(s, i, k - 1, 0);
            }
            else
            {
                leftF = dp[i][k - 1][0];
            }

            if (dp[k + 1][j][0] == -1)
            {
                // Count no. of F in right partition
                rightF = paranthezitaion(s, k + 1, j, 0);
            }
            else
            {
                rightF = dp[k + 1][j][0];
            }

            if (s[k] == '&')
            {
                if (isTrue == 1)
                    ans += leftT * rightT;
                else
                    ans += leftF * rightF + leftT * rightF
                    + leftF * rightT;
            }
            else if (s[k] == '|')
            {
                if (isTrue == 1)
                    ans += leftT * rightT + leftT * rightF
                    + leftF * rightT;
                else
                    ans = ans + leftF * rightF;
            }
            else if (s[k] == '^')
            {
                if (isTrue == 1)
                    ans = ans + leftF * rightT + leftT * rightF;
                else
                    ans = ans + leftT * rightT + leftF * rightF;
            }
            dp[i][j][isTrue] = ans % inf;
        }
        return ans % inf;
    }
    int countWays(int N, string S) {
        // code here
        memset(dp, -1, sizeof(dp));
        return paranthezitaion(S, 0, N - 1, true) % inf;
    }
};

// ----------------------------------------------------------------------------------------------------------------------- //