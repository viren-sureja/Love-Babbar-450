/*
    link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

    sol (using DFS): https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
    sol (using BFS): https://www.geeksforgeeks.org/detect-cycle-in-a-directed-graph-using-bfs/

    video (using DFS): https://youtu.be/uzVUw90ZFIg?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
    video (using BFS or kahn's algo): https://youtu.be/V6GxfKDyLBM?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

    here cycle means
        1. node must be visited
        2. whole cycle loop must have same direction of edges

    so previous algo. of undirected graph won't work here
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using DFS

    TC: O(N + E)    // N or V both are same (vertices)
    SC: O(N + E)
*/
bool checkCycle(int curr, vector<int>& vis, vector<int>& dfsVis, vector<int> adj[]) {
    // to record that we have visited 
    vis[curr] = 1;
    // to record that current vertex is visited and is in current movement/direction
    dfsVis[curr] = 1;
    for (auto i : adj[curr]) {
        if (!vis[i]) {
            /*
                hence here dont write  "return checkCycle().." as if false we will check for other nodes
                as well
            */
            if (checkCycle(i, vis, dfsVis, adj)) return true;
        }
        // it is cycle only if node is visited once as well as it is in current movement/direction
        else if (dfsVis[i]) return true;
    }
    // when we r recurring back reset our current movement dfsVis
    dfsVis[curr] = 0;
    return false;
}
bool isCyclic(int V, vector<int>adj[])
{
    // to record if node is visited or not (help in disconnected component)
    vector<int> vis(V, 0);

    // to record the visited node in current movement/direction
    vector<int> dfsVis(V, 0);

    for (int i = 0;i < V;i++) {
        if (!vis[i]) {
            if (checkCycle(i, vis, dfsVis, adj)) return true;
        }
    }
    return false;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    ref: 13/implement_topological_sort using BFS (kahn's algo)

    using BFS (kahn's algorithm)
    TC: O(V + E)
    SC: O(V) + O(V)  -> 1st for inDeg, 2nd for queue
*/
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> inDeg(V, 0);

    for (int i = 0; i < V; i++) {
        for (auto k : adj[i]) {
            inDeg[k]++;
        }
    }

    queue<int> q;

    for (int i = 0;i < V;i++) {
        if (inDeg[i] == 0) q.push(i);
    }

    int cnt = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cnt++;          // instead of storing we are maintaining count record

        for (auto i : adj[curr]) {
            inDeg[i]--;
            // if i ele. became 
            if (inDeg[i] == 0) q.push(i);
        }
    }

    /*
        if the count of the node arranged topologically is V then for sure it
        does n't have cycle as topological sort works for only DAG
        or if it doesn't get equal to V no. of vertices means cycle
        would have been detected somewhere
    */
    if (cnt == V) return false;
    return true;
}