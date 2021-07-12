/*
    link: https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

    sol: https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/

    video: https://youtu.be/75yC1vbS8S8?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

    djikstra's algo doesn't work for the negative edges
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N-1) * O(E)
    SC: O(N)
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

int main() {
    int N, m;
    cin >> N >> m;
    vector<node> edges;
    for (int i = 0;i < m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;


    int inf = 10000000;
    vector<int> dist(N, inf);

    dist[src] = 0;

    for (int i = 1;i <= N - 1;i++) {
        for (auto it : edges) {
            if (dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    // if still reduces means graph is having negative cycle
    int fl = 0;
    for (auto it : edges) {
        if (dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle";
            fl = 1;
            break;
        }
    }

    // if it doesn't have neg. cycle print the shortest path
    if (!fl) {
        for (int i = 0;i < N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }

    return 0;
}

/*
6 7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3
0
*/





// ----------------------------------------------------------------------------------------------------------------------- //
// [accepted]
int isNegativeWeightCycle(int n, vector<vector<int>>edges) {
    int inf = 1e7;
    vector<int> dist(n, inf);

    for (int i = 0; i < n - 1; i++) {
        for (vector<int> j : edges) {
            if (dist[j[0]] + j[2] < dist[j[1]]) {
                dist[j[1]] = dist[j[0]] + j[2];
            }
        }
    }

    for (vector<int> j : edges) {
        if (dist[j[0]] + j[2] < dist[j[1]]) {
            return 1;
        }
    }
    return 0;
}