/*
    link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

    sol: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

    video: https://youtu.be/uDWljP2PGmU?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    [Accepted]

    TC: O(V + E)
    SC: O(V + E)
*/
void dfs(int curr, vector<int> adj[], vector<int>& vis, vector<int>& ans) {
    ans.push_back(curr);
    vis[curr] = 1;

    for (auto i : adj[curr]) {
        if (!vis[i]) dfs(i, adj, vis, ans);
    }
}

vector<int>dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> ans;

    for (int i = 0;i < V;i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, ans);
        }
    }
    return ans;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    for connected component

    TC: O(V + E)
    SC: O(V + E)
*/

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    cout << "Following is Depth First Traversal"
        " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    for disconnected component

    TC: O(V + E)
    SC: O(V + E)
*/
class Graph {

    // A function used by DFS
    void DFSUtil(int v);

public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints DFS traversal of the complete graph
    void DFS();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i);
}

// The function to do DFS traversal. It uses recursive
// DFSUtil()
void Graph::DFS()
{
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (auto i : adj)
        if (visited[i.first] == false)
            DFSUtil(i.first);
}

// Driver Code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    cout << "Following is Depth First Traversal \n";
    g.DFS();

    return 0;
}
