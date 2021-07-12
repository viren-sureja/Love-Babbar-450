/*
    link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

    sol: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

    video: https://youtu.be/UeE67iCK2lQ?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

    travel adjacent node first
    than move to the next node

    The Time complexity of BFS is O(V + E) when Adjacency List is used
    and O(V^2) when Adjacency Matrix is used,
    where V stands for vertices and E stands for edges.

    as it will go to every vertex as well as it will check for corresponding edges
    hence TC becomes V+E
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    for connected component
*/
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<int> ans;

    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for (auto j : adj[curr]) {
            if (!vis[j]) {
                q.push(j);
                vis[j] = 1;
            }
        }
    }

    return ans;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    for disconnected component

    TC: O(N + E)  => visiting every node once
    SC: O(N + E)  => space for every node and vice-verca for both edge
*/

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<int> ans;

    for (int i = 0;i < V;i++) {
        if (!vis[i]) {
            int i = 0;
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);

                for (auto j : adj[curr]) {
                    if (!vis[j]) {
                        q.push(j);
                        vis[j] = 1;
                    }
                }
            }
        }

        return ans;
    }
}
