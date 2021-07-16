/*
    link: https://www.spoj.com/problems/AGGRCOW/

    video: https://youtu.be/Zwp6M5sl36Q
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;


bool check(vector<ll>& arr, ll n, ll diff, ll cows) {
    /*
        diff: is the diff we require between the cow's stall
        cows: is the total no. of cows to be accomodate
        current_cows: means how many cows got accomodated for given diff
    */
    ll prev = arr[0];
    ll curr_cows = 1;

    for (int i = 1;i < n;i++) {

        // if previous stall and current stall value has desired difference
        if (arr[i] - prev >= diff) {
            // increase the current accomodated cows
            curr_cows++;

            // set current variable as prev.
            prev = arr[i];
        }
        // all cows are at stall 
        if (cows == curr_cows) break;
    }

    // return if all the cows got accomodated or not.
    return curr_cows == cows;
}

void solve() {
    int stalls_cnt, cows;
    cin >> stalls_cnt >> cows;

    vector<ll> stalls(stalls_cnt);
    for (int i = 0;i < stalls_cnt;i++) {
        cin >> stalls[i];
    }

    // sort the stalls 
    sort(stalls.begin(), stalls.end());

    // if stalls_cnt is 2 then directly diff between last and the first stall.
    if (stalls_cnt == 2) {
        cout << stalls[stalls_cnt - 1] - stalls[0] << endl;
    }
    else {
        // low = 1 as one cow is already present on 0th pos.
        ll low = 1, high = 1e9;
        ll ans = 0;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            // check function will tell us whether all cow got accomodated at all stalls
            if (check(stalls, stalls_cnt, mid, cows)) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}