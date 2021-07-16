/*
    link: https://www.spoj.com/problems/EKO/

    video: https://youtu.be/tkoucfh10SI
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using binary search

    TC: O(n logn)
    SC: O(1)
*/

// return amount of wood will be cutted for the given height of machine
ll total_wood(vector<long long>& h, int n, int machine_height) {
    ll wood = 0;
    for (int i = 0;i < n;i++) {
        if (h[i] > machine_height) wood += h[i] - machine_height;
    }
    return wood;
}

void solve() {
    long long n, m;
    cin >> n >> m;

    vector<long long> h(n), res(n);

    ll mx = LONG_LONG_MIN;
    for (int i = 0;i < n;i++) {
        cin >> h[i];
        mx = max(h[i], mx);
    }

    // we will implement binary_search for 0 height to max height
    ll l = 0, r = mx;
    ll ans = 0;
    while (l <= r) {
        // we will find mid and will get wood cutted
        ll mid = l + (r - l) / 2;

        debug(mid);
        ll wood = total_wood(h, n, mid);

        // if wood cutted is of exact amount then ans = mid;
        if (wood == m) {
            ans = mid;
            break;
        }
        // if wood cutted is less then we will decrease the height of the machine.
        else if (wood < m) {
            r = mid - 1;
        }
        // if wood cutted is more than enough then we will store ans as well as increase height of machine.
        else {
            ans = max(ans, mid);
            l = mid + 1;
        }
    }
    cout << ans << endl;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using sorting

    TC: O(N logN)
    SC: O(N)
*/
void solve() {
    long long n, m;
    cin >> n >> m;

    vector<long long> h(n), res(n);
    for (int i = 0;i < n;i++) cin >> h[i];

    // sort the height
    sort(h.begin(), h.end());

    // cutting at the height of max is 0.
    res[n - 1] = 0;
    int high = n - 1;
    for (int i = high - 1;i >= 0;i--) {
        // this mathematical equation will store the wood will be cutted at curr. height
        res[i] = (high - i) * (h[i + 1] - h[i]) + res[i + 1];
    }

    int r = high;
    // traverse till the total wood is less than required
    while (r >= 0 && res[r] < m) r--;

    if (res[r] == m) cout << h[r] << endl;
    else {
        // here wood will be more than enough hence increase the height and decrease the wood.
        long long ans = h[r] + (res[r] - m) / (high - r);
        cout << ans << endl;
    }
}
