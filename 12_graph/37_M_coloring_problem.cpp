/*
    link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

    video: https://youtu.be/h9M0pQ39ha0
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    BFS
*/
#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;


void solve() {

    int v, e;
    cin >> v >> e;
    vector<vector<int> > g(v);
    for (int i = 0;i < e;i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int res[v];
    bool available[v];
    res[0] = 0;
    for (int i = 1;i < v;i++) res[i] = -1;
    for (int i = 0;i < v;i++) available[i] = false;

    int cn = 0;
    for (int i = 1;i < v;i++) {
        for (auto x : g[i]) {
            if (res[x] != -1) {
                available[res[x]] = true;
            }
        }

        int cr;
        for (cr = 0;cr < v;cr++) {
            if (available[cr] == false) {
                break;
            }
        }

        res[i] = cr;
        cn = max(cn, cr + 1);

        for (auto x : g[i]) {
            if (res[x] != -1) {
                available[res[x]] = false;
            }
        }
    }
    cout << cn << endl;
    for (int i = 0;i < v;i++) cout << res[i] << " ";

}

int32_t main() {

    solve();
    return 0;

}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    alternative code

    using BFS

    Time Complexity: O(V + E).
    Space Complexity: O(V). For Storing Visited List.
*/
// CPP program for the above approach
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{

    // A node class which stores the color and the edges
    // connected to the node
public:
    int color = 1;
    set<int> edges;
};

int canPaint(vector<node>& nodes, int n, int m)
{

    // Create a visited array of n
    // nodes, initialized to zero
    vector<int> visited(n + 1, 0);

    // maxColors used till now are 1 as
    // all nodes are painted color 1
    int maxColors = 1;

    // Do a full BFS traversal from
    // all unvisited starting points
    for (int sv = 1; sv <= n; sv++)
    {

        if (visited[sv])
            continue;

        // If the starting point is unvisited,
        // mark it visited and push it in queue
        visited[sv] = 1;
        queue<int> q;
        q.push(sv);

        // BFS Travel starts here
        while (!q.empty())
        {

            int top = q.front();
            q.pop();

            // Checking all adjacent nodes
            // to "top" edge in our queue
            for (auto it = nodes[top].edges.begin();
                it != nodes[top].edges.end(); it++)
            {

                // IMPORTANT: If the color of the
                // adjacent node is same, increase it by 1
                if (nodes[top].color == nodes[*it].color)
                    nodes[*it].color += 1;

                // If number of colors used shoots m, return
                // 0
                maxColors
                    = max(maxColors, max(nodes[top].color,
                        nodes[*it].color));
                if (maxColors > m)
                    return 0;

                // If the adjacent node is not visited,
                // mark it visited and push it in queue
                if (!visited[*it]) {
                    visited[*it] = 1;
                    q.push(*it);
                }
            }
        }
    }

    return 1;
}

// Driver code
int main()
{

    int n = 4;
    bool graph[n][n] = {
    { 0, 1, 1, 1 },
    { 1, 0, 1, 0 },
    { 1, 1, 0, 1 },
    { 1, 0, 1, 0 } };
    int m = 3; // Number of colors


    // Create a vector of n+1
    // nodes of type "node"
    // The zeroth position is just
    // dummy (1 to n to be used)
    vector<node> nodes(n + 1);

    // Add edges to each node as per given input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (graph[i][j])
            {
                // Connect the undirected graph
                nodes[i].edges.insert(i);
                nodes[j].edges.insert(j);
            }
        }
    }

        // Display final answer
    cout << canPaint(nodes, n, m);
    cout << "\n";

    return 0;
}
