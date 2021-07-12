/*
    link: https://www.geeksforgeeks.org/minimum-edges-reverse-make-path-source-destination/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// C++ Program to find minimum edge reversal to get
// atleast one path from source to destination
#include
using namespace std;
# define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair >* adj;

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // returns shortest path from s
    vector shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair >[V];
}

// method adds a directed edge from u to v with weight w
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

// Prints shortest paths from src to all other vertices
vector Graph::shortestPath(int src)
{
    // Create a set to store vertices that are being
    // prerocessed
    set< pair > setds;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector dist(V, INF);

    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;

    /* Looping till all shortest distance are finalized
    then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            // If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /* If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here. */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

/* method adds reverse edge of each original edge
in the graph. It gives reverse edge a weight = 1
and all original edges a weight of 0. Now, the
length of the shortest path will give us the answer.
If shortest path is p: it means we used p reverse
edges in the shortest path. */
Graph modelGraphWithEdgeWeight(int edge[][2], int E, int V)
{
    Graph g(V);
    for (int i = 0; i < E; i++)
    {
        // original edge : weight 0
        g.addEdge(edge[i][0], edge[i][1], 0);

        // reverse edge : weight 1
        g.addEdge(edge[i][1], edge[i][0], 1);
    }
    return g;
}

// Method returns minimum number of edges to be
// reversed to reach from src to dest
int getMinEdgeReversal(int edge[][2], int E, int V,
    int src, int dest)
{
    // get modified graph with edge weight
    Graph g = modelGraphWithEdgeWeight(edge, E, V);

    // get shortes path vector
    vector dist = g.shortestPath(src);

    // If distance of destination is still INF,
    // not possible
    if (dist[dest] == INF)
        return -1;
    else
        return dist[dest];
}

// Driver code to test above method
int main()
{
    int V = 7;
    int edge[][2] = { {0, 1}, {2, 1}, {2, 3}, {5, 1},
                    {4, 5}, {6, 4}, {6, 3} };
    int E = sizeof(edge) / sizeof(edge[0]);

    int minEdgeToReverse =
        getMinEdgeReversal(edge, E, V, 0, 6);
    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not possible" << endl;
    return 0;
}
