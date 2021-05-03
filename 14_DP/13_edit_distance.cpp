/*
    link: https://practice.geeksforgeeks.org/problems/edit-distance3702/1
    sol: https://www.geeksforgeeks.org/edit-distance-dp-5/

    variation of: LCS

    refer: DP_tut/3_LCS/5_minimum....

    Applications:
    There are many practical applications of edit distance algorithm, refer Lucene API for sample.
    Another example, display all the words in a dictionary that are near proximity to a given wordincorrectly spelled word.

*/

// ----------------------------------------------------------------------------------------------------------------------- //

// memoization
int dp[102][102];
int fun(string s, string t, int pos1, int pos2) {

    // base condition are v.v.imp.

    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (pos1 == 0) return pos2;
    // If second string is empty, the only option is to
    // remove all characters of first string
    if (pos2 == 0) return pos1;
    int& ans = dp[pos1][pos2];
    // If already calculated.
    if (ans != -1) return ans;
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (s[pos1 - 1] == t[pos2 - 1])
        return ans = fun(s, t, pos1 - 1, pos2 - 1);
    // If last characters are not same, consider all three
    // operations on last character of first string, recursively
    // compute minimum cost for all three operations and take
    // minimum of three values. 

    // here diff. then LCS(only delete+insert) is here we can replace so if char are not same we try to ignore them both with cost 1.
    // although cost of insertion and deletion is 1 only.
    // but if we somehow use replace then we will save by 1 cost eg. before(delete current and insert new letter) so 2, now(replace current wiht new) hence 1.

    return ans = min({ 1 + fun(s, t, pos1, pos2 - 1),
                      1 + fun(s, t, pos1 - 1, pos2),
                      1 + fun(s, t, pos1 - 1, pos2 - 1) });
}

int editDistance(string s, string t) {
    memset(dp, -1, sizeof(dp));
    int ans = fun(s, t, s.size(), t.size());
    return ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// tabulation
long long memo[102][102];
long long findLCS(string& s, string& t, long long n, long long m) {
    // base condition
    /* case 1: string s is empty but t is not then total insertion will be current length of string t.
       case 2: string s not empty but t is empty hence than total deletion will be current length of s.
       case 3: if both are empty then 0.
    */
    for (long long i = 0;i < n + 1;i++) {
        for (long long j = 0;j < m + 1;j++) {
            if (i == 0) memo[i][j] = j;
            if (j == 0) memo[i][j] = i;
        }
    }
    memo[0][0] = 0;

    for (long long i = 1;i < n + 1;i++) {
        for (long long j = 1;j < m + 1;j++) {
            if (s[i - 1] == t[j - 1]) memo[i][j] = memo[i - 1][j - 1];
            else memo[i][j] = min({ 1 + memo[i - 1][j], 1 + memo[i][j - 1], 1 + memo[i - 1][j - 1] });
        }
    }
    return memo[n][m];
}

long long editDistance(string s, string t) {
    memset(memo, -1, sizeof(memo));
    long long n = s.size();
    long long m = t.size();
    long long ans = findLCS(s, t, n, m);
    return ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// space optimization
// TC: O(n * m)
// SC: O(n)
void EditDistDP(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    // Create a DP array to memoize result
    // of previous computations
    int DP[2][len1 + 1];

    // To fill the DP array with 0
    memset(DP, 0, sizeof DP);

    // Base condition when second string
    // is empty then we remove all characters
    for (int i = 0; i <= len1; i++)
        DP[0][i] = i;

    // Start filling the DP
    // This loop run for every
    // character in second string
    for (int i = 1; i <= len2; i++) {
        // This loop compares the char from
        // second string with first string
        // characters
        for (int j = 0; j <= len1; j++) {
            // if first string is empty then
            // we have to perform add character
            // operation to get second string
            if (j == 0)
                DP[i % 2][j] = i;

            // if character from both string
            // is same then we do not perform any
            // operation . here i % 2 is for bound
            // the row number.
            else if (str1[j - 1] == str2[i - 1]) {
                DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
            }

            // if character from both string is
            // not same then we take the minimum
            // from three specified operation
            else {
                DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j],
                    min(DP[i % 2][j - 1],
                        DP[(i - 1) % 2][j - 1]));
            }
        }
    }

    // after complete fill the DP array
    // if the len2 is even then we end
    // up in the 0th row else we end up
    // in the 1th row so we take len2 % 2
    // to get row
    cout << DP[len2 % 2][len1] << endl;
}

// ----------------------------------------------------------------------------------------------------------------------- //