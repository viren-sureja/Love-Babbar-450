/*
    link: https://www.geeksforgeeks.org/two-clique-problem-check-graph-can-divided-two-cliques/

    video: https://youtu.be/cA8-mdRJuCI
    why to complement and use bipartite? see [3:42] image in above video to understand

    complement: means every node will now be connected to other clique
    bipartite: now to make sure that it is possible to color

    hence we can divide the graph in 2 clique
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// Time complexity of above implementation is O(V^2)

// C++ program to find out whether a given graph can be
// converted to two Cliques or not.
#include <bits/stdc++.h>
using namespace std;

const int V = 5;

// This function returns true if subgraph reachable from
// src is Bipartite or not.
bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue
    // source vertex for BFS traversal
    queue <int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue
        int u = q.front();
        q.pop();

        // Find all non-colored adjacent vertices
        for (int v = 0; v < V; ++v)
        {
            // An edge from u to v exists and destination
            // v is not colored
            if (G[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent
                // v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            // An edge from u to v exists and destination
            // v is colored with same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can
    // be colored with alternate color
    return true;
}

// Returns true if a Graph G[][] is Bipartite or not. Note
// that G may not be connected.
bool isBipartite(int G[][V])
{
    // Create a color array to store colors assigned
    // to all veritces. Vertex number is used as index in
    // this array. The value '-1' of colorArr[i]
    // is used to indicate that no color is assigned to
    // vertex 'i'. The value 1 is used to indicate first
    // color is assigned and value 0 indicates
    // second color is assigned.
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    // One by one check all not yet colored vertices.
    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (isBipartiteUtil(G, i, colorArr) == false)
                return false;

    return true;
}

// Returns true if G can be divided into
// two Cliques, else false.
bool canBeDividedinTwoCliques(int G[][V])
{
    // Find complement of G[][]
    // All values are complemented except
    // diagonal ones
    int GC[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            GC[i][j] = (i != j) ? !G[i][j] : 0;

    // Return true if complement is Bipartite
    // else false.
    return isBipartite(GC);
}

// Driver program to test above function
int main()
{
    int G[][V] = { {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };

    canBeDividedinTwoCliques(G) ? cout << "Yes" :
        cout << "No";
    return 0;
}
