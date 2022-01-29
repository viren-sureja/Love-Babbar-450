/*
    sol: https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

    video: https://youtu.be/1KRmCzBl_mQ?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
*/

// ----------------------------------------------------------------------------------------------------------------------- //
/*
    E is the edges

    TC: O(E logE) + O(E * (4*alpha))    => 1st for sorting, 2nd for checking whether it belong to same component or not
    SC: O(E) + O(V) + O(V)  => 1st for sorted array, 2nd for parent, 3rd for rank
*/
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt;
}

int findPar(int u, vector<int>& parent) {
    if (u == parent[u]) return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int N, m;
    cin >> N >> m;
    vector<node> edges;
    for (int i = 0;i < m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for (int i = 0;i < N;i++)
        parent[i] = i;
    vector<int> rank(N, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges) {
        if (findPar(it.v, parent) != findPar(it.u, parent)) {
            cost += it.wt;
            mst.push_back({ it.u, it.v });
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << cost << endl;
    for (auto it : mst) cout << it.first << " - " << it.second << endl;
    return 0;
}
