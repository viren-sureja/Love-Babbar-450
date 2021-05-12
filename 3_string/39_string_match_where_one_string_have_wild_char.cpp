/*
    link: https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1#

    sol: https://www.geeksforgeeks.org/wildcard-pattern-matching/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
vector<vector<int> > dp;
int finding(string& s, string& p, int n, int m)
{
    // return 1 if n and m are negative
    if (n < 0 && m < 0)
        return 1;

    // return 0 if m is negative
    if (m < 0)
        return 0;

    // return n if n is negative
    if (n < 0)
    {
        // while m is positve
        while (m >= 0)
        {
            if (p[m] != '*')
                return 0;
            m--;
        }
        return 1;
    }

    // if dp state is not visited
    if (dp[n][m] == -1)
    {
        if (p[m] == '*')
        {
            // finding(s, p, n - 1, m) is to ignore the *
            // finding(s, p, n, m - 1) is to start adding char in place of *.
            return dp[n][m] = finding(s, p, n - 1, m) || finding(s, p, n, m - 1);
        }
        else
        {
            // if it's not ? as well as char are not matching.
            if (p[m] != s[n] && p[m] != '?') return dp[n][m] = 0;
            else return dp[n][m] = finding(s, p, n - 1, m - 1);
        }
    }

    // return dp[n][m] if dp state is previsited
    return dp[n][m];
}

// s is the main string
// p is the wild string
bool isMatch(string s, string p)
{
    dp.clear();

    // resize the dp array
    dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
    return dp[s.size()][p.size()] = finding(s, p, s.size() - 1, p.size() - 1);
}
