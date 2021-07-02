/*
    link: https://www.geeksforgeeks.org/check-given-graph-tree/

    An undirected graph is tree if it has following properties.
    1) There is no cycle.
    2) The graph is connected.
    For an undirected graph we can either use BFS or DFS to detect above two properties.
    How to detect cycle in an undirected graph?
    We can either use BFS or DFS. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, then there is a cycle in graph. If we don’t find such an adjacent for any vertex, we say that there is no cycle (See Detect cycle in an undirected graph for more details).
    How to check for connectivity?
    Since the graph is undirected, we can start BFS or DFS from any vertex and check if all vertices are reachable or not. If all vertices are reachable, then graph is connected, otherwise not.


    video: https://youtu.be/9hWUJZuvvMw
*/



// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
using namespace std;

#define MAX

vector<int> g[MAX];
int vis[MAX] = { 0 };

bool isCycle(int u, int parent) {
    // marking current node visited
    vis[u] = true;

    // for all other connected node
    for (auto connectedNodes : g[u]) {

        // if connected node is not visited
        if (!vis[connectedNodes]) {
            if (isCycle(connectedNodes, u)) return true;
        }
        // if connected node is visited and is not parent than cycle exist
        else if (connectedNodes != parent) return true;
    }
    return false;
}

void markConnected(int u) {
    // marking current node visited
    vis[u] = true;
    for (auto connectedNodes : g[u]) {
        // marking those node which are reachable
        if (!vis[connectedNodes]) {
            markConnected(connectedNodes);
        }
    }
}

bool checkTree(int edges) {
    // passing first node which is root and it is having no parent so -1.
    bool x = isCycle(0, -1);

    // cycle detected
    if (x) return false;

    markConnected(0);

    for (int i = 0;i < edges;i++) {

        // node not reachable detected
        if (!vis[i]) return false;
    }

    return true;
}

int main() {
    // n is the no. of edges
    // m is the no. of nodes

    int n, m;
    cin >> n >> m;

    // set false to whole vis array
    memset(vis, 0, sizeof(vis));

    // set connected node
    for (int i = 0;i < n;i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    // check if its tree
    bool x = checkTree(m);
    if (x) cout << "it's tree" << endl;
    else cout << "it's not tree, it's graph" << endl;

    return 0;
}