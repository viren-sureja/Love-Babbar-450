/*
    link: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, q, k;
        cin >> n >> q;
        vector<pair<ll, ll>> v;
        for (int i = 0;i < n;i++) {
            ll a, b;
            cin >> a >> b;
            v.push_back({ a, b });
        }

        sort(v.begin(), v.end());

        int idx = 0;
        for (int i = 1;i < v.size();i++) {
            if (v[idx].second >= v[i].first) {
                v[idx].second = max(v[idx].second, v[i].second);
            }
            else {
                idx++;
                v[idx] = v[i];
            }
        }

        while (q--)
        {

            cin >> k;
            ll ans = -1;

            for (int i = 0;i <= idx;i++) {
                if ((k - 1 + v[i].first) <= v[i].second) {
                    ans = v[i].first + k - 1;
                    break;
                }
                else {
                    k = k - (v[i].second - v[i].first + 1);
                }
            }
            cout << ans << "\n";
        }
    }
}