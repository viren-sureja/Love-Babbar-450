/*
    link: https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
int disappointed(int capacity, string s) {
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    int n = s.size();
    int occupied = 0, ans = 0;

    for (int i = 0;i < n;i++) {

        // if the customer is coming for the first time
        if (cnt[s[i] - 'A'] == 0) {
            // if computer is left to use
            if (occupied < capacity) {
                // assign the char 1
                cnt[s[i] - 'A'] = 1;
                // occupied increases as the computer users increases
                occupied++;
            }
            // all computers are occupied
            else {
                // so increase the ans (as disappointed custo. increases)
                ans++;
                /*  mark him as not able to use computer hence -1.
                    why -1?
                    to avoid count him in when it's char repeated second time indicating he is leaving
                */

                cnt[s[i] - 'A'] = -1;
            }
        }
        // customer is already using computer
        else if (cnt[s[i] - 'A'] == 1) {
            // now as it's char came again it's time to leave hence 0 as visited
            cnt[s[i] - 'A'] = 0;
            // as char is leaving the computer hence occupied decreases.
            occupied--;
        }
    }
    return ans;
}