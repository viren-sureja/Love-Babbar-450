/*
    link: https://www.spoj.com/problems/PRATA/

    video: https://youtu.be/-Nx1h54KzUQ
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
using namespace std;

bool util(int* a, int n, int reqP, int mid) {
    int cnt = 0;

    for (int i = 0;i < n;i++) {
        int time = a[i];
        int j = 2;

        while (time <= mid) {
            cnt++;
            time += (a[i] * j);
            j++;
        }
        if (cnt >= reqP) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int parathas;
        cin >> parathas;

        int n;
        cin >> n;
        int a[n];
        for (int i = 0;i < n;i++) cin >> a[i];

        int lb = 0;
        int ub = 1e8;
        int ans = 0;

        while (lb <= ub) {
            int mid = (lb + ub) / 2;

            if (util(a, n, parathas, mid)) {
                ans = mid;
                ub = mid - 1;
            }
            else lb = mid + 1;
        }

        cout << ans << endl;
    }
}