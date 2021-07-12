/*
    link: https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
    logic: read intro in link

    video: https://youtu.be/jdTnoCBSOVM
*/



// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;


vector<int> order;

void topo(int src, vector<int>& vis, vector<vector<pair<int, int> > > g) {
    vis[src] = 1;
    for (auto x : g[src]) {
        if (!vis[x.first])
            topo(x.first, vis, g);
    }
    order.push_back(src);
}


int32_t main() {

    int v, e;
    cin >> v >> e;

    int src;
    cin >> src;

    vector<vector<pair<int, int> > > g(v);
    for (int i = 0;i < e;i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({ y,w });
    }

    vector<int> vis(v, 0);
    for (int i = 0;i < v;i++) {
        if (!vis[i]) {
            topo(i, vis, g);
        }
    }
    vector<int> dist(v);
    for (int i = 0;i < v;i++) dist[i] = INT_MIN;
    dist[src] = 0;
    for (int i = v - 1;i >= 0;i--) {
        if (dist[order[i]] != INT_MIN) {
            for (auto x : g[order[i]]) {
                int v = dist[x.first];
                int w = x.second;
                int u = dist[order[i]];
                if (u + w > v)
                    dist[x.first] = u + w;
            }
        }
    }
    for (int i = 0;i < v;i++) {
        if (i != src and dist[i] != INT_MIN) {
            cout << src << " -> " << i << " = " << dist[i] << endl;
        }
    }

    return 0;

}
