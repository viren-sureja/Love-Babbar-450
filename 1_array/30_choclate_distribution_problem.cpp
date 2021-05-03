/*
    link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
long long findMinDiff(vector<long long> a, long long n, long long m) {
    // sorted so that we can different window(sub-array) of size m.
    sort(a.begin(), a.end());

    long long ans = a[m - 1] - a[0];    // took first window from 0 to m-1.

    // now we iterate every window(sub-array) and check for the max-min from that range.
    for (int i = 1;i < n - m + 1;i++) {
        ans = min(a[i + m - 1] - a[i], ans);
    }
    return ans;
}