/*
    link: https://www.spoj.com/problems/SUBSUMS/

    video: https://youtu.be/VCZ4lqfZRPk
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(2^(n/2))
*/
#include<bits/stdc++.h>
using namespace std;

void solve(long long* a, vector<long long>& v, long long start, long long end) {
    long long n = end - start + 1;

    for (long long i = 0;i < (1 << n);i++) {
        long long x = i;
        long long j = start;
        long long sum = 0;
        while (x) {
            long long bit = x & 1;
            if (bit) sum += a[j];
            j++;
            x = x >> 1;
        }
        v.push_back(sum);
    }
}

int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    long long arr[n];
    for (long long i = 0;i < n;i++) cin >> arr[i];

    long long count = 0;

    vector<long long> v1, v2;
    solve(arr, v1, 0, n / 2 - 1);
    solve(arr, v2, n / 2, n - 1);

    sort(v2.begin(), v2.end());

    for (long long i = 0;i < v1.size();i++) {
        long long low = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin();
        long long high = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin();
        count += high - low;
    }

    cout << count;
}