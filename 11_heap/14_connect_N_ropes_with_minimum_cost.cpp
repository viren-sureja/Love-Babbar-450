/*
    link: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

    sol: https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/
    refer sol. if u want to refer heap from scratch in this problem
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N * logN)
    SC: O(N)
*/
typedef long long ll;
long long minCost(long long arr[], long long n) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    long long sum = 0;

    while (pq.size() > 1) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        sum += (a + b);

        pq.push(a + b);
    }
    return sum;
}