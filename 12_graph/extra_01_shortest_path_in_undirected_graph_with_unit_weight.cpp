/*
    video: https://youtu.be/hwCWi7-bRfI?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw


    if we use DFS then we have to pass level+1 in recursive function
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using BFS
    TC: O(V + E)
    SC: O(V) + O(V)

    we can get shortest distance between src to any node.
*/
void BFS(vector<int> adj[], int N, int src)
{
    int dist[N];
    for (int i = 0;i < N;i++) dist[i] = INT_MAX;
    queue<int>  q;

    dist[src] = 0;
    q.push(src);

    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0;i < N;i++) cout << dist[i] << " ";

}