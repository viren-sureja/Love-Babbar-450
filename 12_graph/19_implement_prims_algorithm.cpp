/*
    link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

    sol: https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

    video: https://youtu.be/HnD676J56ak?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
    video (implementation): https://youtu.be/oNTsS8lGDHw?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

    steps:
    1. form 3 array: key, mst, parent
    2. mark source's node in key as 0.
    3. pick node which is not part of mst and has min. value in key
    4. mark it as part of mst
    5. now iterate to their edges and find min. weight as well as it is not part of mst
    6. if such edge found mark its parent node (don't change the mst status)
    7. update the key's value as it will be min. compare to INT_MAX
    8. repeat from 3.
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    brute force

    TC: O( (N-1) * (N + E) ) => O(N^2)
    SC: O(N) + O(N) + O(N) => O(N) , for parent, key, mstSet
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, m;
    cin >> N >> m;
    vector<pair<int, int> > adj[N];

    int a, b, wt;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    int parent[N];

    int key[N];

    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;


    key[0] = 0;
    parent[0] = -1;
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    {

        int mini = INT_MAX, u;

        for (int v = 0; v < N; v++)
            if (mstSet[v] == false && key[v] < mini)
                mini = key[v], u = v;

        // making u the part of mst
        mstSet[u] = true;

        // checking all the edges of u
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
                parent[v] = u, key[v] = weight;
        }
    }


    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \n";
    return 0;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    efficient solution
    using priority_queue

    TC: O( (N + E) * logN) => O(N * logN)
    SC: O(N) + O(N) + O(N)
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, m;
    cin >> N >> m;
    vector<pair<int, int> > adj[N];

    int a, b, wt;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    int parent[N];

    int key[N];

    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({ 0, 0 });
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({ key[v], v });
            }
        }
    }

    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \n";
    return 0;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Accepted
*/
int spanningTree(int V, vector<vector<int>> adj[])
{
    int parent[V];
    bool mstSet[V];
    int key[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({ 0, 0 });

    int ans = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (vector<int> p : adj[u]) {
            int v = p[0];
            int weight = p[1];

            if (mstSet[v] == false && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({ weight, v });
            }
        }
    }

    for (int i = 0;i < V;i++) {
        if (key[i] != INT_MAX) ans += key[i];
    }

    return ans;
}