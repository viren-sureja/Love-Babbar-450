/*
    link: https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

    video(very imp): https://www.youtube.com/watch?v=IN3uTs8afz4

*/

// ----------------------------------------------------------------------------------------------------------------------- //

long long getCountUtil(int n) {
    long long dp[n + 1][10];
    memset(dp, 0, sizeof(dp));

    /*
        we r finding for
        eg 1: key 1 and N=1 then:
            ans: 1 key itself
        eg 2: key 1 and N=2 then:
            11, 21, 41
            ans: 3
        eg 3: key 1 and N=3 then:
            111, 121, 221, 321, 521, 141, 441, 541, 741.

    */

    // now while pressing key which direction are allowed to us out of 4(up, down, right, left);
    vector<vector<int>> data;
    data.push_back({ 0, 8 });
    data.push_back({ 1, 2, 4 });
    data.push_back({ 1, 2, 3, 5 });
    data.push_back({ 2, 3, 6 });
    data.push_back({ 1, 4, 5, 7 });
    data.push_back({ 2, 4, 5, 6, 8 });
    data.push_back({ 3, 5, 6, 9 });
    data.push_back({ 4, 7, 8 });
    data.push_back({ 5, 7, 8, 9, 0 });
    data.push_back({ 6, 8, 9 });

    for (int j = 0;j < 10;j++) {
        dp[0][j] = 0;
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n;i++) {
        for (int j = 0;j <= 9;j++) {
            // so currently we are pressing jth key and finding for ith N(or pos)
            // so will take dp_value of previous i-1th pos of prev key where prev key represent the appro. neighbout key of current jth key.
            for (int prev : data[j]) {
                dp[i][j] += dp[i - 1][prev];
            }
        }
    }
    long long sum = 0;
    for (int j = 0;j <= 9;j++) {
        sum += dp[n][j];
    }
    return sum;
}

// ----------------------------------------------------------------------------------------------------------------------- //

class Solution {

private:
    long long getCountUtil(char keypad[][3], int n)
    {
        if (keypad == NULL || n <= 0)
            return 0;
        if (n == 1)
            return 10;

        // left, up, right, down move from current location 
        //  this include all the 5 move possible including staying there.
        int row[] = { 0, 0, -1, 0, 1 };
        int col[] = { 0, -1, 0, 1, 0 };

        // taking n+1 for simplicity - count[i][j] will store 
        // number count starting with digit i and length j 
        long long count[10][n + 1];
        int i = 0, j = 0, k = 0, move = 0, ro = 0, co = 0, num = 0;
        long long nextNum = 0, totalCount = 0;

        // count numbers starting with digit i and of lengths 0 and 1 
        for (i = 0; i <= 9; i++)
        {
            count[i][0] = 0;
            count[i][1] = 1;
        }

        // Bottom up - Get number count of length 2, 3, 4, ... , n 
        for (k = 2; k <= n; k++)
        {
            for (i = 0; i < 4; i++)  // Loop on keypad row 
            {
                for (j = 0; j < 3; j++)   // Loop on keypad column 
                {
                    // Process for 0 to 9 digits 
                    if (keypad[i][j] != '*' && keypad[i][j] != '#')
                    {
                        // Here we are counting the numbers starting with 
                        // digit keypad[i][j] and of length k keypad[i][j] 
                        // will become 1st digit, and we need to look for 
                        // (k-1) more digits 
                        num = keypad[i][j] - '0';
                        count[num][k] = 0;

                        // move left, up, right, down from current location 
                        // and if new location is valid, then get number 
                        // count of length (k-1) from that new digit and 
                        // add in count we found so far 
                        for (move = 0; move < 5; move++)
                        {
                            ro = i + row[move];
                            co = j + col[move];
                            // condition are very imp.
                            if (ro >= 0 && ro <= 3 && co >= 0 && co <= 2 &&
                                keypad[ro][co] != '*' && keypad[ro][co] != '#')
                            {
                                nextNum = keypad[ro][co] - '0';
                                count[num][k] += count[nextNum][k - 1];
                            }
                        }
                    }
                }
            }
        }

        // Get count of all possible numbers of length "n" starting 
        // with digit 0, 1, 2, ..., 9 
        totalCount = 0;
        for (i = 0; i <= 9; i++)
            totalCount += count[i][n];
        return totalCount;
    }

public:
    long long getCount(int N)
    {
        char keypad[4][3] = { {'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'} };

        return getCountUtil(keypad, N);
    }


};

// ----------------------------------------------------------------------------------------------------------------------- //