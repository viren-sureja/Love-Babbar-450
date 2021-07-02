/*
    ref: 9_reorganize_strings.cpp
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();

        int cnt[26] = { 0 };

        // get count of every char
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }

        int mx = 0;
        for (int i = 0; i < 26; i++) {
            mx = max(mx, cnt[i]);
        }

        if (mx <= (n + 1) / 2) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}
