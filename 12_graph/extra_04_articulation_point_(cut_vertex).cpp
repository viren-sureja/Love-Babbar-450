/*
    sol: https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

    video: https://youtu.be/3t3JHswP7mw?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

    ref: 26/find bridge in graph .cpp


    use hashSet as articulation point can come multiple time
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(V + E)
    SC: O(V) + O(V) + O(V) + O(V), for vis, tin, low, isArti...
*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, int& timer, vector<int> adj[], vector<int>& isArticulation) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    for (auto it : adj[node]) {
        if (it == parent) continue;

        if (!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation);
            low[node] = min(low[node], low[it]);

            // from here we can know that this node has multiple child and are not connected
            // bcoz if they would have they have already been visited
            child++;
            if (low[it] >= tin[node] && parent != -1) {
                isArticulation[node] = 1;
            }
        }
        else {
            // if the node is visited means it cannot be articulation point
            // hence so improve the low[node] if the adjacent's insertion time is lesser
            low[node] = min(low[node], tin[it]);
        }
    }

    if (parent == -1 && child > 1) {
        isArticulation[node] = 1;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> vis(n, 0);
    vector<int> isArticulation(n, 0);
    int timer = 0;
    for (int i = 0;i < n;i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
        }
    }

    for (int i = 0;i < n;i++) {
        if (isArticulation[i] == 1) cout << i << endl;
    }

    return 0;
}