/*
    sol: https://www.geeksforgeeks.org/bridge-in-a-graph/

    An edge in an undirected connected graph is a bridge iff removing it disconnects the graph.
    For a disconnected undirected graph, definition is similar, a bridge is an edge removing
    which increases number of disconnected components.
    Like Articulation Points, bridges represent vulnerabilities in a connected network and
    are useful for designing reliable networks. For example, in a wired computer network, an
    articulation point indicates the critical computers and a bridge indicates the critical
    wires or connections.

    video: https://youtu.be/2rjZH0-2lhk?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N + E)
    SC: O(N) + O(N)
*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, int& timer, vector<int> adj[]) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : adj[node]) {
        if (it == parent) continue;

        if (!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj);
            low[node] = min(low[node], low[it]);

            // low [it] > tin[node] means adjacent's low is so higher than current's tin means 
            // to reach adjacent node it's through only current node.
            // hence it's bridge
            if (low[it] > tin[node]) {
                cout << node << " " << it << endl;
            }
        }
        // node is visited and is not parent then update the low of current node to tin of adjacent
        else {
            low[node] = min(low[node], tin[it]);
        }
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
    int timer = 0;
    for (int i = 0;i < n;i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, tin, low, timer, adj);
        }
    }

    return 0;
}