/*
    link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#

    sol (just refer): https://www.geeksforgeeks.org/strongly-connected-components/

    video: https://youtu.be/V8qIqJxCioo?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(V) + O(V + E) + O(V + E), 1st for toposort, 2nd for transpose, 3rd for DFS acc. to finishing line
    SC: O(V + E) + O(V) + O(V), 1st for storing transpose, 2nd for vis, 3rd for stack
*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int>& st, vector<int>& vis, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}

void revDfs(int node, vector<int>& vis, vector<int> transpose[]) {
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node]) {
        if (!vis[it]) {
            revDfs(it, vis, transpose);
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
    }

    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0;i < n;i++) {
        if (!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }

    vector<int> transpose[n];

    for (int i = 0;i < n;i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            transpose[it].push_back(i);
        }
    }



    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }


    return 0;
}

/*
5 5
0 1
1 2
2 0
1 3
3 4
*/








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    [accepted]
*/
void dfs(int curr, stack<int>& st, vector<int>& vis, vector<int> adj[]) {
    vis[curr] = 1;
    for (auto i : adj[curr]) {
        if (!vis[i]) dfs(i, st, vis, adj);
    }
    st.push(curr);
}

void revDfs(int curr, vector<int>& vis, vector<int> transpose[]) {
    vis[curr] = 1;
    for (auto it : transpose[curr]) {
        if (!vis[it]) revDfs(it, vis, transpose);
    }
}


int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }

    vector<int> transpose[V];

    for (int i = 0; i < V; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            transpose[it].push_back(i);
        }
    }

    int cnt = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            cnt++;
            revDfs(node, vis, transpose);
        }
    }

    return cnt;
}