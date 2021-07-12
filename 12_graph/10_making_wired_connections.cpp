/*
    link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

    just count the disconnected graph
*/


// ----------------------------------------------------------------------------------------------------------------------- //
void dfs(int curr, vector<int> v[], vector<int>& vis) {
    vis[curr] = 1;

    for (auto i : v[curr]) {
        if (!vis[i]) {
            dfs(i, v, vis);
        }
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {
    // if cables(edges) is less than vertex-1 means all computer(vertex) won't connect
    if (connections.size() < n - 1) return -1;

    vector<int> vis(n, 0);

    vector<int> v[n];

    for (int i = 0;i < connections.size();i++) {
        v[connections[i][0]].push_back(connections[i][1]);
        v[connections[i][1]].push_back(connections[i][0]);
    }

    int disconnected = 0;

    for (int i = 0;i < n;i++) {
        if (!vis[i]) {
            disconnected++;
            dfs(i, v, vis);
        }
    }

    // dis -1 as initial network wont count 
    // the one out of which we will provide cable
    return disconnected - 1;
}