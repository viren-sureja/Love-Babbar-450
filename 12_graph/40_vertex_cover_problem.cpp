/*
    link: https://www.geeksforgeeks.org/vertex-cover-problem-set-1-introduction-approximate-algorithm-2/

    Given an undirected graph, the vertex cover problem is to find minimum size vertex cover
    means min. no. of vertices which cover every edges

    note from GFG: We will soon be discussing exact algorithms for vertex cover.

    as this code doesn't give exact minimal solution
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(V + E)

    this code is just for ref. (it's not exact code)
*/
// Program to print Vertex Cover of a given undirected graph
#include<iostream>
#include <list>
using namespace std;

// This class represents a undirected graph using adjacency list
class Graph
{
    int V; // No. of vertices
    list<int>* adj; // Pointer to an array containing adjacency lists
public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void printVertexCover(); // prints vertex cover
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Since the graph is undirected
}

// The function to print vertex cover
void Graph::printVertexCover()
{
    // Initialize all vertices as not visited.
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int>::iterator i;

    // Consider all edges one by one
    for (int u = 0; u < V; u++)
    {
        // An edge is only picked when both visited[u] and visited[v]
        // are false
        if (visited[u] == false)
        {
            // Go through all adjacents of u and pick the first not
            // yet visited vertex (We are basically picking an edge
            // (u, v) from remaining edges.
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
                    // Add the vertices (u, v) to the result set.
                    // We make the vertex u and v visited so that
                    // all edges from/to them would be ignored
                    visited[v] = true;
                    visited[u] = true;
                    break;
                }
            }
        }
    }

    // Print the vertex cover
    for (int i = 0; i < V; i++)
        if (visited[i])
            cout << i << " ";
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printVertexCover();

    return 0;
}
