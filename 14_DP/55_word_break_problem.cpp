/*
    link: https://practice.geeksforgeeks.org/problems/word-break1352/1
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int wordBreak(string A, vector<string>& B) {
    set<string> s;
    for (string i : B) s.insert(i);


    int n = A.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));  // to avoid garbage value.

    dp[0] = 1;  // empty string is always in dictionary.

    for (int i = 1;i < n + 1;i++) {
        for (int j = 0;j < i;j++) {
            /*
                here dp is of N+1 index based while string is of 0 based
                hence dp[0] means empty string while A.substr(0, len) is starting from pos=0.

                so everytime comparison will be like: str=abcd
                ("" && "abcd") ("a" && "bcd") ("ab" && "cd") ...
                to check every possibilities.
            */
            if (dp[j] && s.find(A.substr(j, i - j)) != s.end()) {
                // if prev substring's dp is true and new substring is also true then we will set 1 and break.
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n];
}

// ----------------------------------------------------------------------------------------------------------------------- //