/*
    link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

    hint: use shortest path algo
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    DFS
*/
void dfs(int s, int d, int k, int cost, vector<int>& visited, int& ans, unordered_map<int, vector<pair<int, int>>>& g) {
    if (s == d) { ans = cost; return; }
    if (k == 0) return;
    visited[s] = 1;
    for (const auto& x : g[s]) {
        if (visited[x.first] == 0) {
            if (cost + x.second > ans) continue; // IMPORTANT!!! prunning 

            dfs(x.first, d, k - 1, cost + x.second, visited, ans, g);

        }
    }
    visited[s] = 0;
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int K) {
    unordered_map<int, vector<pair<int, int>>> g;
    for (const auto& e : flights)
        g[e[0]].emplace_back(e[1], e[2]);
    int ans = INT_MAX;
    vector<int> visited(n, 0);
    dfs(s, d, K + 1, 0, visited, ans, g);
    return ans == INT_MAX ? -1 : ans;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using BFS
*/
int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int K) {
    unordered_map<int, vector<pair<int, int>>> g;
    for (const auto& e : flights)
        g[e[0]].emplace_back(e[1], e[2]);
    int ans = INT_MAX;
    queue<pair<int, int>> q;
    q.push({ s,0 });
    int steps = 0;
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            auto curr = q.front();q.pop();
            if (curr.first == d) ans = min(ans, curr.second);
            for (auto x : g[curr.first]) {
                if (curr.second + x.second > ans) continue;
                q.push({ x.first,curr.second + x.second });
            }
        }
        if (steps++ > K) break;
    }

    return ans == INT_MAX ? -1 : ans;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using bellman ford
*/
class Solution {
public:
    //bellman ford.
    //just run it k+1 iterations.
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {

        vector<int> c(n, 1e8);
        c[src] = 0;

        for (int z = 0; z <= k; z++) {
            vector<int> C(c);
            for (auto e : a)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[sink] == 1e8 ? -1 : c[sink];
    }
};






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using priority_queue, BFS
*/
class node {
public:
    int u;
    int v;
    int stop;
    node(int u1, int v1, int k)
    {
        u = u1;
        v = v1;
        stop = k;
    }
};

class Solution {
public:

    struct compare {
        bool operator()(node& n1, node& n2)
        {
            return n1.v > n2.v;
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int, int>> graph[n];

        for (int i = 0;i < flights.size();i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            graph[u].push_back(make_pair(v, w));
        }

        int dist[n];

        for (int i = 0;i < n;i++) dist[i] = INT_MAX;

        dist[src] = 0;

        priority_queue<node, vector<node>, compare> pq;

        pq.push(node(src, 0, 0));

        while (!pq.empty())
        {
            node n1 = pq.top();
            pq.pop();

            if (n1.u == dst) return n1.v;


            if (n1.stop > k) continue;

            if (dist[n1.u] != INT_MAX && dist[n1.u] < n1.stop) continue;

            dist[n1.u] = n1.stop;

            for (int i = 0;i < graph[n1.u].size();i++)
            {
                pq.push(node(graph[n1.u][i].first, n1.v + graph[n1.u][i].second, n1.stop + 1));
            }
        }
        return -1;
    }
};