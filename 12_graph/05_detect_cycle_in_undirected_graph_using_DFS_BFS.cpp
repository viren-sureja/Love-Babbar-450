/*
    link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

    sol: https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
    sol (using bfs): https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/

    video (using BFS): https://youtu.be/A8ko93TyOns?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
    video (using DFS): https://youtu.be/Y9NFqI6Pzd4?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
*/

// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using BFS

    TC: O(V + E)
    SC: O(V + E)
*/
bool checkCycle(int curr, vector<int>& vis, vector<int> adj[]) {
    vis[curr] = 1;

    queue<pair<int, int>> q;
    q.push({ curr, -1 });

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (auto i : adj[p.first]) {
            if (!vis[i]) {
                vis[i] = 1;
                q.push({ i, p.first });
            }
            else if (i != p.second) return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int>adj[])
{
    vector<int> vis(V, 0);

    for (int i = 0;i < V;i++) {
        if (!vis[i]) {
            if (checkCycle(i, vis, adj)) return true;
        }
    }
    return false;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using DFS

    TC: O(N + E)    // N or V both are same (vertices)
    SC: O(N + E)
*/
bool checkCycle(int curr, int prev, vector<int>& vis, vector<int> adj[]) {
    vis[curr] = 1;

    for (auto i : adj[curr]) {
        if (!vis[i]) {
            /*
                hence here dont write  "return checkCycle().." as if false we will check for other nodes
                as well
            */
            if (checkCycle(i, curr, vis, adj)) return true;
        }
        // i is visited as well as it is not parent means it is cycle
        else if (i != prev) return true;
    }
    return false;
}
bool isCycle(int V, vector<int>adj[])
{
    vector<int> vis(V, 0);

    for (int i = 0;i < V;i++) {
        if (!vis[i]) {
            if (checkCycle(i, -1, vis, adj)) return true;
        }
    }
    return false;
}