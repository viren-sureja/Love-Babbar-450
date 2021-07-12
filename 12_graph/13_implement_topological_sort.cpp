/*
    what is topological sorting ?
    (DFS) https://www.geeksforgeeks.org/topological-sorting/
    (BFS) https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

    topological sort is not for cyclic graph (as it won't be possible)
    so it is always for **directed** **acyclic** graph
    hence ""DAG""

    Topological sorting for Directed Acyclic Graph (DAG) is a linear
    ordering of vertices such that for every directed edge u v,
    vertex u comes before v in the ordering. Topological Sorting for a
    graph is not possible if the graph is not a DAG.

    link: https://practice.geeksforgeeks.org/problems/topological-sort/1

    video (DFS): https://youtu.be/Yh6EFazXipA?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
    video (BFS): https://youtu.be/rZv_jHZva34?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    DFS
    TC: O(V + E)
    SC: O(V) + O(V)   => 1st -> visited array and 2nd -> stack
    ASC (auxiliary): O(V)

    here stack will ensure that all the directed nodes are visited and nothing's
    left so now push element into the stack

    hence stack will have ele. in topological order
*/
void dfs(int curr, stack<int>& s, vector<int>& vis, vector<int> adj[]) {
    vis[curr] = 1;

    for (auto i : adj[curr]) {
        if (!vis[i]) {
            dfs(i, s, vis, adj);
        }
    }

    s.push(curr);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> s;

    for (int i = 0;i < V;i++) {
        if (!vis[i]) {
            dfs(i, s, vis, adj);
        }
    }

    vector<int> sorted;
    while (!s.empty()) {
        sorted.push_back(s.top());
        s.pop();
    }
    return sorted;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using BFS (kahn's algorithm)
    here we will require inDeg vector as we won't have recursive calls
    so to check every time which vertex has how many indegree

    TC: O(V + E)
    SC: O(V) + O(V)  -> 1st for inDeg, 2nd for queue
*/
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> inDeg(V, 0);

    // store indegrees of all
    for (int i = 0; i < V; i++) {
        for (auto k : adj[i]) {
            inDeg[k]++;
        }
    }

    queue<int> q;

    // get all the node with indegree=0, 
    // if there is no node with indegree=0, means it has cycle
    // if there is cycle then topological sort doesn't exist
    for (int i = 0;i < V;i++) {
        if (inDeg[i] == 0) q.push(i);
    }

    vector<int> topoSorted;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        topoSorted.push_back(curr);

        for (auto i : adj[curr]) {
            inDeg[i]--;
            // if i ele. became 
            if (inDeg[i] == 0) q.push(i);
        }
    }

    return topoSorted;
}
