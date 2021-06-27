/*
    link: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

    sol: https://www.geeksforgeeks.org/distance-nearest-cell-1-binary-matrix/

*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive method
    TC: O(N^2 * M^2)
    SC: O(1)
*/
void printDistance(int mat[N][M])
{
    int ans[N][M];

    // Initialize the answer matrix with INT_MAX.
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans[i][j] = INT_MAX;

    // For each cell
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            // Traversing the whole matrix
            // to find the minimum distance.
            for (int k = 0; k < N; k++)
                for (int l = 0; l < M; l++)
                {
                    // If cell contain 1, check
                    // for minimum distance.
                    if (mat[k][l] == 1)
                        ans[i][j] = min(ans[i][j],
                            abs(i - k) + abs(j - l));
                }
        }

    // Printing the answer.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using BFS
    TC: O(N*M)
    SC: O(N*M)
*/
// C++ program to find distance of nearest
// cell having 1 in a binary matrix.

#include<bits/stdc++.h>
#define MAX 250007
using namespace std;

int N;
int M;

// Making a class of graph with bfs function.
class graph
{
    private:
    vector<int> g[MAX];
    int n, m;

    public:
    graph(int a, int b)
    {
        n = a;
        m = b;
    }

    // Function to create graph with N*M nodes
    // considering each cell as a node and each
    // boundary as an edge.
    void createGraph()
    {
        int k = 1; // A number to be assigned to a cell

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // If last row, then add edge on right side.
                if (i == n)
                {
                    // If not bottom right cell.
                    if (j != m)
                    {
                        g[k].push_back(k + 1);
                        g[k + 1].push_back(k);
                    }
                }

                // If last column, then add edge toward down.
                else if (j == m)
                {
                    g[k].push_back(k + m);
                    g[k + m].push_back(k);
                }

                // Else makes an edge in all four directions.
                else
                {
                    g[k].push_back(k + 1);
                    g[k + 1].push_back(k);
                    g[k].push_back(k + m);
                    g[k + m].push_back(k);
                }

                k++;
            }
        }
    }

    // BFS function to find minimum distance
    void bfs(bool visit[], int dist[], queue<int> q)
    {
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (int i = 0; i < g[temp].size(); i++)
            {
                if (visit[g[temp][i]] != 1)
                {
                    dist[g[temp][i]] =
                        min(dist[g[temp][i]], dist[temp] + 1);

                    q.push(g[temp][i]);
                    visit[g[temp][i]] = 1;
                }
            }
        }
    }

    // Printing the solution.
    void print(int dist[])
    {
        for (int i = 1, c = 1; i <= n * m; i++, c++)
        {
            cout << dist[i] << " ";

            if (c % m == 0)
                cout << endl;
        }
    }
};

class Solution
{
    public:

// Find minimum distance
    vector<vector<int>> findMinDistance(vector<vector<int>> mat)
    {
        // Creating a graph with nodes values assigned
        // from 1 to N x M and matrix adjacent.
        graph g1(N, M);
        g1.createGraph();

        // To store minimum distance
        int dist[MAX];

        // To mark each node as visited or not in BFS
        bool visit[MAX] = { 0 };

        // Initialising the value of distance and visit.
        for (int i = 1; i <= M * N; i++)
        {
            dist[i] = INT_MAX;
            visit[i] = 0;
        }

        // Inserting nodes whose value in matrix
        // is 1 in the queue.
        int k = 1;
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (mat[i][j] == 1)
                {
                    dist[k] = 0;
                    visit[k] = 1;
                    q.push(k);
                }
                k++;
            }
        }

        // Calling for Bfs with given Queue.
        g1.bfs(visit, dist, q);

        vector<vector<int>> ans(N, vector<int>(M));
        k = 1;
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < M;j++) {
                int x = dist[k];
                ans[i][j] = x;
                k++;
            }
        }

        // Printing the solution.
        return ans;
    }

    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>>nearest(vector<vector<int>>grid)
    {
        N = grid.size();
        M = grid[0].size();
        return findMinDistance(grid);
    }