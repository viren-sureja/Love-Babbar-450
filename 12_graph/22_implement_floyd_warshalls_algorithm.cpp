/*
    [shortest path finding algo]

    link: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

    video: https://youtu.be/nV_wOZnhbog
    => floyd warshalls can detect negative edge cycle [6:02]
    => including the adjacent node wont help as it will already given in adj. matrix [8:40]

    sol (just refer the comments in code): https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

    logic:
    if visiting via K then formula will be : d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(V^3)
    SC: O(V^2)
*/
#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices

void floyd_warshall(int graph[V][V])
{
    int dist[V][V];

    //Assign all values of graph to allPairs_SP
    for (int i = 0;i < V;++i)
        for (int j = 0;j < V;++j)
            dist[i][j] = graph[i][j];

    //Find all pairs shortest path by trying all possible paths
    for (int k = 0;k < V;++k)	//Try all intermediate nodes
        for (int i = 0;i < V;++i)	//Try for all possible starting position
            for (int j = 0;j < V;++j)	//Try for all possible ending position
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)	//SKIP if K is unreachable from i or j is unreachable from k
                    continue;
                // dist[i][j] means direct edge from i to j
                // dist[i][k] + dist[k][j] means distance via vertex k to reach j from i.
                else if (dist[i][k] + dist[k][j] < dist[i][j])		//Check if new distance is shorter via vertex K
                    dist[i][j] = dist[i][k] + dist[k][j];
            }

    //Check for negative edge weight cycle
    for (int i = 0;i < V;++i)
        if (dist[i][i] < 0)
        {
            cout << "Negative edge weight cycle is present\n";
            return;
        }

    //Print Shortest Path Graph
    //(Values printed as INT_MAX defines there is no path)
    for (int i = 1;i < V;++i)
    {
        for (int j = 0;j < V;++j)
            cout << i << " to " << j << " distance is " << dist[i][j] << "\n";
        cout << "=================================\n";
    }
}

int main()
{
    int graph[V][V] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
                        {INT_MAX, 0, 4, 2, 7, INT_MAX},
                        {INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
                        {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                        {INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
                        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };

    floyd_warshall(graph);
    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    [accepted]
*/
const int INF = 1e8;

void shortest_distance(vector<vector<int>>& matrix) {
    int V = matrix.size();

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (matrix[i][k] == INF || matrix[k][j] == INF) continue;
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF) {
                matrix[i][j] = -1;
            }
        }
    }
}