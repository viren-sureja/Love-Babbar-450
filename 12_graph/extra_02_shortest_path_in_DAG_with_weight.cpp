/*
    video: https://youtu.be/CrxG4WJotgg?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

    1. find topological sort
    2. make dist array
    3. mark src in dist as 0
    4. from stack made using topological sort pop 1 by 1 ele.
    5. update dist. array as dis[curr] = dis[prev] + 1

*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using BFS

    TC: O(V + E)
    SC: O(2*V)
*/
#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std;

void findTopoSort(int node, int vis[], stack<int>& st, vector<pair<int, int>> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}


void shortestPath(int src, int N, vector<pair<int, int>> adj[])
{
    int vis[N] = { 0 };
    stack<int> st;
    for (int i = 0; i < N; i++)
        if (!vis[i])
            findTopoSort(i, vis, st, adj);

    int dist[N];
    for (int i = 0; i < N; i++)
        dist[i] = 1e9;

    // crucial step
    dist[src] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dist[node] != INF) {
            for (auto it : adj[node]) {
                // prev cost + curr node's weight < curr cost
                if (dist[node] + it.second < dist[it.first]) {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        (dist[i] == 1e9) ? cout << "INF " : cout << dist[i] << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0;i < m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({ v, wt });
    }

    shortestPath(0, n, adj);

    return 0;
}