/*
    Note: whenever question says pre-requisite or to complete some task before some task use topological sort

    link: https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/

    read the Approach in link
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(V + E)
    SC: O(V)
*/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

// Adjacency List to store the graph
vector<int> graph[maxN];

// Array to store the in-degree of node
int indegree[maxN];

// Array to store the time in which
// the job i can be done
int job[maxN];

// Function to add directed edge
// between two vertices
void addEdge(int u, int v)
{
    // Insert edge from u to v
    graph[u].push_back(v);

    // Increasing the indegree
    // of vertex v
    indegree[v]++;
}

// Function to find the minimum time
// needed by each node to get the task
void printOrder(int n, int m)
{
    // Find the topo sort order
    // using the indegree approach

    // Queue to store the
    // nodes while processing
    queue<int> q;

    // Pushing all the vertex in the
    // queue whose in-degree is 0

    // Update the time of the jobs
    // who don't require any job to
    // be completed before this job
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            job[i] = 1;
        }
    }

    // Iterate until queue is empty
    while (!q.empty()) {

        // Get front element of queue
        int cur = q.front();

        // Pop the front element
        q.pop();

        for (int adj : graph[cur]) {

            // Decrease in-degree of
            // the current node
            indegree[adj]--;

            // Push its adjacent elements
            // it means all the required jobs to finish before this job are finished
            if (indegree[adj] == 0) {
                job[adj] = job[cur] + 1;
                q.push(adj);
            }
        }
    }

    // Print the time to complete
    // the job
    for (int i = 1; i <= n; i++)
        cout << job[i] << " ";
    cout << "\n";
}

// Driver Code
int main()
{
    // Given Nodes N and edges M
    int n, m;
    n = 10;
    m = 13;

    // Given Directed Edges of graph
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);

    // Function Call
    printOrder(n, m);
    return 0;
}
