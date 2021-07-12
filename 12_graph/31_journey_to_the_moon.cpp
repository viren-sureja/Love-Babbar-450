/*
    link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem

    video: https://youtu.be/IM1xOjamHA8
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using dfs
    TC: O(V+E)
    SC: O()
*/
#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;

void dfile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void dfs(int src, vector<int>& vis, vector<int> g[], int& counter) {
    vis[src] = 1;
    counter++;
    for (auto x : g[src]) {
        if (!vis[x]) {
            dfs(x, vis, g, counter);
        }
    }
}

int32_t main()
{

    int v, e;
    cin >> v >> e;
    vector<int> g[v];
    for (int i = 0;i < e;i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> solution;
    vector<int> vis(v, 0);
    for (int i = 0;i < v;i++) {
        if (!vis[i]) {
            // count of astronauts in each country
            int counter = 0;
            dfs(i, vis, g, counter);
            solution.push_back(counter);
        }
    }

    /*
        whenever used  (x * x-1) /2
        it means xC2    => as we r choosing 2 out of x
    */

    // total no. of pairs
    int val = (v * (v - 1)) / 2;
    for (int i = 0;i < solution.size();i++) {
        // no. pairs in individual country
        int x = (solution[i] * (solution[i] - 1)) / 2;

        // as we want astronauts from different country
        val = val - x;
    }
    cout << val;

    return 0;
}
